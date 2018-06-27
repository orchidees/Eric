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

#define MAX_EQUAL_EPOCHS 150

// -----------------------------------------------------------------------------

template <typename T, template <typename X> class Forecast>
struct GeneticOrchestra : public OptimizerI<T> {
	GeneticOrchestra (Parameters<T>* p) : OptimizerI<T>(p) {}
	
	T search (OrchestrationModel<T>& model) {
		std::vector<Solution<T> > population (OptimizerI<T>::parameters->pop_size);
		gen_init_population (model, population, model.segment->features, 
			OptimizerI<T>::parameters->pursuit);	

		model.fitness.clear ();
		best_epoch = 0;		

		T total_fitness = 0;
		int fit_count = 0;
		T max_fit = 0;
		T old_fit = 0;

		std::vector<Solution<T> > best_pop;
		for (unsigned i = 0; i < OptimizerI<T>::parameters->max_epochs; ++i) {
			total_fitness = evaluate_population(population, model.segment->features, 
				model.database);	

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
			model.fitness.push_back(total_fitness);

			// std::cout << "epoch " << i << " " << max_fit <<" " << total_fitness << std::endl;

			if (old_fit == max_fit) ++fit_count;
			else fit_count = 0;
			if (fit_count > MAX_EQUAL_EPOCHS) break;

			old_fit = max_fit;
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
			model.solutions.push_back(it->second);
		}

		evaluate_population(model.solutions, model.segment->features, 
			model.database);
		return max_fit;
	}

	int best_epoch;
private:	
	// init population ---------------------------------------------------------
	void gen_init_population (OrchestrationModel<T>& model,
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
					mutate_individual (model, population[i], 
						OptimizerI<T>::parameters->mutation_rate);	
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
				DB_entry<T>* e = model.database[model.instruments[inum][k]];
				// std::vector<T> nfeat (e.features);
				// normalize(&nfeat[0], &nfeat[0], nfeat.size());

				T R = norm (&e->features[0], e->features.size()); // regularization
				T d = (inner_prod(&residual[0], &e->features[0], residual.size ()));
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
			T no = norm<T> (&model.database[f[i]]->features[0], 
				model.database[f[i]]->features.size ());
			no *= no;
			for (unsigned k = 0; k < residual.size (); ++k) {
				residual[k] -= (projections[vx[p]] * model.database[f[i]]->features[k] / no);
			}
			// std::cout << "--------------------------------------- " << norm (&residual[0], residual.size()) << std::endl;
		}
	}	

	// evaluation --------------------------------------------------------------

	T evaluate_individual (const Solution<T>& id, const std::vector<T>& target,
		const std::vector<DB_entry<T>* >& database) {
		std::vector<T> values (target.size (), 0);

		Forecast<T>::compute(id, database, values, target, OptimizerI<T>::parameters);
		normalize2(&values[0], &values[0], values.size ());
		// int mpos = 0;
		// T max = maximum(&target[0], target.size (), mpos);
		// scale(&values[0], &values[0], values.size (), max);
		

		T s = 0; 
		for (unsigned i = 0; i < target.size(); ++i) {
			T diff = values[i] - target[i];
			if (diff >= 0) s += OptimizerI<T>::parameters->positive_penalization *  diff;
 			else s +=  OptimizerI<T>::parameters->negative_penalization * fabs (diff);
		}
		return s;

		// return edistance<T>(&values[0], &target[0], target.size ());
	}

	T evaluate_population (std::vector<Solution<T> >& population, 
		const std::vector<T>& target, const std::vector<DB_entry<T>* >& database) {
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
		std::vector<Solution<T>>& old_pop,
		std::vector<Solution<T>>& new_pop, unsigned n_individuals, T total_fitness,
		T crossover_rate, T mutation_rate, T sparsity,
		const std::vector<std::string>& orchestra, 
		std::map<std::string, std::vector<int> >& instruments) {

		while (new_pop.size () < n_individuals) {
			Solution<T> parent_a = select_parent(old_pop, total_fitness);
			Solution<T> parent_b = select_parent(old_pop, total_fitness);

			// for (unsigned i = 0; i <parent_a.indices.size (); ++i) {
			// 	std::cout << parent_a.indices[i] << " ";
			// }
			// std::cout << std::endl << "-------------" << std::endl;

			// for (unsigned i = 0; i <parent_b.indices.size (); ++i) {
			// 	std::cout << parent_b.indices[i] << " ";
			// }
			// std::cout << std::endl;
			
			Solution<T> offspring1, offspring2;
			crossover_parents (offspring1, offspring2, parent_a, parent_b, 
				crossover_rate);
			
			mutate_individual (model, offspring1, mutation_rate);
			mutate_individual (model, offspring2, mutation_rate);

			apply_sparsity(offspring1, sparsity);
			apply_sparsity(offspring2, sparsity);

			// new_pop.push_back(parent_a);
			// new_pop.push_back(parent_b);
			
			new_pop.push_back(offspring1);
			new_pop.push_back(offspring2);
		}

		for (typename std::vector<Solution<T> >::iterator it = new_pop.begin (); 
			it != new_pop.end (); /*--*/) {
			if (it->is_empty ()) {
				new_pop.erase(it);
			} else ++it;
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
			if (id.indices[i] == -1) continue; // cannot recreate instruments
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
