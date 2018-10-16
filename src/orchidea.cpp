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
			source = new Source<Real> (&params);
			target = new SoundTarget<float, FluxSegmentation> (source, &params);
			session = new Session<Real, ClosestSolutions> (source, &params, 
				new GeneticOrchestra<Real, AdditiveForecast> (&params));

			source_loaded = false;
		}
		virtual ~OrchideaHandle () {
			delete source;
			delete target;
			delete session;
		}

		Parameters<Real> params;
		Source<Real>* source;
		SoundTarget<Real, FluxSegmentation>* target;

		Session<Real, ClosestSolutions>* session;

		std::vector<OrchestrationModel<Real> > orchestrations;	
		ConnectionModel<Real> connection;

		std::string error_details;
		std::string last_solutions;
		std::string db_status;

		bool source_loaded;
	};

	OrchideaHandle* orchidea_create () {
		return new OrchideaHandle ();
	}
	void orchidea_destroy (OrchideaHandle* h) {
		delete h;
	}
	void orchidea_set_notifier (OrchideaHandle* h, orchidea_notifier notifier) {
		h->params.notifier = notifier;
	}
	int orchidea_set_source (OrchideaHandle* h, const char* db_paths[],
		int size) {
        try {
        	h->params.db_files.clear ();
        	for (unsigned i = 0; i < size; ++i) {
        		h->params.db_files.push_back (db_paths[i]);
        	}
        	h->source->load ();
        	std::stringstream tmp;
	        h->source->dump (tmp);
	        h->db_status = tmp.str ();
	        h->source_loaded = true;
	    } catch (std::exception& e) {
	    	h->error_details = e.what ();
	    	return ORCHIDEA_DB_ERROR;
	    }
        return ORCHIDEA_NO_ERROR;
	}
	const char* orchidea_dump_source (OrchideaHandle* h) {
		return h->db_status.c_str ();
	}	
	int orchidea_set_target (OrchideaHandle* h, 
		const char* filename) {
		try {
			if (!h->source_loaded) throw 
				std::runtime_error ("source must be loaded before analyzing a target");

			h->target->analyze (filename);

		} catch (std::exception& e) {
			h->error_details = e.what ();
			return ORCHIDEA_TARGET_ERROR;
		}
		return ORCHIDEA_NO_ERROR;
	}
	int orchidea_set_search (OrchideaHandle* h, const char* algorithm) {
		std::string alg = algorithm;
		if (algorithm == (std::string) "genetic") {
			delete h->session->optim; // created in constructor
			h->session->optim = new GeneticOrchestra<Real, AdditiveForecast>(&h->params);
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
	int orchidea_orchestrate (OrchideaHandle* h, int* segments) {
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
			*segments = h->orchestrations.size ();
		} catch (std::exception& e) {
			h->error_details = e.what ();
			return ORCHIDEA_ORCHESTRATION_ERROR; 
		}
		return ORCHIDEA_NO_ERROR;
	}
	int orchidea_export_solutions (OrchideaHandle* h, const char* out_path) {
		if (h->params.sound_paths.size () == 0) {
			h->error_details = "";
			return ORCHIDEA_NO_SOUNDS;
		}

		try {
			for (unsigned i = 0; i < h->orchestrations.size (); ++i) {
				std::stringstream prefix;
				prefix << out_path << "/target_" << std::setw (3) << std::setfill('0') << i << "_";
				std::stringstream fit_name;
				fit_name << prefix.str () << "fitness.txt";			
				save_vector<float> (fit_name.str ().c_str (), h->orchestrations[i].fitness);
		
				int norch = h->orchestrations.size ();
				if (norch) {
			        if (h->params.notifier != nullptr) {
			        	h->params.notifier ("exporting solutions ", (((float)i + 1) / (float)norch) * 100.);
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

	        if (h->params.notifier != nullptr) {
	        	h->params.notifier ("exporting connection ", 100.);
	        }
			h->connection.export_solutions(out_path);
		}
		catch (std::exception& e) {
			h->error_details = e.what ();
			return ORCHIDEA_EXPORT_ERROR;
		}

	    return ORCHIDEA_NO_ERROR;
	}
	int orchidea_analyse_sounds (OrchideaHandle* h, const char* sound_folder, 
		const char* db_name, int bsize, int hopsize, int ncoeff, const char* feature) {

		try {
	    	std::vector<std::string> files;
	        if (h->params.notifier != nullptr) {
	        	h->params.notifier ("listing files", 100.);
	        }
	    	listdir (sound_folder, sound_folder, files); 

	    	std::ofstream out (db_name);
	    	if (!out.good ()) {
	    		throw std::runtime_error ("cannot create database");
	    	}
	        make_db<Real>(sound_folder, files, out, std::cout, 
	        	bsize, hopsize, ncoeff, feature, h->params.notifier);
		} catch (std::exception& e) {
			h->error_details = e.what ();
			return ORCHIDEA_ANALYSIS_ERROR;
		}

        return ORCHIDEA_NO_ERROR;			
	}
	const char* orchidea_get_error_details (OrchideaHandle* h) {
		return h->error_details.c_str ();
	}
	const char* orchidea_decode_error (int error) {
		switch (error) {
			case ORCHIDEA_DB_ERROR:
				return "orchidea: wrong or missing DB";
			break;
			case ORCHIDEA_TARGET_ERROR:
				return "orchidea: cannot load target or compute features";
			break;			
			case ORCHIDEA_INVALID_PARAMETER:
				return "orchidea: invalid parameter name";
			break;
			case ORCHIDEA_TARGET_NOT_DEFINED:
				return "orchidea: target not defined";
			break;
			case ORCHIDEA_SOURCE_NOT_DEFINED:
				return "orchidea: source not defined";
			break;
			case ORCHIDEA_INVALID_SEARCH_ALGORITHM:
				return "orchidea: invalid search algorithm requested";
			break;						
			case ORCHIDEA_NO_SOUNDS:
				return "orchidea: no sound folders defined";
			break;			
			case ORCHIDEA_EXPORT_ERROR:
				return "orchidea: export error";
			break;
			case ORCHIDEA_ORCHESTRATION_ERROR:
				return "orchidea: orchestration error";
			break;
			case ORCHIDEA_NO_INSTRUMENTS:
				return "orchidea: no instruments defined";
			break;
			case ORCHIDEA_ANALYSIS_ERROR:
				return "orchidea: cannot perform sound analysis";
			break;			
			default:
				return "orchidea: no errors";
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


