// Target.h
// 


#ifndef TARGET_H
#define TARGET_H 

#include "analysis.h"
#include "Source.h"
#include "Parameters.h"

#include <map>
#include <vector>
#include <string>

template <typename T>
struct Target {
	Target (const char* name,
		Source<T>* s, Parameters<T>* p) {
		source = s;
		parameters = p;
		analyze(name);
	}
	void analyze (const char* name) {
		compute_features<T>(name, features, source->bsize, 
			source->hopsize, source->ncoeff, source->type);
		// normalize (&features[0], &features[0], features.size ());

		if (parameters->partials_filtering > 0) {
			partials_to_notes<T> (name, notes, 
				parameters->partials_window, parameters->partials_window / 4, 
				parameters->partials_filtering);	
			for (unsigned i = 0; i < parameters->extra_pitches.size (); ++i) {
				notes[parameters->extra_pitches[i]] = 0;
			}					
		}		

	}
	Parameters<T>* parameters;
	Source<T>* source;

	std::vector<T> features;
	std::map<std::string, int> notes;
};

#endif	// TARGET_H 

// EOF
