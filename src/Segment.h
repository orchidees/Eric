// Segment.h
// 


#ifndef SEGMENT_H
#define SEGMENT_H 

#include <vector>
#include <string>
#include <map>

template <typename T>
struct Segment {
	std::vector<T> features;
	std::map<std::string, int> notes;
	T start;
	T length;
};

#endif	// SEGMENT_H 

// EOF
