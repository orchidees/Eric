// StandardGA.h
// 


#ifndef STANDARDGA_H
#define STANDARDGA_H 

#include "Target.h"
#include "Source.h"
#include "Parameters.h"
#include "utilities.h"
#include "constants.h"

#include <map>
#include <string>
#include <vector>
#include <deque>

#define MAX_EQUAL_FITNESS 15

struct Comp{
    Comp( const std::vector<float>& v ) : _v(v) {}
    bool operator ()(int a, int b) {  
    	return _v[a] > _v[b]; 
    }
    const std::vector<float>& _v;
};

// -----------------------------------------------------------------------------

template <typename T>
struct Solution {
	std::vector<int> chromosome;
	float fitness;
	bool operator< (const Solution<T>& rhs) const {
		return this->fitness < rhs.fitness;
	}
};

template <typename T>
struct StandardGA {
	StandardGA (const Source<T>* s, const Parameters<T>* p) {
		source = s;
		parameters = p;
	}
	
	T search (const Target<T>& target, std::vector<Solution<T> >& solutions) {
		std::vector<Solution<T> > population (parameters->pop_size);
		gen_population (population, source->actual_orchestra, source->actual_instruments, 
			source->database, target.features, parameters->pursuit);	

		fitness.clear ();
		best_epoch = 0;		

		T total_fitness = 0;
		int fit_count = 0;
		T max_fit = 0;
		T old_fit = 0;

		std::vector<Solution<T> > best_pop;
		for (unsigned i = 0; i < parameters->max_epochs; ++i) {
			total_fitness = evaluate_population(population, target.features, 
				source->database, source->ncoeff);	

			fitness.push_back(total_fitness);

			std::vector<Solution<T> > new_pop;
			gen_offspring_population(population, new_pop, parameters->pop_size, total_fitness,
				parameters->xover_rate, parameters->mutation_rate, parameters->sparsity, 
				parameters->actual_orchestra, parameters->actual_instruments);
	
			copy_population (new_pop, population);

			if (max_fit < total_fitness) {
				max_fit = total_fitness;
				best_pop = new_pop;
				best_epoch = i;
			}
			if (total_fitness >= LARGE_VALUE) break;
			if (old_fit == total_fitness) ++fit_count;
			if (fit_count > MAX_EQUAL_FITNESS) break;
			old_fit = total_fitness;
		}		

		if (best_pop.size () == 0) {
			best_pop = population;
		}

		make_uniques(best_pop, solutions);
		evaluate_population(solutions, target.features, source->database, source->ncoeff);
		std::sort (solutions.begin (), solutions.end ());
		std::reverse(solutions.begin (), solutions.end());

		return max_fit;
	}

	Source<T>* source;
	Parameters<T>* parameters;
	std::vector<T> fitness;
	int best_epoch;
private:	
	void gen_population (std::vector<Solution<T> >& population, 
		const std::vector<float>& target,
		int k) {
		for (unsigned i = 0; i < population.size (); ++i) {
			switch (k) {
				case 0:
					gen_random_chromosome(population[i].chromosome, source->actual_orchestra, 
						source->actual_instruments);
				break;
				default:
					gen_pursuit_chromosome(population[i].chromosome, source->actual_orchestra, 
						source->actual_instruments,
						source->database, target, k);	
				break;	
			}
		}
	}	
	float evaluate_individual (const Solution<T>& id, const std::vector<float>& target,
		const std::vector<DB_entry<float>>& database, unsigned ncoeff) {
		std::vector<float> values (target.size (), 0);

		forecast_individual(id, database, values, target);
		return edistance<float>(&values[0], &target[0], target.size ());
	}

