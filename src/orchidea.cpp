// orchidea.cpp - main file for library (C API)
//

#include "orchidea.h"

#include "SoundTarget.h"
#include "Source.h"
#include "Parameters.h"
#include "GeneticOrchestra.h"
#include "Session.h" 
#include "forecasts.h"
#include "analysis.h"
#include "utilities.h"
#include "constants.h"
#include "config.h" 
#include "segmentations.h"
#include "OrchestrationModel.h"
#include "ConnectionModel.h"
#include "connections.h"

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

#ifdef __cplusplus 
extern "C" {
#endif

	typedef float Real;

	struct OrchideaHandle {
		OrchideaHandle () {
			source = new Source<Real> (&params, false);
			target = new SoundTarget<float, FluxSegmentation> (source, &params);
			search = new GeneticOrchestra<Real, AdditiveForecast> (&params);
			session = new Session<Real, ClosestSolutions> (source, &params, search);
		}
		virtual ~OrchideaHandle () {
			delete source;
			delete target;
			delete search;
			delete session;
		}

		Parameters<Real> params;
		Source<Real>* source;
		SoundTarget<Real, FluxSegmentation>* target;
		GeneticOrchestra<Real, AdditiveForecast>* search;

		Session<Real, ClosestSolutions>* session;

		std::vector<OrchestrationModel<Real> > orchestrations;	
		ConnectionModel<Real> connection;

		std::string error_details;
		std::string last_solutions;
		std::string db_status;
	};

	OrchideaHandle* orchidea_create () {
		return new OrchideaHandle ();
	}
	void orchidea_destroy (OrchideaHandle* h) {
		delete h;
	}
	int orchidea_set_target (OrchideaHandle* h, 
		const char* filename) {
		try {
			h->target->analyze (filename);

		} catch (std::exception& e) {
			h->error_details = e.what ();
			return ORCHIDEA_TARGET_ERROR;
		}
		return ORCHIDEA_NO_ERROR;
	}
	int orchidea_set_source (OrchideaHandle* h, const char* db_paths[],
		int size) {
        try {
        	for (unsigned i = 0; i < size; ++i) {
        		h->params.db_files.push_back (db_paths[i]);
        	}
        	h->source->load ();
        	std::stringstream tmp;
	        h->source->dump (tmp);
	        h->db_status = tmp.str ();
	    } catch (std::exception& e) {
	    	h->error_details = e.what ();
	    	return ORCHIDEA_DB_ERROR;
	    }
        return ORCHIDEA_NO_ERROR;
	}
	const char* orchidea_dump_source (OrchideaHandle* h) {
		return h->db_status.c_str ();
	}
	int orchidea_set_search (OrchideaHandle* h, const char* algorithm, 
		orchidea_notifier notif) {
		std::string alg = algorithm;
		if (algorithm == (std::string) "genetic") {
			delete h->search; // created in constructor
			 h->search = new GeneticOrchestra<Real, AdditiveForecast>(&h->params);
			return ORCHIDEA_NO_ERROR;
		} else {
			return ORCHIDEA_INVALID_SEARCH_ALGORITHM;
		}
	}
	int orchidea_set_param (OrchideaHandle* h, 
		const char* param[], int size) {
		try {
			std::deque<std::string> tokens;
			for (unsigned i = 0; i < size; ++i) {
				tokens.push_back(param[i]);
			}
			h->params.set_parameter (tokens);
		} catch (std::exception& e) {
				h->error_details = e.what ();
			return ORCHIDEA_INVALID_PARAMETER;

		}

		return ORCHIDEA_NO_ERROR;
	}

	void orchidea_reset_filters (OrchideaHandle* h) {
    	h->params.dynamics.clear ();
    	h->params.styles.clear ();
    	h->params.others.clear ();
	}
	int orchidea_orchestrate (OrchideaHandle* h, int* nb_solutions) {
		if (h->target->segments.size () == 0) {
			h->error_details = "";
			return ORCHIDEA_TARGET_NOT_DEFINED;
		}
		if (h->source->tot_instruments.size () == 0) {
			h->error_details = "";
			return ORCHIDEA_SOURCE_NOT_DEFINED;
		}

		if (h->params.orchestra.size () == 0) {
			h->error_details = "";
			return ORCHIDEA_NO_INSTRUMENTS;
		}

		try {
			h->session->orchestrate (*h->target, h->orchestrations);
			h->session->connect (h->orchestrations, h->connection);
		} catch (std::exception& e) {
			h->error_details = e.what ();
			return ORCHIDEA_ORCHESTRATION_ERROR; 
		}
		return ORCHIDEA_NO_ERROR;
	}
	int orchidea_export_solutions (OrchideaHandle* h, const char* export_path, 
		orchidea_notifier notif) {
		if (h->params.sound_paths.size () == 0) {
			h->error_details = "";
			return ORCHIDEA_NO_SOUNDS;
		}

		try {
			for (unsigned i = 0; i < h->orchestrations.size (); ++i) {
				std::stringstream prefix;
				prefix << "target_" << std::setw (3) << std::setfill('0') << i << "_";
				std::stringstream fit_name;
				fit_name << prefix.str () << "fitness.txt";			
				save_vector<float> (fit_name.str ().c_str (), h->orchestrations[i].fitness);
		
				int nsol = h->orchestrations[i].solutions.size ();
				if (nsol) {
			        if (h->params.notif != nullptr) {
			        	h->params.notif ("exporting solutions ", (((float)i + 1) / (float)nsol) * 100.);
			        }

					std::stringstream tar_name;
					tar_name << prefix.str () << "features.txt";
					save_vector(tar_name.str ().c_str (), h->orchestrations[i].segment->features);

					AdditiveForecast<float>::compute(h->orchestrations[i].solutions[0], 
						h->orchestrations[i].database, 
						h->orchestrations[i].best_forecast, h->orchestrations[i].segment->features,
						&h->params);
					normalize2(&h->orchestrations[i].best_forecast[0], 
						&h->orchestrations[i].best_forecast[0], 
						h->orchestrations[i].best_forecast.size());

					std::stringstream best_name;
					best_name << prefix.str () << "best_forecast.txt";							
					save_vector(best_name.str ().c_str (), h->orchestrations[i].best_forecast);
				}

				if (h->params.export_solutions > 0) {		
					h->orchestrations[i].export_solutions(prefix.str ());
				}
			}

	        if (h->params.notif != nullptr) {
	        	h->params.notif ("exporting connection ", 100.);
	        }
			h->connection.export_solutions("");
		}
		catch (std::exception& e) {
			h->error_details = e.what ();
			return ORCHIDEA_EXPORT_ERROR;
		}

	    return ORCHIDEA_NO_ERROR;
	}
	int orchidea_analyse_sounds (OrchideaHandle* h, const char* sound_folder, const char* db_folder, 
		const char* db_name, const char* tool_path,  orchidea_notifier notif) {

		// try {
	 //        orchidea::KnowledgeBDBPtr sKnowledge = orchidea::KnowledgeBDBPtr(
	 //        	new orchidea::KnowledgeBDB(db_folder, "", tool_path));
	        
	 //        if (!sKnowledge->getBDBConnector()->addSoundDirectory(sound_folder, db_name, "", notif)) {
	 //        	h->error_details = "";
	 //        	return ORCHIDEA_ANALYSIS_ERROR;
	 //        }			
		// } catch (std::exception& e) {
		// 	h->error_details = e.what ();
		// 	return ORCHIDEA_ANALYSIS_ERROR;
		// }

        return ORCHIDEA_NO_ERROR;			
	}
	const char* orchidea_get_error_details (OrchideaHandle* h) {
		return h->error_details.c_str ();
	}
	const char* orchidea_decode_error (int error) {
		switch (error) {
			case ORCHIDEA_DB_ERROR:
				return "liborchidea: wrong or missing DB";
			break;
			case ORCHIDEA_TARGET_ERROR:
				return "liborchidea: cannot load target or compute features";
			break;			
			case ORCHIDEA_INVALID_PARAMETER:
				return "liborchidea: invalid parameter name";
			break;
			case ORCHIDEA_TARGET_NOT_DEFINED:
				return "liborchidea: target not defined";
			break;
			case ORCHIDEA_SOURCE_NOT_DEFINED:
				return "liborchidea: source not defined";
			break;
			case ORCHIDEA_INVALID_SEARCH_ALGORITHM:
				return "liborchidea: invalid search algorithm requested";
			break;						
			case ORCHIDEA_NO_SOUNDS:
				return "liborchidea: no sound folders defined";
			break;			
			case ORCHIDEA_EXPORT_ERROR:
				return "liborchidea: export error";
			break;
			case ORCHIDEA_ORCHESTRATION_ERROR:
				return "liborchidea: orchestration error";
			break;
			case ORCHIDEA_NO_INSTRUMENTS:
				return "liborchidea: no instruments defined";
			break;
			case ORCHIDEA_ANALYSIS_ERROR:
				return "liborchidea: cannot perform sound analysis";
			break;			
			default:
				return "liborchidea: no errors";
			break;
		}
	}
	void orchidea_throw (OrchideaHandle* h, int err) {
		if (err == 0) return;
		else {
			printf("%s\n", orchidea_decode_error(err));
			if (h->error_details.size ()) {
				printf("(error info: %s)\n", h->error_details.c_str ());
			}
			exit (EXIT_FAILURE);
		}
	}

#ifdef __cplusplus
}
#endif

// EOF


