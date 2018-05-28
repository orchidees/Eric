// analysis.h
// 


#ifndef ANALYSIS_H
#define ANALYSIS_H 

#include <string>
#include <sstream>

#include "WavFile.h"
#include "FFT.h"
#include "MFCC.h"
#include "utilities.h"

#define NUM_FILTERS 40

void compute_mfcc (const char* name, std::vector<float>& features, 
	int bsize, int hop, int ncoeff) {
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

	float* avg_coeffs = new float[ncoeff];
	memset(avg_coeffs, 0, sizeof(float) * ncoeff);
	float norm = (float) 1. / (samples / hop);

	for (unsigned i = 0; i < samples; i += hop) {
		memset(cdata, 0, sizeof(float) * bsize * 2);		

		int rsize = i + bsize > samples ? samples - i : bsize;
		for (unsigned j = 0; j < rsize; ++j) {
			cdata[2 * j] = buffer[j];
		}

		fft->forward(cdata);
		for (unsigned j = 0; j < bsize; ++j) {
			spectrum[j] = sqrt (cdata[j * 2] * cdata[j * 2] + 
					cdata[j * 2 + 1] * cdata[j * 2 + 1]);
		}

		for (unsigned j = 0; j < ncoeff; ++j) {
			avg_coeffs[j] += (mfcc.getCoeff (spectrum, j) * norm);
		}
	}

	features.resize(ncoeff);
	for (unsigned i = 0; i < ncoeff; ++i) {
		features[i] =  avg_coeffs[i];
	}

	delete [] buffer;
	delete [] cdata;
	delete [] avg_coeffs;
	delete fft;
}


#endif	// ANALYSIS_H 

// EOF