	float evaluate_population (std::vector<Solution<T> >& population, 
		const std::vector<float>& target, const std::vector<DB_entry<float>>& database, 
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
	
	Solution<T> select_parent (const std::vector<Solution<T> >& population, 
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

	void crossover_parents (Solution<T>& offspring1, Solution<T>& offspring2, 
		const Solution<T>& parent_a, const Solution<T>& parent_b, float crossover_rate) {
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

	void mutate_individual (Solution<T>& id, float mutation_rate) {
		std::stringstream mutation;

		for (unsigned i = 0; i < id.chromosome.size (); ++i) {
			float choice = frand<float>(0., 1.);
			
			if (choice < mutation_rate) {
				std::string inum = source->actual_orchestra[i];

				std::deque<std::string> res;
				if (source->actual_orchestra[i].find ("|") != std::string::npos) { // doublings
					tokenize(source->actual_orchestra[i], res, "|");
					int p = rand () % res.size ();
					inum = res[p];
				}

				unsigned range = source->actual_instruments[inum].size();
				id.chromosome[i] = source->actual_instruments[inum][rand () % range];
			} 
		}
	}

	void apply_sparsity (Solution<T>& id, float sparsity) {
		for (unsigned i = 0; i < id.chromosome.size (); ++i) {
			float p = frand<float>(0., 1.);

			if (p < sparsity) {
				id.chromosome[i] = -1;
			}
		}
	}

	void gen_offspring_population (const std::vector<Solution<T>>& old_pop,
		std::vector<Solution<T>>& new_pop, unsigned n_individuals, float total_fitness,
		float crossover_rate, float mutation_rate, float sparsity,
		const std::vector<std::string>& orchestra, 
		std::map<std::string, std::vector<int> >& instruments) {

		while (new_pop.size () < n_individuals) {
			Solution<T> parent_a = select_parent(old_pop, total_fitness);
			Solution<T> parent_b = select_parent(old_pop, total_fitness);

			Solution<T> offspring1, offspring2;
			crossover_parents (offspring1, offspring2, parent_a, parent_b, crossover_rate);
			
			mutate_individual (offspring1, mutation_rate, orchestra, instruments);
			mutate_individual (offspring2, mutation_rate, orchestra, instruments);
			
			apply_sparsity(offspring1, sparsity);
			apply_sparsity(offspring2, sparsity);

			new_pop.push_back(offspring1);
			new_pop.push_back(offspring2);
		}
	}

	void copy_population (const std::vector<Solution<T>>& source, 
		std::vector<Solution<T>>& target) {
		for (unsigned i = 0; i < source.size (); ++i) {
			target[i].chromosome = source[i].chromosome;
			target[i].fitness = source[i].fitness;
		}
	}

	void forecast_individual (const Solution<T>& id, const std::vector<DB_entry<float>>& database, 
		std::vector<float>& forecast, const std::vector<float>& target) {
		
		// inner product approach
		for (unsigned i = 0; i < id.chromosome.size (); ++i) {
			if (id.chromosome[i] == -1) continue; // silent instrument
			DB_entry<float> e = database[id.chromosome[i]];
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

	void gen_random_chromosome (std::vector<int>& f) {
	 	f.resize(source->actual_orchestra.size ());	
		for (unsigned i = 0; i < f.size (); ++i) {
			std::string inum = source->actual_orchestra[i];

			std::deque<std::string> res;
			if (source->actual_orchestra[i].find ("|") != std::string::npos) { // doublings
				tokenize(source->actual_orchestra[i], res, "|");
				int p = rand () % res.size ();
				inum = res[p];
			}
			
			unsigned p = rand () % source->actual_instruments[inum].size();		
			f[i] = source->actual_instruments[inum][p];
		}
	}
	void gen_pursuit_chromosome (std::vector<int>& f, 
		const std::vector<float>& target,
		int kth) {

		f.resize(source->actual_orchestra.size ());	

		std::vector<float> residual (target.size ());
		for (unsigned i = 0; i < target.size (); ++i) {
			residual[i] = target[i];
		}

		for (unsigned i = 0; i < f.size (); ++i) {		
			// std::cout << "i = " << i << std::endl;
			std::string inum = source->actual_orchestra[i];

			std::deque<std::string> res;
			if (source->actual_orchestra[i].find ("|") != std::string::npos) { // doublings
				tokenize(source->actual_orchestra[i], res, "|");
				int p = rand () % res.size ();
				inum = res[p];
			}

			std::vector<float> moduli;
			std::vector<float> projections;
			std::vector<float> indexes;
			for (unsigned k = 0; k < source->actual_instruments[inum].size (); ++k) {
				DB_entry<float> e = source->database[source->actual_instruments[inum][k]];
				// std::vector<float> nfeat (e.features);
				// normalize(&nfeat[0], &nfeat[0], nfeat.size());

				float R = norm (&e.features[0], e.features.size()); // regularization
				float d = (inner_prod(&residual[0], &e.features[0], residual.size ()));
				projections.push_back(d);
				moduli.push_back(fabs (d) - R);
				indexes.push_back(source->actual_instruments[inum][k]);
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
			float no = norm<float> (&source->database[f[i]].features[0], source->database[f[i]].features.size ());
			no *= no;
			for (unsigned k = 0; k < residual.size (); ++k) {
				residual[k] -= (projections[vx[p]] * source->database[f[i]].features[k] / no);
			}
			// std::cout << "--------------------------------------- " << norm (&residual[0], residual.size()) << std::endl;
		}
	}
};

#endif	// STANDARDGA_H 

// EOF
