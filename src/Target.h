// Target.h
// 


#ifndef TARGET_H
#define TARGET_H 

#include "analysis.h"
#include "Source.h"
#include "Parameters.h"
#include "WavFile.h"

#include <map>
#include <vector>
#include <string>

template <typename T>
struct Segment {
	std::vector<T> features;
	std::map<std::string, int> notes;
};

template <typename T>
struct Target {
	Target (const char* name,
		Source<T>* s, Parameters<T>* p) {
		source = s;
		parameters = p;
		analyze(name);
	}

	void analyze (const char* name) {
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

			delete [] left;
			delete [] right;		
		}

		Segment<T> seg;

		// get segments here
		// for segments
		compute_features<T>(buffer, samples, seg.features, source->bsize, 
			source->hopsize, source->ncoeff, source->type);
		normalize2(&seg.features[0], &seg.features[0], seg.features.size ());

		if (parameters->partials_filtering > 0) {
			partials_to_notes<T> (name, seg.notes, 
				parameters->partials_window, parameters->partials_window / 4, 
				parameters->partials_filtering);	
			for (unsigned i = 0; i < parameters->extra_pitches.size (); ++i) {
				seg.notes[parameters->extra_pitches[i]] = 0;
			}					
		}
		segments.push_back (seg);
		// end


		delete [] buffer;
	}

	Parameters<T>* parameters;
	Source<T>* source;

	std::vector<Segment<T> > segments;
};


#endif	// TARGET_H 

// EOF
