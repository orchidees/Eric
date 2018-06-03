// ga.h
// 

#ifndef GA_H
#define GA_H 

#include "utilities.h"
#include "algorithms.h" 

#include <vector>
#include <cmath>
#include <iostream>

struct Individual {
	std::vector<int> chromosome;
	float fitness;
	bool operator< (const Individual& rhs) const {
		return this->fitness < rhs.fitness;
	}
};

void gen_random_chromosome (std::vector<int>& f, 
	const std::vector<std::string>& orchestra, 
	std::map<std::string, std::vector<int> >& instruments) {
	f.resize(orchestra.size ());	
	for (unsigned i = 0; i < f.size (); ++i) {
		std::string inum = orchestra[i];

		std::deque<std::string> res;
		if (orchestra[i].find ("|") != std::string::npos) { // doublings
			tokenize(orchestra[i], res, "|");
			int p = rand () % res.size ();
			inum = res[p];
		}

		
		unsigned p = rand () % instruments[inum].size();		
		f[i] = instruments[inum][p];
	}
}

void gen_random_population (std::vector<Individual>& population, 
	const std::vector<std::string>& orchestra, 
	std::map<std::string, std::vector<int> >& instruments) {
	for (unsigned i = 0; i < population.size (); ++i) {
		gen_random_chromosome(population[i].chromosome, orchestra, instruments);
		population[i].fitness = 0.;
	}
}

void forecast_individual (const Individual& id, const std::vector<DB_entry>& database, 
	std::vector<float>& forecast, unsigned ncoeff) {
	forecast.clear ();
	forecast.resize (ncoeff, 0);
	for (unsigned i = 0; i < id.chromosome.size (); ++i) {
		if (id.chromosome[i] == -1) continue; // silent instrument
		DB_entry e = database[id.chromosome[i]];
		for (unsigned j = 0; j < ncoeff; ++j) {
			forecast[j] += (e.features[j] / id.chromosome.size());			
		}
	}
}

float evaluate_individual (const Individual& id, const std::vector<float>& target,
	const std::vector<DB_entry>& database, unsigned ncoeff) {
	std::vector<float> values (target.size (), 0);

	forecast_individual(id, database, values, ncoeff);
	return edistance<float>(&values[0], &target[0], target.size ());

}

float evaluate_population (std::vector<Individual>& population, 
	const std::vector<float>& target, const std::vector<DB_entry>& database, 
	unsigned ncoeff) {
	float total_fitness = 0;

	for (unsigned i = 0; i < population.size (); ++i) {
		float v =  evaluate_individual(population[i], target, database, ncoeff);
		if (v == 0) population[i].fitness = LARGE_VALUE;
		else population[i].fitness = pow (1. / v, 2.);
		
		total_fitness += population[i].fitness;
	}
	return total_fitness;
}

void print_individual (std::ostream& out, const Individual& id){	
	for (unsigned i = 0; i < id.chromosome.size (); ++i) {
		out << id.chromosome[i] << " ";
	}
}

void print_population (std::ostream& out, 
	const std::vector<Individual>& population){
	for (unsigned i = 0; i < population.size (); ++i) {
		print_individual (out, population[i]);
		out << std::endl;
	}
}

Individual select_parent (const std::vector<Individual>& population, 
	float total_fitness) {
	float wheel = frand<float>(0., 1.) * total_fitness;

	float psum = 0;
	unsigned select = 0;
	for (unsigned i = 0; i < population.size (); ++i) {
		psum += population[i].fitness;
		if (psum >= wheel) {
			select = i;
			break;
		}
	}

	return population[select];
}

void crossover_parents (Individual& offspring1, Individual& offspring2, 
	const Individual& parent_a, const Individual& parent_b, float crossover_rate) {
	offspring1.chromosome = parent_a.chromosome;
	offspring2.chromosome = parent_b.chromosome;

	float choice = frand<float>(0., 1.);
	if (choice < crossover_rate) {
		float r = frand<float>(0., 1.);
		unsigned  cpoint = (unsigned) (r * offspring1.chromosome.size ());

		for (unsigned i = cpoint; i < offspring1.chromosome.size(); ++i) {
			offspring1.chromosome[i] = parent_b.chromosome[i];
			offspring2.chromosome[i] = parent_a.chromosome[i];
		}
	}
}

