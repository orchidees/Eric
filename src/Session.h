// Session.h
// 


#ifndef SESSION_H
#define SESSION_H 

#include "Parameters.h"
#include "Source.h"
#include "TargetI.h"
#include "OptimizerI.h"
#include "OrchestrationModel.h"
#include "ConnectionModel.h"

#include <vector>
#include <map>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>

template <typename T, template <typename X> class ConnectionPolicy>
struct Session {
	Session (Source<T>* s, Parameters<T>* p, OptimizerI<T>* o) {
		parameters = p; 
		source = s;
		optim = o;			
	}

	void orchestrate (TargetI<T>& target, 
		std::vector<OrchestrationModel<T> >& orchestrations) {
		for (unsigned i = 0; i < target.segments.size (); ++i) {
			OrchestrationModel<T> model(parameters);
			make_model (target.segments[i], model);
 			optim->search(model);

			std::sort (model.solutions.begin (), model.solutions.end ());
			std::reverse(model.solutions.begin (), model.solutions.end());

			set_durations(model);

			model.best_forecast.resize (model.segment->features.size ());
			orchestrations.push_back(model);
		}
	}
	void connect (std::vector<OrchestrationModel<T> >& orchestrations,
		ConnectionModel<T>& connection) {
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
	void make_model (Segment<T>& segment, OrchestrationModel<T>& model) {
		model.database.clear ();
		model.orchestra.clear ();
		model.instruments.clear ();
		model.ncoeff = source->ncoeff;
		model.segment = &segment; // set segment

		for (unsigned j = 0; j <  source->database.size (); ++j) {
			bool note_check = segment.notes.size () == 0 ? true : false;
			bool style_check =  parameters->styles.size () == 0 ? true : false;
			bool dynamics_check =  parameters->dynamics.size () == 0 ? true : false;
			bool others_check =  parameters->others.size () == 0 ? true : false;

			for (std::map<std::string, int>::iterator i = segment.notes.begin(); 
				i != segment.notes.end (); ++i) {
				if ( source->database[j].symbols[2] == i->first) {
					note_check = true;
					break;
				}
			}

			for (unsigned i = 0; i <  parameters->styles.size (); ++i) {
				if ( source->database[j].symbols[1] ==  parameters->styles[i]) {
					style_check = true;
					break;
				}
			}

			for (unsigned i = 0; i <  parameters->dynamics.size (); ++i) {
				if ( source->database[j].symbols[3] ==  parameters->dynamics[i]) {
					dynamics_check = true;
					break;
				}
			}

			for (unsigned i = 0; i <  parameters->others.size (); ++i) {
				std::stringstream others;
				for (unsigned z = 4; z <  source->database[j].symbols.size (); ++z){
					others <<  source->database[j].symbols[z];
				}
				if (others.str ().find (parameters->others[i]) != std::string::npos) {
					others_check = true;
					break;
				}
			}			

			if (note_check && style_check && dynamics_check && others_check) {
				model.database.push_back(&source->database[j]);
			}
		}

		if (model.database.size () < 1) {
			throw std::runtime_error("empty search space; please check filters");
		}

		for (unsigned i = 0; i < model.database.size (); ++i) {
			insert_symbol (model.instruments, model.database[i]->symbols[0], i);
		}
		for (std::vector<std::string>::iterator i =  parameters->orchestra.begin(); 
			i !=  parameters->orchestra.end ();
			++i) {
			if ((*i).find ("|") != std::string::npos) {
				std::deque<std::string> res;
				tokenize(*i, res, "|");
	
				bool missing = false;
				for (unsigned k = 0; k < res.size (); ++k) {
					std::map<std::string, std::vector<int> >::iterator it = 
						model.instruments.find (res[k]);
					if (it == model.instruments.end ()) {
						missing = true;
						break;
					}	
				}
				if (!missing) model.orchestra.push_back(*i);
			} else {
				std::map<std::string, std::vector<int> >::iterator it = model.instruments.find (*i);
				if (it != model.instruments.end ()) {
					model.orchestra.push_back(*i);
				}
			}
		}

		if (model.orchestra.size () == 0) {
			throw std::runtime_error ("empty orchestra; please check filters");
		}				
	}	

	Parameters<T>* parameters;
	Source<T>* source;
	OptimizerI<T>* optim;	
private:
	void set_durations (OrchestrationModel<T>& model) {
		for (unsigned i = 0; i < model.solutions.size (); ++i) {
			for (unsigned j = 0; j < model.solutions[i].indices.size (); ++j) {
				model.solutions[i].durations.push_back (model.segment->length);
			}
		}
	}
	void check_model (OrchestrationModel<T>& model) {
		if (model.segment == nullptr || model.database.size () == 0 || 
			model.orchestra.size () == 0) {
			throw std::runtime_error ("invalid model for orchestration");
		}		
	}
};

#endif	// SESSION_H 

// EOF
