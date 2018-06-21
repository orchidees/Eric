// Session.h
// 


#ifndef SESSION_H
#define SESSION_H 

#include "Parameters.h"
#include "Target.h"
#include "Source.h"
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
	T orchestrate (Target<T>& target, 
		std::vector<Solution<T> >& solutions) {
		make_model(target, model);
		T fit = optim->search(model, solutions);

		std::sort (solutions.begin (), solutions.end ());
		std::reverse(solutions.begin (), solutions.end());

		return fit;
	}
	std::ostream& dump_solution (std::ostream& out, 
		const Solution<T>& sol, int offset) {
		check_model(model);

		unsigned n_instruments = model.orchestra.size ();
		for (unsigned i = 0; i < n_instruments; ++i) {
			if (i != 0) for (unsigned i = 0; i < offset; ++i) out << " ";
			if (sol.indices[i] == -1) {
				out << "-" << std::endl;
				continue;
			}
			for (unsigned h = 0; h < model.database[sol.indices[i]].symbols.size (); ++h) {
				out << model.database[sol.indices[i]].symbols[h] << "\t";
			}	
			out << std::endl;
		}

		return out;
	}
	void export_solutions (std::vector<Solution<T> >& solutions) {
		std::string prefix = "";

		check_model(model);

		std::stringstream nn;
		nn << prefix << "solutions_summary.txt";
		std::ofstream solutions_summary (nn.str ());
		
		unsigned max_sols = parameters->export_solutions < solutions.size () ? 
			parameters->export_solutions : solutions.size ();

		for (unsigned i = 0; i < max_sols; ++i) {
			solutions_summary << ">" << i << std::endl;
			std::vector<float> ratios;
			std::vector<std::string> files;
			std::vector<float> pans;
			
			std::stringstream name_wav;
			name_wav << prefix << "solution_" << std::setw(3) << std::setfill('0') << i << ".wav";			
			std::string symbols;

			for (unsigned j = 0; j < solutions[i].indices.size (); ++j) {
				if (solutions[i].indices[j] == -1) {
					solutions_summary << "-" << std::endl;
					continue; // silent instrument
				}	

				DB_entry<float> d = model.database[solutions[i].indices[j]];
				files.push_back(d.file);
				if (parameters->partials_filtering > 0) {
					T r = cents_to_ratio<T> (model.target->notes[d.symbols[2]]);
					ratios.push_back (r);
				} else ratios.push_back (1.);

				if (d.symbols[0].find ("Fl") != std::string::npos)pans.push_back (.5);
				else if (d.symbols[0].find ("Picc") != std::string::npos)pans.push_back (.5);
				else if (d.symbols[0].find ("Acc") != std::string::npos) pans.push_back(.3);
				else if (d.symbols[0].find ("ASax") != std::string::npos) pans.push_back(.7);
				else if (d.symbols[0].find ("Ob") != std::string::npos) pans.push_back(.6);
				else if (d.symbols[0].find ("Cl") != std::string::npos) pans.push_back(.4);
				else if (d.symbols[0].find ("Bn") != std::string::npos) pans.push_back(.55);
				else if (d.symbols[0].find ("Hn") != std::string::npos) pans.push_back(.3);
				else if (d.symbols[0].find ("Tp") != std::string::npos) pans.push_back(.4);
				else if (d.symbols[0].find ("Tbn") != std::string::npos) pans.push_back(.55);
				else if (d.symbols[0].find ("BT") != std::string::npos) pans.push_back(.65);
				else if (d.symbols[0].find ("Hp") != std::string::npos) pans.push_back(.3);
				else if (d.symbols[0].find ("Vl") != std::string::npos) pans.push_back(.2);
				else if (d.symbols[0].find ("Va") != std::string::npos) pans.push_back(.55);
				else if (d.symbols[0].find ("Vc") != std::string::npos) pans.push_back(.8);
				else if (d.symbols[0].find ("Cb") != std::string::npos) pans.push_back(.7);
				else pans.push_back(.5);

				for (unsigned z = 0; z < d.symbols.size (); ++z) {
					solutions_summary << d.symbols[z] << " ";	
				}
				solutions_summary << d.file << std::endl;
			}

			create_sound_mix(files, parameters->sound_paths, ratios, pans,
				name_wav.str ().c_str (), parameters->t60, parameters->dry_wet);
			solutions_summary << std::endl;
		}

		solutions_summary.close ();
	}
	
	void make_model (Target<T>& target, OrchestrationModel<T>& model) {
		model.database.clear ();
		model.orchestra.clear ();
		model.instruments.clear ();
		model.ncoeff = source->ncoeff;
		model.target = &target;

		for (unsigned j = 0; j < source->database.size (); ++j) {
			bool note_check = target.notes.size () == 0 ? true : false;
			bool style_check = parameters->styles.size () == 0 ? true : false;
			bool dynamics_check = parameters->dynamics.size () == 0 ? true : false;
			bool others_check = parameters->others.size () == 0 ? true : false;

			for (std::map<std::string, int>::iterator i = target.notes.begin(); 
				i != target.notes.end (); ++i) {
				if (source->database[j].symbols[2] == i->first) {
					note_check = true;
					break;
				}
			}

			for (unsigned i = 0; i < parameters->styles.size (); ++i) {
				if (source->database[j].symbols[1] == parameters->styles[i]) {
					style_check = true;
					break;
				}
			}

			for (unsigned i = 0; i < parameters->dynamics.size (); ++i) {
				if (source->database[j].symbols[3] == parameters->dynamics[i]) {
					dynamics_check = true;
					break;
				}
			}

			for (unsigned i = 0; i < parameters->others.size (); ++i) {
				std::stringstream others;
				for (unsigned z = 4; z < source->database[j].symbols.size (); ++z){
					others << source->database[j].symbols[z];
				}
				if (others.str ().find (parameters->others[i]) != std::string::npos) {
					others_check = true;
					break;
				}
			}			

			if (note_check && style_check && dynamics_check && others_check) {
				model.database.push_back(source->database[j]);
			}
		}

		if (model.database.size () < 1) {
			throw std::runtime_error("empty search space; please check filters");
		}

		for (unsigned i = 0; i < model.database.size (); ++i) {
			insert_symbol (model.instruments, model.database[i].symbols[0], i);
		}
		for (std::vector<std::string>::iterator i = parameters->orchestra.begin(); 
			i != parameters->orchestra.end ();
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

	OrchestrationModel<T> model;
private:
	void check_model (OrchestrationModel<T>& model) {
		if (model.target == nullptr || model.database.size () == 0 || 
			model.orchestra.size () == 0) {
			throw std::runtime_error ("invalid model for orchestration");
		}		
	}
};

#endif	// SESSION_H 

// EOF
