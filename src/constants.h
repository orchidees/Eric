// constants.h
// 

#ifndef CONSTANTS_H
#define CONSTANTS_H 

#include <cmath>

extern const double EPS = .0000000000001;
extern const double MINIMUM_REASONABLE_THRESHOLD = 0.005;
extern const double RMAX = 0x7fffffff;
extern const double LARGE_VALUE = 1000000000;

extern const double PI = 4. * atan ((double) 1.);
extern const double TWOPI = 8. * atan ((double) 1.);

extern const double LOG2 = (double) log ((double) 2.);
extern const double LOG2OF10 = 3.32192809488736234787;
extern const double SQRT2 = sqrt (2.);

extern const double DEFAULT_SR = 44100.;


#endif	// CONSTANTS_H 

// EOF