void mutate_individual (Individual& id, float mutation_rate, 
	const std::vector<std::string>& orchestra, 
	std::map<std::string, std::vector<int> >& instruments) {
	std::stringstream mutation;

	for (unsigned i = 0; i < id.chromosome.size (); ++i) {
		float choice = frand<float>(0., 1.);
		
		if (choice < mutation_rate) {
			std::string inum = orchestra[i];

			std::deque<std::string> res;
			if (orchestra[i].find ("|") != std::string::npos) { // doublings
				tokenize(orchestra[i], res, "|");
				int p = rand () % res.size ();
				inum = res[p];
			}

			unsigned range = instruments[inum].size();
			id.chromosome[i] = instruments[inum][rand () % range];
		} 
	}
}

void apply_sparsity (Individual& id, float sparsity) {
	float p = frand<float>(0., 1.);

	if (p < sparsity) {
		id.chromosome[rand() % id.chromosome.size ()] = -1;
	}
}

void gen_offspring_population (const std::vector<Individual>& old_pop,
	std::vector<Individual>& new_pop, unsigned n_individuals, float total_fitness,
	float crossover_rate, float mutation_rate, float sparsity,
	const std::vector<std::string>& orchestra, 
	std::map<std::string, std::vector<int> >& instruments) {

	while (new_pop.size () < n_individuals) {
		Individual parent_a = select_parent(old_pop, total_fitness);
		Individual parent_b = select_parent(old_pop, total_fitness);

		Individual offspring1, offspring2;
		crossover_parents (offspring1, offspring2, parent_a, parent_b, crossover_rate);
		
		mutate_individual (offspring1, mutation_rate, orchestra, instruments);
		mutate_individual (offspring2, mutation_rate, orchestra, instruments);
		
		apply_sparsity(offspring1, sparsity);
		apply_sparsity(offspring2, sparsity);

		new_pop.push_back(offspring1);
		new_pop.push_back(offspring2);
	}
}

void copy_population (const std::vector<Individual>& source, 
	std::vector<Individual>& target) {
	for (unsigned i = 0; i < source.size (); ++i) {
		target[i].chromosome = source[i].chromosome;
		target[i].fitness = source[i].fitness;
	}
}

Individual get_best_individual (const std::vector<Individual>& population) {
	float max_fitness = 0; 
	int max_index = 0;
	for (unsigned i = 0; i < population.size (); ++i) {
		if (population[i].fitness > max_fitness) {
			max_fitness = population[i].fitness;
			max_index = i;
		}
	}

	return population[max_index];
}

void make_uniques (const std::vector<Individual>& population, 
	std::vector<Individual>& uniques) {
	std::map<std::vector<int>, Individual> uniques_map;
	for (unsigned i = 0; i < population.size (); ++i) {
		uniques_map[population[i].chromosome] = population[i];
	}

	for (std::map<std::vector<int>, Individual>::iterator it = uniques_map.begin();
		it != uniques_map.end (); ++it) {
		uniques.push_back(it->second);
	}
}

void export_population (const std::vector<Individual>& pop,
	const std::vector<DB_entry>& database, const Config<float>& c,
	std::map<std::string, int>& notes,
	const std::string& type, unsigned ncoeff) {
	std::ofstream solutions ("solutions.txt");
	solutions << "features: " << type << " " << ncoeff << std::endl << std::endl;
	
	for (unsigned i = 0; i < pop.size (); ++i) {
		solutions << ">" << i << std::endl;
		std::vector<float> ratios;
		std::vector<std::string> files;
		std::vector<float> pans;
		
		std::stringstream name_wav;
		name_wav << "solution_" << i << ".wav";			
		
		std::string symbols;

		for (unsigned j = 0; j < pop[i].chromosome.size (); ++j) {
			if (pop[i].chromosome[j] == -1) {
				solutions << "-" << std::endl;
				continue; // silent instrument
			}	

			DB_entry d = database[pop[i].chromosome[j]];
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
			name_wav.str ().c_str ());
		solutions << std::endl;
	}

	solutions.close ();
}

#endif	// GA_H 

// EOF
