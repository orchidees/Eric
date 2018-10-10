// Target.h
// 


#ifndef SOUNDTARGET_H
#define SOUNDTARGET_H 

#include "analysis.h"
#include "Source.h"
#include "Parameters.h"
#include "WavFile.h"
#include "constants.h"
#include "Segment.h"
#include "TargetI.h"

#include <map>
#include <vector>
#include <string>

template <typename T, template <typename X> class SegmentationPolicy>
struct SoundTarget : public TargetI<T> {
	SoundTarget (const char* name,
		Source<T>* s, Parameters<T>* p) : TargetI<T> (s, p) {
		analyze(name);
	}

	SoundTarget (Source<T>* s, Parameters<T>* p) : TargetI<T> (s, p) {
		TargetI<T>::segments.clear ();
	}
	void analyze (const char* name) {
		TargetI<T>::segments.clear ();

		WavInFile in (name); // raises exception on failure
		
		int sr = in.getSampleRate();
		int samples  = in.getNumSamples();
		int channels = in.getNumChannels ();
		int bits = in.getNumBits();

		if (sr != DEFAULT_SR) {
			throw std::runtime_error ("invalid sampling rate");
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

			delete [] left;
			delete [] right;		
		}

 		// get segments here
		std::vector<T> onsets;
		SegmentationPolicy<T>::get_onsets(buffer, samples, TargetI<T>::source->bsize, 
			TargetI<T>::source->hopsize, (T) DEFAULT_SR, 
			(T) TargetI<T>::parameters->onsets_threshold, 
			(T) TargetI<T>::parameters->onsets_timegate, onsets);

		if (onsets.size () == 0) onsets.push_back(0);
		
		// save_vector("onsets.txt", onsets);
		for (unsigned i = 0; i < onsets.size (); ++i) {
			Segment<T> seg;
			int start =  (int) (onsets[i] * DEFAULT_SR);
			int len = (int) (i == onsets.size () - 1 ? samples - start
				: (int) ((onsets[i + 1] - onsets[i]) * DEFAULT_SR));
			seg.start = start;
			seg.length = len;

			compute_features<T>(buffer + start, len, seg.features, 
				TargetI<T>::source->bsize, 
				TargetI<T>::source->hopsize, TargetI<T>::source->ncoeff, 
				TargetI<T>::source->type);
			normalize2(&seg.features[0], &seg.features[0], seg.features.size ());

			if (TargetI<T>::parameters->partials_filtering > 0) {
				partials_to_notes<T> (buffer + start, len, seg.notes, 
					TargetI<T>::parameters->partials_window, 
					TargetI<T>::parameters->partials_window / 4, 
					TargetI<T>::parameters->partials_filtering);	
				for (unsigned i = 0; i < TargetI<T>::parameters->extra_pitches.size (); ++i) {
					seg.notes[TargetI<T>::parameters->extra_pitches[i]] = 0;
				}
			}
			TargetI<T>::segments.push_back (seg);
		}


		delete [] buffer;
	}
};


#endif	// SOUNDTARGET_H 

// EOF
