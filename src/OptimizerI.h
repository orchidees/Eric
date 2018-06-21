// OptimizerI.h
// 


#ifndef OPTIMIZERI_H
#define OPTIMIZERI_H 

#include "Source.h"
#include "OrchestrationModel.h"
#include "Parameters.h"

#include <vector>

template <typename T>
struct Solution {
	std::vector<int> indices;
	T fitness;
	bool operator< (const Solution<T>& rhs) const {
		return this->fitness < rhs.fitness;
	}
	bool is_empty () {
		int scount = 0; 
		for (unsigned j = 0; j < indices.size (); ++j) {
			if (indices[j] == -1) ++scount;
		}
		return scount == indices.size ();
	}	
};

template <typename T>
struct Comp{
    Comp(const std::vector<T>& v ) : _v(v) {}
    bool operator ()(int a, int b) {  
    	return _v[a] > _v[b]; 
    }
    const std::vector<T>& _v;
};

template <typename T>
struct OptimizerI {
	OptimizerI (Parameters<T>* p) {
		parameters = p;
	}
	virtual ~OptimizerI () {}

	virtual T search (OrchestrationModel<T>& model,
		std::vector<Solution<T> >& solutions) = 0;

	Source<T>* source;
	Parameters<T>* parameters;
};

#endif	// OPTIMIZERI_H 

// EOF
