// OrchestrationModel.h
// 

#ifndef ORCHESTRATIONMODEL_H
#define ORCHESTRATIONMODEL_H 

#include "Target.h"
#include "Source.h"

#include <vector>
#include <map>
#include <string>

template<typename T>
struct OrchestrationModel {
	OrchestrationModel () : ncoeff (0), target (nullptr) {}

	int ncoeff;
	Target<T>* target;
	std::vector<DB_entry<T> > database;
	std::map<std::string, std::vector<int> > instruments;
	std::vector<std::string> orchestra;
};

#endif	// ORCHESTRATIONMODEL_H 

// EOF
