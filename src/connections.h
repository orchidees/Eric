// connections.h
// 


#ifndef CONNECTIONS_H
#define CONNECTIONS_H 

#include "forecasts.h"
#include "OrchestrationModel.h"
#include "ConnectionModel.h"

#include <vector>

template <typename T>
struct BestSolutions {
	static void connect (std::vector<OrchestrationModel<T> >& orchestrations,
		ConnectionModel<T>& connection) {
		for (unsigned i = 0; i < orchestrations.size (); ++i) {
			connection.models.push_back (&orchestrations[i]);
			connection.indices.push_back (0);
		}
	}
};

template <typename T>
struct ClosestSolutions {
	static void connect (std::vector<OrchestrationModel<T> >& orchestrations,
		ConnectionModel<T>& connection) {
		
		connection.indices.push_back(0); // start from best solution
		connection.models.push_back(&orchestrations[0]);
		Segment<T>* current = orchestrations[0].segment;
		for (typename std::vector<OrchestrationModel<T> >::iterator it = orchestrations.begin () + 1; 
			it != orchestrations.end (); ++it) {
			std::vector<T> values (it->segment->features.size (), 0);

			T minDist = LARGE_VALUE;
			int argmin = 0;
			for (unsigned j = 0; j < it->solutions.size (); ++j) {
				AdditiveForecast<T>::compute(it->solutions[j], 
					it->database, values, it->segment->features, it->parameters);
				normalize2(&values[0], &values[0], values.size ());
				T s = 0; 
				for (unsigned i = 0; i < it->segment->features.size(); ++i) {
					T diff = values[i] - current->features[i];
					if (diff >= 0) s += it->parameters->positive_penalization *  diff;
		 			else s +=  it->parameters->negative_penalization * fabs (diff);
				}

				if (s < minDist) {
					minDist = s;
					argmin = j;
				}
			}

			connection.models.push_back (&(*it));
			connection.indices.push_back(argmin);
			current = it->segment;
		}
	}
};


#endif	// CONNECTIONS_H 

// EOF
