// GeneticOrchestra.h
// 


#ifndef GENETICORCHESTRA_H
#define GENETICORCHESTRA_H 

#include "Target.h"
#include "Source.h"
#include "Parameters.h"
#include "OptimizerI.h"
#include "utilities.h"
#include "constants.h"

#include <map>
#include <string>
#include <vector>
#include <deque>

#define MAX_EQUAL_FITNESS 15

// -----------------------------------------------------------------------------

template <typename T>
struct GeneticOrchestra : public OptimizerI<T> {
	GeneticOrchestra (Parameters<T>* p) : OptimizerI<T>(p) {}
	
	T search (OrchestrationModel<T>& model,
		std::vector<Solution<T> >& solutions) {
		std::vector<Solution<T> > population (OptimizerI<T>::parameters->pop_size);
		gen_population (model, population, model.target->features, 
			OptimizerI<T>::parameters->pursuit);	

		fitness.clear ();
		best_epoch = 0;		

		T total_fitness = 0;
		int fit_count = 0;
		T max_fit = 0;
		T old_fit = 0;

		std::vector<Solution<T> > best_pop;
		for (unsigned i = 0; i < OptimizerI<T>::parameters->max_epochs; ++i) {
			total_fitness = evaluate_population(population, model.target->features, 
				model.database);	

			fitness.push_back(total_fitness);

			std::vector<Solution<T> > new_pop;
			gen_offspring_population(model, population, new_pop, 
				OptimizerI<T>::parameters->pop_size, total_fitness,
				OptimizerI<T>::parameters->xover_rate, 
				OptimizerI<T>::parameters->mutation_rate, 
				OptimizerI<T>::parameters->sparsity, 
				model.orchestra, model.instruments);
	
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

		std::map<std::vector<int>, Solution<T> > uniques_map;
		for (unsigned i = 0; i < best_pop.size (); ++i) {
			uniques_map[best_pop[i].indices] = best_pop[i];
		}

		for (typename std::map<std::vector<int>, Solution<T> >::iterator it = 
			uniques_map.begin();
			it != uniques_map.end (); ++it) {
			solutions.push_back(it->second);
		}

		evaluate_population(solutions, model.target->features, 
			model.database);
		return max_fit;
	}

	std::vector<T> fitness;
	int best_epoch;
private:	
	// init population ---------------------------------------------------------
	void gen_population (OrchestrationModel<T>& model,
		std::vector<Solution<T> >& population, 
		const std::vector<T>& target,
		int k) {
		for (unsigned i = 0; i < population.size (); ++i) {
			switch (k) {
				case 0:
					gen_random_chromosome(model, population[i].indices);
				break;
				default:
					gen_pursuit_chromosome(model, population[i].indices, target, k);	
				break;	
			}
		}
	}	
	void gen_random_chromosome (OrchestrationModel<T>& model, std::vector<int>& f) {
	 	f.resize(model.orchestra.size ());	
		for (unsigned i = 0; i < f.size (); ++i) {
			std::string inum = model.orchestra[i];

			std::deque<std::string> res;
			if (model.orchestra[i].find ("|") != std::string::npos) { // doublings
				tokenize(model.orchestra[i], res, "|");
				int p = rand () % res.size ();
				inum = res[p];
			}
			
			unsigned p = rand () % model.instruments[inum].size();		
			f[i] = model.instruments[inum][p];
		}
	}
	void gen_pursuit_chromosome (OrchestrationModel<T>& model,
		std::vector<int>& f, 
		const std::vector<T>& target,
		int kth) {

		f.resize(model.orchestra.size ());	

		std::vector<T> residual (target.size ());
		for (unsigned i = 0; i < target.size (); ++i) {
			residual[i] = target[i];
		}

		for (unsigned i = 0; i < f.size (); ++i) {		
			// std::cout << "i = " << i << std::endl;
			std::string inum = model.orchestra[i];

			std::deque<std::string> res;
			if (model.orchestra[i].find ("|") != std::string::npos) { // doublings
				tokenize(model.orchestra[i], res, "|");
				int p = rand () % res.size ();
				inum = res[p];
			}

			std::vector<T> moduli;
			std::vector<T> projections;
			std::vector<T> indexes;
			for (unsigned k = 0; k < model.instruments[inum].size (); ++k) {
				DB_entry<T> e = model.database[model.instruments[inum][k]];
				// std::vector<T> nfeat (e.features);
				// normalize(&nfeat[0], &nfeat[0], nfeat.size());

				T R = norm (&e.features[0], e.features.size()); // regularization
				T d = (inner_prod(&residual[0], &e.features[0], residual.size ()));
				projections.push_back(d);
				moduli.push_back(fabs (d) - R);
				indexes.push_back(model.instruments[inum][k]);
				// std::cout << k << " " << e.file << " " << fabs(d) << std::endl;
			}

			std::vector<int> vx (moduli.size ());
			for (unsigned k = 0; k < moduli.size(); ++k){
				vx[k]= k;
			}
			kth = kth > vx.size () ? vx.size () : kth;

			partial_sort (vx.begin(), vx.begin() + kth, vx.end (), Comp<T>(moduli));

			unsigned p = rand () % kth;		
			f[i] = indexes[vx[p]];
			// std::cout << "SELECTED " << vx[p] << " " << database[f[i]].file << std::endl;
			T no = norm<T> (&model.database[f[i]].features[0], 
				model.database[f[i]].features.size ());
			no *= no;
			for (unsigned k = 0; k < residual.size (); ++k) {
				residual[k] -= (projections[vx[p]] * model.database[f[i]].features[k] / no);
			}
			// std::cout << "--------------------------------------- " << norm (&residual[0], residual.size()) << std::endl;
		}
	}	

	// evaluation --------------------------------------------------------------
	void forecast_individual (const Solution<T>& id, 
		const std::vector<DB_entry<T>>& database, 
		std::vector<T>& forecast, const std::vector<T>& target) {

		// T tot_nrg = 0;
		for (unsigned i = 0; i < id.indices.size (); ++i) {
			if (id.indices[i] == -1) continue; // silent instrument
			DB_entry<T> e = database[id.indices[i]];
			
			// T no = norm<T>(&e.features[0], e.features.size ());
			// T prod = inner_prod(&target[0], &e.features[0], target.size ());
			// no *= no;

			for (unsigned j = 0; j < target.size (); ++j) {
				// inner product approach
				// forecast[j] += (prod * e.features[j] / no);
				
				// Tardieu's product approach
				// forecast[j] += e.features[target.size () - 1] * e.features[j];	
				// tot_nrg += e.features[target.size () - 1];
				
				// plain 
				forecast[j] += e.features[j] / id.indices.size ();	
			}
		}

		// for (unsigned j = 0; j < target.size (); ++j) {
		// 	forecast[j] /= tot_nrg;
		// }

		// std::cout << "norms " << norm (&target[0], target.size ()) << " " << norm (&forecast[0], forecast.size ()) << std::endl;
	}
	T evaluate_individual (const Solution<T>& id, const std::vector<T>& target,
		const std::vector<DB_entry<T>>& database) {
		std::vector<T> values (target.size (), 0);

		forecast_individual(id, database, values, target);
		return edistance<T>(&values[0], &target[0], target.size ());
	}

	T evaluate_population (std::vector<Solution<T> >& population, 
		const std::vector<T>& target, const std::vector<DB_entry<T>>& database) {
		T total_fitness = 0;

		for (unsigned i = 0; i < population.size (); ++i) {
			T v =  evaluate_individual(population[i], target, database);
			if (v == 0) population[i].fitness = LARGE_VALUE;
			else population[i].fitness = pow (1. / v, 2.);
			
			total_fitness += population[i].fitness;
		}
		return total_fitness;
	} 
	
	// offsprings --------------------------------------------------------------
	void gen_offspring_population (OrchestrationModel<T>& model,
		const std::vector<Solution<T>>& old_pop,
		std::vector<Solution<T>>& new_pop, unsigned n_individuals, T total_fitness,
		T crossover_rate, T mutation_rate, T sparsity,
		const std::vector<std::string>& orchestra, 
		std::map<std::string, std::vector<int> >& instruments) {

		while (new_pop.size () < n_individuals) {
			Solution<T> parent_a = select_parent(old_pop, total_fitness);
			Solution<T> parent_b = select_parent(old_pop, total_fitness);

			Solution<T> offspring1, offspring2;
			crossover_parents (offspring1, offspring2, parent_a, parent_b, crossover_rate);
			
			mutate_individual (model, offspring1, mutation_rate);
			mutate_individual (model, offspring2, mutation_rate);
			
			apply_sparsity(offspring1, sparsity);
			apply_sparsity(offspring2, sparsity);

			new_pop.push_back(offspring1);
			new_pop.push_back(offspring2);
		}
	}	
	Solution<T> select_parent (const std::vector<Solution<T> >& population, 
		T total_fitness) {
		T wheel = frand<T>(0., 1.) * total_fitness;

		T psum = 0;
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
		const Solution<T>& parent_a, const Solution<T>& parent_b, T crossover_rate) {
		offspring1.indices = parent_a.indices;
		offspring2.indices = parent_b.indices;

		T choice = frand<T>(0., 1.);
		if (choice < crossover_rate) {
			T r = frand<T>(0., 1.);
			unsigned  cpoint = (unsigned) (r * offspring1.indices.size ());

			for (unsigned i = cpoint; i < offspring1.indices.size(); ++i) {
				offspring1.indices[i] = parent_b.indices[i];
				offspring2.indices[i] = parent_a.indices[i];
			}
		}
	}
	void mutate_individual (OrchestrationModel<T>& model,
		Solution<T>& id, T mutation_rate) {
		std::stringstream mutation;

		for (unsigned i = 0; i < id.indices.size (); ++i) {
			T choice = frand<T>(0., 1.);
			
			if (choice < mutation_rate) {
				std::string inum = model.orchestra[i];

				std::deque<std::string> res;
				if (model.orchestra[i].find ("|") != std::string::npos) { // doublings
					tokenize(model.orchestra[i], res, "|");
					int p = rand () % res.size ();
					inum = res[p];
				}

				unsigned range = model.instruments[inum].size();
				id.indices[i] = model.instruments[inum][rand () % range];
			} 
		}
	}
	void apply_sparsity (Solution<T>& id, T sparsity) {
		for (unsigned i = 0; i < id.indices.size (); ++i) {
			T p = frand<T>(0., 1.);

			if (p < sparsity) {
				id.indices[i] = -1;
			}
		}
	}

	// utilities ---------------------------------------------------------------
	void copy_population (const std::vector<Solution<T>>& source, 
		std::vector<Solution<T>>& target) {
		for (unsigned i = 0; i < source.size (); ++i) {
			target[i].indices = source[i].indices;
			target[i].fitness = source[i].fitness;
		}
	}

	
};

#endif	// GENETICORCHESTRA_H 

// EOF
