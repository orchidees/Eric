// ga.h
// 


#ifndef GA_H
#define GA_H 

#include <vector>
#include <cmath>
#include <iostream>

#include "utilities.h"
#include "algorithms.h"

#define LARGE_VALUE 100000000

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
			forecast[j] += (e.features[j] / id.chromosome.size ());			
		}
	}
}

float evaluate_individual (const Individual& id, const std::vector<float>& target,
	const std::vector<db_entry>& database, unsigned ncoeff) {
	std::vector<float> values (target.size (), 0);
	forecast_individual(id, database, values, ncoeff);

	float sum = 0;
	for (unsigned i = 0; i < target.size (); ++i) {
		sum += fabs (values[i] - target[i]);
	}

	return sum;
}

float evaluate_population (std::vector<Individual>& population, 
	const std::vector<float>& target, const std::vector<db_entry>& database, unsigned ncoeff) {
	float total_fitness = 0;

	for (unsigned i = 0; i < population.size (); ++i) {
		float v =  evaluate_individual(population[i], target, database, ncoeff);
		if (v == 0) population[i].fitness = LARGE_VALUE;
		else population[i].fitness = 1. / v;
		
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
	float wheel = frand(0, 1) * total_fitness;
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

void crossover_parents (Individual& child, const Individual& parent_a, 
	const Individual& parent_b, float crossover_rate) {
	child.chromosome = parent_a.chromosome;

	float choice = frand (0, 1);
	if (choice < crossover_rate) {
		float r = frand (0, 1);
		unsigned  cpoint = (unsigned) (r * child.chromosome.size ());
		for (unsigned i = cpoint; i < child.chromosome.size(); ++i) {
			child.chromosome[i] = parent_b.chromosome[i];
		}
	}
}

void mutate_individual (Individual& id, float mutation_rate, 
	unsigned mutation_amp, unsigned range) {
	std::stringstream mutation;
	for (unsigned i = 0; i < id.chromosome.size (); ++i) {
		float choice = frand (0, 1);
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

	for (unsigned i = 0; i < n_individuals; ++i) {
		Individual parent_a = select_parent(old_pop, total_fitness);
		Individual parent_b = select_parent(old_pop, total_fitness);

		Individual child;
		crossover_parents (child, parent_a, parent_b, crossover_rate);
		mutate_individual (child, mutation_rate, mutation_amp, range);

		new_pop[i] = (child);
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

#endif	// GA_H 

// EOF
