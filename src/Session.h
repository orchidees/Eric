// Session.h
// 


#ifndef SESSION_H
#define SESSION_H 

#include "SessionI.h"
#include "Parameters.h"
#include "Source.h"
#include "OptimizerI.h"
#include "OrchestrationModel.h"
#include "ConnectionModel.h"

template <typename T, template <typename X> class ConnectionPolicy>
struct Session : public SessionI<T> {
	Session (Source<T>* s, Parameters<T>* p, OptimizerI<T>* o) : SessionI<T> (s, p, o) {			
	}


	void connect (std::vector<OrchestrationModel<T> >& orchestrations,
		ConnectionModel<T>& connection) {
		connection.models.clear ();
		connection.indices.clear ();

		ConnectionPolicy<T>::connect (orchestrations, connection);

		// continuity model
		for (unsigned m1 = 0; m1 < connection.models.size (); ++m1) {
			Solution<T>& sol1 = connection.models[m1]->solutions[connection.indices[m1]];
			for (unsigned s1 = 0; s1 < sol1.indices.size (); ++s1) {
				if (sol1.indices[s1] == -1) continue; // look for next instrumnets
				for (unsigned m2 = m1; m2 < connection.models.size (); ++m2) {
					if (m1 == m2) continue; // start checking from next timepoint
					Solution<T>& sol2 = connection.models[m2]->solutions[connection.indices[m2]];

					if (s1 >= sol2.indices.size ()) break; // instrument cannot be continued
					if (sol2.indices[s1] == -1) break; // there is nothing to continue

					DB_entry<T>* n1 = connection.models[m1]->database[sol1.indices[s1]];
					DB_entry<T>* n2 = connection.models[m2]->database[sol2.indices[s1]];
					
					if (n1->symbols[2] == n2->symbols[2]) {
						sol2.indices[s1] = -1; // assumed
						sol1.durations[s1] += sol2.durations[s1];
					} else break;
				}
			}

		}		
	}

};

#endif	// SESSION_H 

// EOF
