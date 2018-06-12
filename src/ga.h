// ga.h
// 

#ifndef GA_H
#define GA_H 

#include "Parameters.h"
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

struct Comp{
    Comp( const std::vector<float>& v ) : _v(v) {}
    bool operator ()(int a, int b) {  
    	return _v[a] > _v[b]; 
    }
    const std::vector<float>& _v;
};

void gen_pursuit_chromosome (std::vector<int>& f, 
	const std::vector<std::string>& orchestra, 
	std::map<std::string, std::vector<int> >& instruments,
	const std::vector<DB_entry>& database,
	const std::vector<float>& target,
	int kth) {

	f.resize(orchestra.size ());	

	std::vector<float> residual (target.size ());
	for (unsigned i = 0; i < target.size (); ++i) {
		residual[i] = target[i];
	}

	for (unsigned i = 0; i < f.size (); ++i) {		
		// std::cout << "i = " << i << std::endl;
		std::string inum = orchestra[i];

		std::deque<std::string> res;
		if (orchestra[i].find ("|") != std::string::npos) { // doublings
			tokenize(orchestra[i], res, "|");
			int p = rand () % res.size ();
			inum = res[p];
		}

		std::vector<float> moduli;
		std::vector<float> projections;
		std::vector<float> indexes;
		for (unsigned k = 0; k < instruments[inum].size (); ++k) {
			DB_entry e = database[instruments[inum][k]];
			// std::vector<float> nfeat (e.features);
			// normalize(&nfeat[0], &nfeat[0], nfeat.size());

			float R = norm (&e.features[0], e.features.size()); // regularization
			float d = (inner_prod(&residual[0], &e.features[0], residual.size ()));
			projections.push_back(d);
			moduli.push_back(fabs (d) - R);
			indexes.push_back(instruments[inum][k]);
			// std::cout << k << " " << e.file << " " << fabs(d) << std::endl;
		}

		std::vector<int> vx (moduli.size ());
		for (unsigned k = 0; k < moduli.size(); ++k){
			vx[k]= k;
		}
		kth = kth > vx.size () ? vx.size () : kth;

		partial_sort (vx.begin(), vx.begin() + kth, vx.end (), Comp(moduli));

		unsigned p = rand () % kth;		
		f[i] = indexes[vx[p]];
		// std::cout << "SELECTED " << vx[p] << " " << database[f[i]].file << std::endl;
		float no = norm<float> (&database[f[i]].features[0], database[f[i]].features.size ());
		no *= no;
		for (unsigned k = 0; k < residual.size (); ++k) {
			residual[k] -= (projections[vx[p]] * database[f[i]].features[k] / no);
		}
		// std::cout << "--------------------------------------- " << norm (&residual[0], residual.size()) << std::endl;
	}
}

void gen_free_pursuit_chromosome (
	std::vector<int>& f,
	const std::vector<DB_entry>& database,
	const std::vector<float>& target,
	int size,
	int kth) {
	
	f.clear ();	

	std::vector<float> residual (target.size ());
	for (unsigned i = 0; i < target.size (); ++i) {
		residual[i] = target[i];
	}
	for (unsigned i = 0; i < size; ++i) {		
		std::vector<float> moduli;
		std::vector<float> projections;
		std::vector<float> indexes;
		for (unsigned k = 0; k < database.size (); ++k) {
			DB_entry e = database[k];

			float R = norm (&e.features[0], e.features.size()); // regularization
			float d = (inner_prod(&residual[0], &e.features[0], residual.size ()));
			projections.push_back(d);
			moduli.push_back(fabs (d) - R);
			indexes.push_back(k);
		}

		std::vector<int> vx (moduli.size ());
		for (unsigned k = 0; k < moduli.size(); ++k){
			vx[k]= k;
		}
		kth = kth > vx.size () ? vx.size () : kth;

		partial_sort (vx.begin(), vx.begin() + kth, vx.end (), Comp(moduli));

		unsigned p = rand () % kth;		
		int idx = indexes[vx[p]];
		std::cout << "SELECTED " << vx[p] << " " << database[idx].file << std::endl;
		float no = norm<float> (&database[idx].features[0], database[idx].features.size ());
		no *= no;
		for (unsigned k = 0; k < residual.size (); ++k) {
			residual[k] -= (projections[vx[p]] * database[idx].features[k] / no);
		}

		f.push_back(idx);
		float nn = norm (&residual[0], residual.size ());
		std::cout << " --------------------------------------- " << nn << std::endl;
	}
}

void gen_population (std::vector<Individual>& population, 
	const std::vector<std::string>& orchestra, 
	std::map<std::string, std::vector<int> >& instruments,
	const std::vector<DB_entry>& database,
	const std::vector<float>& target,
	int k) {
	for (unsigned i = 0; i < population.size (); ++i) {
		switch (k) {
			case 0:
				gen_random_chromosome(population[i].chromosome, orchestra, instruments);
			break;
			default:
				gen_pursuit_chromosome(population[i].chromosome, orchestra, instruments,
					database, target, k);	
			break;	
		}
		// gen_free_pursuit_chromosome(
		// 	population[i].chromosome,  
		// 	database, 
		// 	target, 
		// 	orchestra.size(), k);
		// population[i].fitness = 0.;
	}
}

void forecast_individual (const Individual& id, const std::vector<DB_entry>& database, 
	std::vector<float>& forecast, const std::vector<float>& target) {
	
	// inner product approach
	for (unsigned i = 0; i < id.chromosome.size (); ++i) {
		if (id.chromosome[i] == -1) continue; // silent instrument
		DB_entry e = database[id.chromosome[i]];
		// float no = norm<float>(&e.features[0], e.features.size ());
		// float prod = inner_prod(&target[0], &e.features[0], target.size ());
		// no *= no;
		for (unsigned j = 0; j < target.size (); ++j) {
			//forecast[j] += (prod * e.features[j] / no);
			forecast[j] += (e.features[j] / id.chromosome.size());	
		}
	}

	// std::cout << "norms " << norm (&target[0], target.size ()) << " " << norm (&forecast[0], forecast.size ()) << std::endl;
}

float evaluate_individual (const Individual& id, const std::vector<float>& target,
	const std::vector<DB_entry>& database, unsigned ncoeff) {
	std::vector<float> values (target.size (), 0);

	forecast_individual(id, database, values, target);
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
	const std::vector<DB_entry>& database, const Parameters<float>& c,
	std::map<std::string, int>& notes,
	const std::string& type, unsigned ncoeff, const std::string& prefix = "solution") {
	std::stringstream nn;
	nn << prefix << ".txt";
	std::ofstream solutions (nn.str ());
	solutions << "features: " << type << " " << ncoeff << std::endl << std::endl;
	
	for (unsigned i = 0; i < pop.size (); ++i) {
		solutions << ">" << i << std::endl;
		std::vector<float> ratios;
		std::vector<std::string> files;
		std::vector<float> pans;
		
		std::stringstream name_wav;
		name_wav << prefix << "_" << i << ".wav";			
		
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
			name_wav.str ().c_str (), c.t60, c.dry_wet);
		solutions << std::endl;
	}

	solutions.close ();
}

#endif	// GA_H 

// EOF
