// analysis.h
// 

#ifndef ANALYSIS_H
#define ANALYSIS_H 

#include <string>
#include <sstream>
#include <vector>
#include <map>

#include "WavFile.h"
#include "fourier.h"
#include "utilities.h"
#include "Hz2Note.h"
#include "MFCC.h"

#define NUM_SMOOTH 160
#define NUM_FILTERS 40

void compute_features (const char* name, std::vector<float>& features, 
	int bsize, int hop, int ncoeff, const std::string& type) {
	features.resize(ncoeff, 0); // + 1);

	WavInFile in (name); // raises exception on failure
	
	int sr = in.getSampleRate();
	int samples  = in.getNumSamples();
	int channels = in.getNumChannels ();
	int bits = in.getNumBits();

	if (sr != 44100) {
		throw std::runtime_error ("invalid sampling rate (must be 44100)");
	}
	if (channels > 2) {
		throw std::runtime_error ("unsupported number of channels");
	}
	if (bits != 16) {
		throw std::runtime_error ("unsupported number of bits");	
	}
	
	float* buffer = new float[samples * channels];
	in.read (buffer, samples * channels);

	if (channels == 2) {
		float* left = new float[samples];
	 	float* right = new float[samples];
		deinterleave (buffer, left, right, samples);
		for (unsigned i = 0; i < samples; ++i) {
			buffer[i] = (left[i] + right[i]) * .5;
		}		
	}
	
	MFCC<float> mfcc (sr, NUM_FILTERS, bsize);
	AbstractFFT<float>* fft = createFFT<float>(bsize);

	float* cdata = new float[bsize * 2];
	float* spectrum = new float[bsize];
	float* avg_coeffs = new float[bsize * 2];
	memset(avg_coeffs, 0, sizeof(float) * 2 * bsize);
	float* env = new float[bsize * 2];
	float* win = new float[bsize];
	makeWindow<float>(win, bsize, .5, .5, 0.); // hanning

	float tot_nrg = 0;
	int frames = 0;
	for (unsigned i = 0; i < samples; i += hop) {
		memset(cdata, 0, sizeof(float) * bsize * 2);		

		float nrg = 0;
		int rsize = i + bsize > samples ? samples - i : bsize;
		for (unsigned j = 0; j < rsize; ++j) {
			cdata[2 * j] = buffer[j] * win[j]; // windowing
			nrg += buffer[j] * buffer[j];
		}
		nrg = std::sqrt (nrg); // frame energy
		tot_nrg += nrg;

		fft->forward(cdata);
		for (unsigned j = 0; j < bsize; ++j) {
			spectrum[j] = sqrt (cdata[j * 2] * cdata[j * 2] + 
				cdata[j * 2 + 1] * cdata[j * 2 + 1]);
		}

		for (unsigned j = 0; j < bsize; ++j) {
			avg_coeffs[2 * j] += (spectrum[j] * nrg); // avg spectrum
		}			
		++frames;
	}

	for (unsigned i = 0; i < bsize; ++i) {
		avg_coeffs[2 *  i] /= tot_nrg; // renormalization
	}
	
	if (type == "spectrum") {
		for (unsigned j = 0; j < ncoeff; ++j) {
			features[j] = avg_coeffs[2 * j];
		}			
	} else if (type == "specpeaks") {
		for (unsigned j = 0; j < bsize; ++j) {
			spectrum[j] = avg_coeffs[2 * j];
		}		
		std::vector<int> peaks;
		locmax(spectrum, bsize / 2, peaks);
	
		if (peaks.size () < ncoeff) peaks.resize (ncoeff, 0); // preserves data
		for (unsigned j = 0; j < ncoeff; ++j) {
			features[j] = spectrum[peaks[j]];
		}			
	} else if (type == "specenv") {
		cepstralEnvelope(NUM_SMOOTH, avg_coeffs, env, fft, bsize);
		for (unsigned j = 0; j < ncoeff; ++j) {
			features[j] = env[2 * j];
		}			
	} else if (type == "mfcc") {
		for (unsigned j = 0; j < ncoeff; ++j) {
			features[j] = (mfcc.getCoeff (avg_coeffs, j));
		}

	} else if (type == "moments") {
		features.resize (4, 0); // fixed size

		for (unsigned j = 0; j < bsize; ++j) {
			spectrum[j] = avg_coeffs[2 * j];
		}				
		float* freq = new float[bsize / 2];
		ampFreqQuad(&spectrum[0], freq, bsize / 2, 44100.);

		features[0] = speccentr(spectrum, freq, bsize / 2);
		features[1] = specspread(spectrum, freq, bsize / 2, features[0]);
		features[2] = specskew(spectrum, freq, bsize / 2, features[0], features[1]);
		features[3] = speckurt(spectrum, freq, bsize / 2, features[0], features[1]);

		delete [] freq;
	} else {
		throw std::runtime_error ("invalid feature type requested");
	} 
	//features[ncoeff] = tot_nrg; // store total nrg

	delete [] buffer;
	delete [] cdata;
	delete [] avg_coeffs;
	delete [] env;
	delete fft;
}

void partials_to_notes (const char* name, std::map<std::string, int>& notes,
	unsigned bsize, unsigned hopsize, float threshold) {
	static const char* note_names[] = {
		"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"
	};

	std::vector<float> spectrum (bsize / 2);
	compute_features(name, spectrum, bsize, hopsize, bsize / 2, "spectrum");
	normalize(&spectrum[0], &spectrum[0], bsize / 2);

	std::vector<int> peaks;
	locmax(&spectrum[0], bsize / 2, peaks);

	float* freq = new float[bsize / 2];
	ampFreqQuad(&spectrum[0], freq, bsize / 2, 44100.);

	Hz2Note<float> hz2n;	
	for (unsigned i = 0; i < peaks.size() - 1; ++i) {
		if (spectrum[peaks[i]] > threshold) {
			// float fn = peaks[i] * freqPerBin;
			float fn = freq[peaks[i]];
			float nfreq = 0;
			int oct = 0;
			int note = 0;
			int cents = 0;
			hz2n.convert(fn, nfreq, oct, note, cents);
			std::stringstream n;
			n << note_names[note] << oct;
			notes[n.str ()] = cents;
		}
	}

	WavOutFile out("target.wav", 44100., 16, 1);
	unsigned samples = (unsigned) (2. * 44100.);
	float* buff = new float[samples];
	memset(buff, 0, sizeof (float) * samples);

	float* win = new float[samples];
	makeWindow<float>(win, samples, .5, .5, 0.);

	for (unsigned i = 0; i < samples; ++i) {
		for (unsigned j = 0; j < peaks.size (); ++j) {
			buff[i] += spectrum[peaks[j]] * sin (2. * M_PI * freq[peaks[j]] 
				* ((float) i / 44100.));
		}
		buff[i] *= .125 * win[i];
	}

	out.write(buff, samples);	

	delete [] buff;
	delete [] freq;
}



#endif	// ANALYSIS_H 

// EOF
