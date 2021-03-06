// OptimizerI.h
// 


#ifndef OPTIMIZERI_H
#define OPTIMIZERI_H 

#include "Source.h"
#include "OrchestrationModel.h"
#include "Parameters.h"

#include <vector>

template <typename T>
struct OptimizerI {
	OptimizerI (Parameters<T>* p) {
		parameters = p;
	}
	virtual ~OptimizerI () {}

	virtual T search (OrchestrationModel<T>& model, std::vector<OrchestrationModel<T> >& history) = 0;

	Source<T>* source;
	Parameters<T>* parameters;
};

#endif	// OPTIMIZERI_H 

// EOF
