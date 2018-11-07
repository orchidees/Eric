// SessionI.h
// 

#ifndef SESSIONI_H
#define SESSIONI_H 

#include "SessionI.h"
#include "Parameters.h"
#include "Source.h"
#include "TargetI.h"
#include "OptimizerI.h"
#include "OrchestrationModel.h"
#include "ConnectionModel.h"
#include "forecasts.h"

#include <vector>
#include <map>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>


template <typename T>
struct SessionI {
	SessionI (Source<T>* s, Parameters<T>* p, OptimizerI<T>* o) {
		parameters = p; 
		source = s;
		optim = o;			
	}

	virtual ~SessionI () {}

	void orchestrate (TargetI<T>& target, 
		std::vector<OrchestrationModel<T> >& orchestrations) {
		orchestrations.clear (); // FIXME: why crashes if not cleared?		
		
		for (unsigned i = 0; i < target.segments.size (); ++i) {
			OrchestrationModel<T> model(SessionI<T>::parameters);
			make_model (target.segments[i], model);
 			SessionI<T>::optim->search(model);

			std::sort (model.solutions.begin (), model.solutions.end ());
			std::reverse(model.solutions.begin (), model.solutions.end());

			set_durations(model);

			model.best_forecast.resize (model.segment->features.size ());
			orchestrations.push_back(model);
		}
	}

	virtual void connect (std::vector<OrchestrationModel<T> >& orchestrations,
		ConnectionModel<T>& connection) = 0;
	void export_solutions (const std::string& prefix,
		std::vector<OrchestrationModel<T> >& orchestrations,
		ConnectionModel<T>& connection) {
		for (unsigned i = 0; i < orchestrations.size (); ++i) {
			if (orchestrations[i].solutions.size () && 
				SessionI<T>::parameters->export_solutions > 0) {
		        if (SessionI<T>::parameters->notifier != nullptr) {
			        	SessionI<T>::parameters->notifier ("exporting segment ", i + 1);
		        }				
				std::stringstream full_prefix;
				full_prefix << prefix << "segment_" << std::setw (4) 
					<< std::setfill('0') << i + 1 << "_";
				std::stringstream fit_name;
				fit_name << full_prefix.str () << "fitness.txt";			
				save_vector<T> (fit_name.str ().c_str (), orchestrations[i].fitness);
		
				std::stringstream tar_name;
				tar_name << full_prefix.str () << "features.txt";
				save_vector(tar_name.str ().c_str (), orchestrations[i].segment->features);

				AdditiveForecast<T>::compute(orchestrations[i].solutions[0], 
					orchestrations[i].database, 
					orchestrations[i].best_forecast, orchestrations[i].segment->features,
					SessionI<T>::parameters);
				normalize2(&orchestrations[i].best_forecast[0], 
					&orchestrations[i].best_forecast[0], 
					orchestrations[i].best_forecast.size());

				std::stringstream best_name;
				best_name << full_prefix.str () << "best_forecast.txt";							
				save_vector(best_name.str ().c_str (), orchestrations[i].best_forecast);
			
				orchestrations[i].export_solutions(full_prefix.str ());
			}
		}
        
        if (SessionI<T>::parameters->notifier != nullptr) {
	        	SessionI<T>::parameters->notifier ("exporting connection", 1);
        }
		connection.export_solutions(prefix);
	}
	void make_model (Segment<T>& segment, OrchestrationModel<T>& model) {
		model.database.clear ();
		model.orchestra.clear ();
		model.instruments.clear ();
		model.ncoeff = SessionI<T>::source->ncoeff;
		model.segment = &segment; // set segment

		for (unsigned j = 0; j <  SessionI<T>::source->database.size (); ++j) {
			bool note_check = segment.notes.size () == 0 ? true : false;
			bool style_check =  SessionI<T>::parameters->styles.size () == 0 ? true : false;
			bool dynamics_check =  SessionI<T>::parameters->dynamics.size () == 0 ? true : false;
			bool others_check =  SessionI<T>::parameters->others.size () == 0 ? true : false;

			for (std::map<std::string, int>::iterator i = segment.notes.begin(); 
				i != segment.notes.end (); ++i) {
				if ( SessionI<T>::source->database[j].symbols[2] == i->first) {
					note_check = true;
					break;
				}
			}

			for (unsigned i = 0; i <  SessionI<T>::parameters->styles.size (); ++i) {
				if ( SessionI<T>::source->database[j].symbols[1] ==  SessionI<T>::parameters->styles[i]) {
					style_check = true;
					break;
				}
			}

			for (unsigned i = 0; i <  SessionI<T>::parameters->dynamics.size (); ++i) {
				if ( SessionI<T>::source->database[j].symbols[3] ==  SessionI<T>::parameters->dynamics[i]) {
					dynamics_check = true;
					break;
				}
			}

			for (unsigned i = 0; i <  SessionI<T>::parameters->others.size (); ++i) {
				std::stringstream others;
				for (unsigned z = 4; z <  SessionI<T>::source->database[j].symbols.size (); ++z){
					others <<  SessionI<T>::source->database[j].symbols[z];
				}
				if (others.str ().find (SessionI<T>::parameters->others[i]) != std::string::npos) {
					others_check = true;
					break;
				}
			}			

			if (note_check && style_check && dynamics_check && others_check) {
				model.database.push_back(&SessionI<T>::source->database[j]);
			}
		}

		if (model.database.size () < 1) {
			throw std::runtime_error("empty search space; please check filters");
		}

		for (unsigned i = 0; i < model.database.size (); ++i) {
			insert_symbol (model.instruments, model.database[i]->symbols[0], i);
		}
		for (std::vector<std::string>::iterator i =  SessionI<T>::parameters->orchestra.begin(); 
			i !=  SessionI<T>::parameters->orchestra.end ();
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


protected:
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


#endif	// SESSIONI_H 

// EOF
