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

template <typename T>
void compute_features (const char* name, std::vector<T>& features, 
	int bsize, int hop, int ncoeff, const std::string& type) {
	features.resize(ncoeff + 1, 0); // nrg

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
	
	T* buffer = new T[samples * channels];
	in.read (buffer, samples * channels);

	if (channels == 2) {
		T* left = new T[samples];
	 	T* right = new T[samples];
		deinterleave (buffer, left, right, samples);
		for (unsigned i = 0; i < samples; ++i) {
			buffer[i] = (left[i] + right[i]) * .5;
		}		
	}
	
	MFCC<T> mfcc (sr, NUM_FILTERS, bsize);
	AbstractFFT<T>* fft = createFFT<T>(bsize);

	T* cdata = new T[bsize * 2];
	T* spectrum = new T[bsize];
	T* avg_coeffs = new T[bsize * 2];
	memset(avg_coeffs, 0, sizeof(T) * 2 * bsize);
	T* env = new T[bsize * 2];
	T* win = new T[bsize];
	makeWindow<T>(win, bsize, .5, .5, 0.); // hanning

	T tot_nrg = 0;
	int frames = 0;
	for (unsigned i = 0; i < samples; i += hop) {
		memset(cdata, 0, sizeof(T) * bsize * 2);		

		T nrg = 0;
		int rsize = i + bsize > samples ? samples - i : bsize;
		for (unsigned j = 0; j < rsize; ++j) {
			cdata[2 * j] = buffer[j] * win[j]; // windowing
			T v = fabs (buffer[j]);
			nrg += v*v;
		}
		nrg = (nrg / rsize); // frame energy
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
	} else if (type == "logspec") {
		for (unsigned j = 0; j < ncoeff; ++j) {
			features[j] = log (avg_coeffs[2 * j] + EPS);
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
		// features.resize (4, 0); // fixed size

		for (unsigned j = 0; j < bsize; ++j) {
			spectrum[j] = avg_coeffs[2 * j];
		}				
		T* freq = new T[bsize / 2];
		ampFreqQuad(&spectrum[0], freq, bsize / 2, 44100.);

		features[0] = speccentr(spectrum, freq, bsize / 2);
		features[1] = specspread(spectrum, freq, bsize / 2, features[0]);
		features[2] = specskew(spectrum, freq, bsize / 2, features[0], features[1]);
		features[3] = speckurt(spectrum, freq, bsize / 2, features[0], features[1]);

		delete [] freq;
	} else {
		throw std::runtime_error ("invalid feature type requested");
	} 
	features[ncoeff] = tot_nrg / frames; // store total nrg

	delete [] buffer;
	delete [] cdata;
	delete [] avg_coeffs;
	delete [] env;
	delete fft;
}

template <typename T>
void make_db (const char* path, const std::vector<std::string>& files,  
	std::ostream& out, std::ostream& console, int bsize, int hopsize, int ncoeff, 
	const std::string& type) {
	std::ofstream errs ("errors.txt");
	out << type << " " << bsize << " " << hopsize << " " << ncoeff
		<< std::endl;
	for (unsigned i = 0; i < files.size (); ++i) {    		
		if (files[i].find (".wav") != std::string::npos) {
			console << "(" << i << "/" << files.size () << ") analysing " << files[i] << "...";
			console.flush();
			try {
				std::vector<T> features;
				std::stringstream fullname;
				fullname << path << files[i];
				compute_features<float> (fullname.str ().c_str (), features, 
					bsize, hopsize, ncoeff, type);	

				std::cout << files[i] << features.size() << std::endl;
				out << files[i] << " ";
				for (int i = 0; i < features.size (); ++i) {
					out << features[i] << " ";
				}
				out << std::endl;
				out.flush ();
			} catch (std::exception& e) {
				errs << files[i] << std::endl;
				console << "error: " << e.what () << std::endl;
			}
			console << "done" << std::endl;
		}
	}
}

template <typename T>
void partials_to_notes (const char* name, std::map<std::string, int>& notes,
	unsigned bsize, unsigned hopsize, T threshold) {
	static const char* note_names[] = {
		"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"
	};

	std::vector<T> spectrum (bsize / 2);
	compute_features(name, spectrum, bsize, hopsize, bsize / 2, "spectrum");
	normalize(&spectrum[0], &spectrum[0], bsize / 2);

	std::vector<int> peaks;
	locmax(&spectrum[0], bsize / 2, peaks);

	T* freq = new T[bsize / 2];
	ampFreqQuad(&spectrum[0], freq, bsize / 2, 44100.);

	Hz2Note<T> hz2n;	
	for (unsigned i = 0; i < peaks.size() - 1; ++i) {
		if (spectrum[peaks[i]] > threshold) {
			// T fn = peaks[i] * freqPerBin;
			T fn = freq[peaks[i]];
			T nfreq = 0;
			int oct = 0;
			int note = 0;
			int cents = 0;
			hz2n.convert(fn, nfreq, oct, note, cents);
			std::stringstream n;
			n << note_names[note] << oct;
			notes[n.str ()] = cents;
		}
	}

	// WavOutFile out("target.wav", 44100., 16, 1);
	// unsigned samples = (unsigned) (2. * 44100.);
	// T* buff = new T[samples];
	// memset(buff, 0, sizeof (T) * samples);

	// T* win = new T[samples];
	// makeWindow<T>(win, samples, .5, .5, 0.);

	// for (unsigned i = 0; i < samples; ++i) {
	// 	for (unsigned j = 0; j < peaks.size (); ++j) {
	// 		buff[i] += spectrum[peaks[j]] * sin (2. * M_PI * freq[peaks[j]] 
	// 			* ((T) i / 44100.));
	// 	}
	// 	buff[i] *= .125 * win[i];
	// }

	// out.write(buff, samples);	

	// delete [] buff;
	// delete [] win;

	delete [] freq;
}



#endif	// ANALYSIS_H 

// EOF
