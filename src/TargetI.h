// TargetI.h
// 

#ifndef TARGETI_H
#define TARGETI_H 

#include "Segment.h"
#include "Source.h"
#include "Parameters.h"

template <typename T> 
struct TargetI {
	TargetI (Source<T>* s, Parameters<T>* p) : source (s), parameters (p) {}
	virtual ~TargetI () {}

	std::vector<Segment<T> > segments;
	Source<T>* source;	
	Parameters<T>* parameters;
};


#endif	// TARGETI_H 

// EOF