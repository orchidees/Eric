// solutions.h

#ifndef SOLUTIONS_H
#define SOLUTIONS_H

#include "StandardGA.h"
#include "utilities.h"

#include <vector>
#include <map>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

template <typename T>
Solution<T> get_best_solution (const std::vector<Solution<T> >& solutions) {
	float max_fitness = 0; 
	int max_index = 0;
	for (unsigned i = 0; i < solutions.size (); ++i) {
		if (solutions[i].fitness > max_fitness) {
			max_fitness = solutions[i].fitness;
			max_index = i;
		}
	}

	return solutions[max_index];
}

template <typename T>
void export_solutions (const std::vector<Solution<T> >& pop,
	const std::vector<DB_entry<float>>& database, const Parameters<float>& c,
	std::map<std::string, int>& notes,
	const std::string& type, unsigned ncoeff, const std::string& prefix = "solution") {
	std::stringstream nn;
	nn << prefix << "_summary.txt";
	std::ofstream solutions (nn.str ());
	solutions << "features: " << type << " " << ncoeff << std::endl << std::endl;
	
	for (unsigned i = 0; i < pop.size (); ++i) {
		solutions << ">" << i << std::endl;
		std::vector<float> ratios;
		std::vector<std::string> files;
		std::vector<float> pans;
		
		std::stringstream name_wav;
		name_wav << prefix << "_" << std::setw(3) << std::setfill('0') << i << ".wav";			
		std::string symbols;

		for (unsigned j = 0; j < pop[i].chromosome.size (); ++j) {
			if (pop[i].chromosome[j] == -1) {
				solutions << "-" << std::endl;
				continue; // silent instrument
			}	

			DB_entry<float> d = database[pop[i].chromosome[j]];
			files.push_back(d.file);
			if (c.partials_filtering > 0) {
				float r = cents_to_ratio (notes[d.symbols[2]]);
				ratios.push_back (r);
			} else ratios.push_back (1.);

			if (d.symbols[0].find ("Fl") != std::string::npos)pans.push_back (.5);
			else if (d.symbols[0].find ("MulFl") != std::string::npos)pans.push_back (.5);
			else if (d.symbols[0].find ("Ob") != std::string::npos) pans.push_back(.6);
			else if (d.symbols[0].find ("MulOb") != std::string::npos) pans.push_back(.6);
			else if (d.symbols[0].find ("Cl") != std::string::npos) pans.push_back(.4);
			else if (d.symbols[0].find ("MulCl") != std::string::npos) pans.push_back(.4);
			else if (d.symbols[0].find ("Bn") != std::string::npos) pans.push_back(.55);
			else if (d.symbols[0].find ("MulBn") != std::string::npos) pans.push_back(.55);
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
				solutions << d.symbols[z] << " ";	
			}
			solutions << d.file << std::endl;
		}

		create_sound_mix(files, c.sound_paths, ratios, pans,
			name_wav.str ().c_str (), c.t60, c.dry_wet);
		solutions << std::endl;
	}

	solutions.close ();
}

#endif // SOLUTIONS_H
