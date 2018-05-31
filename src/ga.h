// ga.h
// 

#ifndef GA_H
#define GA_H 

#include <vector>
#include <cmath>
#include <iostream>

#include "utilities.h"
#include "algorithms.h"

struct Individual {
	std::vector<int> chromosome;
	float fitness;
};

void gen_random_chromosome (std::vector<int>& f, unsigned instruments, unsigned range) {
	f.resize(instruments);
	for (unsigned i = 0; i < f.size (); ++i) {
		f[i] = rand () % range;
	}
}

void gen_random_population (std::vector<Individual>& population, unsigned instruments, unsigned range) {
	for (unsigned i = 0; i < population.size (); ++i) {
		gen_random_chromosome(population[i].chromosome, instruments, range);
		population[i].fitness = 0.;
	}
}

void forecast_individual (const Individual& id, const std::vector<db_entry>& database, 
	std::vector<float>& forecast, unsigned ncoeff) {
	
	forecast.clear ();
	forecast.resize (ncoeff);
	for (unsigned i = 0; i < id.chromosome.size (); ++i) {
		db_entry e = database[id.chromosome[i]];

		for (unsigned j = 0; j < ncoeff; ++j) {
			forecast[j] += (e.features[j]); // / id.chromosome.size());			
		}
	}

	normalize(&forecast[0], &forecast[0], ncoeff);
}

float evaluate_individual (const Individual& id, const std::vector<float>& target,
	const std::vector<db_entry>& database, unsigned ncoeff) {
	std::vector<float> values (target.size (), 0);

	forecast_individual(id, database, values, ncoeff);
	return edistance<float>(&values[0], &target[0], target.size ());

}

float evaluate_population (std::vector<Individual>& population, 
	const std::vector<float>& target, const std::vector<db_entry>& database, unsigned ncoeff) {
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

Individual select_parent (const std::vector<Individual>& population, float total_fitness) {
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
	unsigned mutation_amp, unsigned range) {
	std::stringstream mutation;
	for (unsigned i = 0; i < id.chromosome.size (); ++i) {
		float choice = frand<float>(0., 1.);
		if (choice < mutation_rate) {
			int r = (rand () % (2 * mutation_amp)) - mutation_amp;
			id.chromosome[i] += r;
			if (id.chromosome[i] >= range || id.chromosome[i] < 0) {
				id.chromosome[i] = rand () % range;
			} 
		} 
	}
}

void genereate_population (const std::vector<Individual>& old_pop,
	std::vector<Individual>& new_pop, unsigned n_individuals, float total_fitness,
	float crossover_rate, float mutation_rate, unsigned  mutation_amp, unsigned range) {

	while (new_pop.size () < n_individuals) {
		Individual parent_a = select_parent(old_pop, total_fitness);
		Individual parent_b = select_parent(old_pop, total_fitness);

		// print_individual(std::cout, parent_a); std::cout << std::endl;
		// print_individual(std::cout, parent_b);  std::cout << std::endl;

		Individual offspring1, offspring2;
		crossover_parents (offspring1, offspring2, parent_a, parent_b, crossover_rate);
		
		// print_individual(std::cout, offspring1);  std::cout << std::endl;
		// print_individual(std::cout, offspring2);  std::cout << std::endl << std::endl;
		

		mutate_individual (offspring1, mutation_rate, mutation_amp, range);
		mutate_individual (offspring2, mutation_rate, mutation_amp, range);
		// print_individual(std::cout, offspring1);  std::cout << std::endl;
		// print_individual(std::cout, offspring2);  std::cout << std::endl << std::endl;
		
		new_pop.push_back(offspring1);
		new_pop.push_back(offspring2);
	}
}

void copy_population (const std::vector<Individual>& source, std::vector<Individual>& target) {
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

void decode_chromosome (const std::vector<int>& chromosome, const std::vector<db_entry>& database,
	std::vector<std::string>& files) {

	for (unsigned i = 0; i < chromosome.size (); ++i) {
		files.push_back(database[chromosome[i]].file);
	}
}

void export_population (const std::vector<Individual>& pop,
	const std::vector<db_entry>& database, const char* root_path,
	const std::string& type, unsigned ncoeff) {
	std::ofstream solutions ("solutions.txt");
	solutions << "features: " << type << " " << ncoeff << std::endl << std::endl;
	
	for (unsigned i = 0; i < pop.size (); ++i) {
		std::vector<float> values (ncoeff, 0);		
		forecast_individual(pop[i], database, values, ncoeff);
		std::stringstream name_bmp;
		name_bmp << "solution_" << i << ".bmp";
		plot_vector(name_bmp.str ().c_str (), values, false, ncoeff);

		std::stringstream name_wav;
		name_wav << "solution_" << i << ".wav";			
		std::vector<std::string> files;
		decode_chromosome(pop[i].chromosome, database, files);
		std::vector<float> ratios (files.size (), 1);

		create_sound_mix(files, root_path, ratios, name_wav.str ().c_str ());
		for (unsigned z = 0; z < files.size (); ++z) {
			solutions << files[z] << " ";
		}
		solutions << std::endl;
	}

	solutions.close ();
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
#endif	// GA_H 

// EOF
