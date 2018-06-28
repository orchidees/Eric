// Session.h
// 


#ifndef SESSION_H
#define SESSION_H 

#include "Parameters.h"
#include "Source.h"
#include "TargetI.h"
#include "OptimizerI.h"
#include "OrchestrationModel.h"

#include <vector>
#include <map>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>

template <typename T>
struct Session {
	Session (Source<T>* s, Parameters<T>* p, OptimizerI<T>* o) {
		parameters = p; 
		source = s;
		optim = o;			
	}

	void orchestrate (TargetI<T>& target, 
		std::vector<OrchestrationModel<T> >& orchestrations) {
		for (unsigned i = 0; i < target.segments.size (); ++i) {
			std::cout << "segment " << i << std::endl;
			OrchestrationModel<T> model(parameters);
			make_model (target.segments[i], model);
			std::cout << "model. " << model.database.size () << std::endl;
 			optim->search(model);

			std::sort (model.solutions.begin (), model.solutions.end ());
			std::reverse(model.solutions.begin (), model.solutions.end());

			model.best_forecast.resize (model.segment->features.size ());
			orchestrations.push_back(model);
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
	void check_model (OrchestrationModel<T>& model) {
		if (model.segment == nullptr || model.database.size () == 0 || 
			model.orchestra.size () == 0) {
			throw std::runtime_error ("invalid model for orchestration");
		}		
	}
};

#endif	// SESSION_H 

// EOF
