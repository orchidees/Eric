// segmentations.h
// 


#ifndef SEGMENTATIONS_H
#define SEGMENTATIONS_H 

#include "fourier.h"
#include "utilities.h"

#include <vector>

template <typename T>
struct NoSegments {
	static void get_onsets (const T* buffer, int samples,
		int bsize, int hop, T sr, T threshold, T timegate, std::vector<T>& onsets) {
		onsets.push_back(0);
	}
};

template <typename T>
struct Frames {
	static void get_onsets (const T* buffer, int samples,
		int bsize, int hop, T sr, T threshold, T timegate, std::vector<T>& onsets) {
		int p = 0;
		while (p < samples) {
			onsets.push_back((T) p / sr);
			p += bsize;
		}
	}
};

template <typename T>
struct FluxSegmentation {
	static void get_onsets (const T* buffer, int samples,
		int bsize, int hop, T sr, T threshold, T timegate, std::vector<T>& onsets) {
		T* cdata = new T[bsize * 2];
		T* spectrum = new T[bsize];
		T* old_spectrum = new T[bsize];
		memset (old_spectrum, 0, sizeof (T) * bsize);

		T* win = new T[bsize];
		makeWindow<T>(win, bsize, .5, .5, 0.); // hanning
		AbstractFFT<T>* fft = createFFT<T>(bsize);
		
		std::vector<T> flux;
		int frames = 0;
		for (unsigned i = 0; i < samples; i += hop) {
			memset(cdata, 0, sizeof(T) * bsize * 2);		

			int rsize = i + bsize > samples ? samples - i : bsize;
			for (unsigned j = 0; j < rsize; ++j) {
				cdata[2 * j] = buffer[i + j] * win[j]; // windowing
			}

			fft->forward(cdata);
			for (unsigned j = 0; j < bsize; ++j) {
				spectrum[j] = sqrt (cdata[j * 2] * cdata[j * 2] + 
					cdata[j * 2 + 1] * cdata[j * 2 + 1]);
			}
		
			T v = specflux(spectrum, old_spectrum, bsize);
			flux.push_back (v);
			++frames;
		}

		
		int mpos = 0;
		T ma = maximum(&flux[0], flux.size(), mpos);
		scale<T>(&flux[0], &flux[0], flux.size (), 1. / ma);
		save_vector("flux.txt", flux);

		std::vector<int> fluxpeaks;
		locmax(&flux[0], flux.size (), fluxpeaks);

		T prev_onset = 0;
		for (unsigned i = 0; i < fluxpeaks.size (); ++i) {
			if (flux[fluxpeaks[i]] > threshold) {
				T pos = fluxpeaks[i] * hop / sr;
				T dist = fabs (pos - prev_onset);
				if (dist > timegate || i == 0) {
					onsets.push_back(pos);
					prev_onset = pos;
				}
			}
		}

	 	delete [] cdata;
		delete [] spectrum;
		delete [] old_spectrum;
		delete [] win;
		delete fft;
	}
};


#endif	// SEGMENTATIONS_H 

// EOF
