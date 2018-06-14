// anarkid.cpp
//

#include "Target.h"
#include "Source.h"
#include "Parameters.h"
#include "analysis.h"
#include "utilities.h"
#include "constants.h"
#include "ga.h"

#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <ctime>

using namespace std;

// 1. compute MFCC of target
// 2. read text file for data in memory filename + coefficients
// 3. chromosome is sequence of random numbers from 1 to n files
// 4. mutation is +-r integer
// 5. evaluation is = sum of corresponding envelopes and distance with target

// TODO: tuning quantizzato (??),
//	     orchestrazione dinamica, constraints, regole di concatenazione

// REFACTOR: miglioramento interfaccia codice

// IDEE: NMF per scomposiione / temporalità; self-similarity matrix

// AbstractAnalysis, StaticSpectralFeatures, AbstractSource, Source, Matrix, 
// AbstractTarget, SoundTarget, AbstractOptimizer, Solution, StandardGA,
// Parameters, Session

// int main () {
// 	Parameters p;
// 	read_config (argv[1], p);
//  Source source (p);
// 	Target t (argv[2], p);
// 	Orchestrator s (p);
// 	s.search (t);
// 	s.export ("folder");

// 	return 0;
// } 

const int MAX_EQUAL_FITNESS = 15;

int main (int argc, char* argv[]) {
    try {
    	srand (time (NULL));

		cout << "[anarkid, ver. 0.1]" << endl << endl;
		cout << "anarchist assisted orchestration" << endl;
		cout << "(c) 2018, www.carminecella.com" << endl << endl;

		if (argc != 3) {
			throw runtime_error("syntax is 'anarkid target.wav config.txt");
		}

		// config --------------------------------------------------------------
		cout << "loading configuration... "; cout.flush ();
		Parameters<float> params (argv[2]);
		cout << "done" << endl;
		cout << "parameters.............. " << params.xover_rate << ", " 
			<< params.mutation_rate << ", " << params.sparsity << endl;

		// db ------------------------------------------------------------------
		cout << "loading databases....... ";  cout.flush ();
		Source<float> source  (&params);
		cout << "done (" << source.database.size () << " entries)" << endl;
		
		// symbols -------------------------------------------------------------
		cout << "instruments............. ";
		print_coll (cout, source.tot_instruments, 25);
		cout << endl;
		cout << "styles.................. ";
		print_coll (cout, source.styles, 25);
		cout << endl;
		cout << "pitches................. ";
		print_coll (cout, source.pitches, 25); 
		cout << endl;
		cout << "dynamics................ ";
		print_coll (cout, source.dynamics, 25);
		cout << endl;
 
		// target --------------------------------------------------------------
		cout << "analysing target........ ";  cout.flush ();
		Target<float> target (argv[1], &source, &params);
		cout << "done" << endl;
		if (params.partials_filtering) {			
			cout << "target pitches.......... ";
			int nl = 0;
			for (map<string, int>::iterator i = target.notes.begin(); i != target.notes.end (); ++i) {
				cout << i->first << " (" << 
					(i->second > 0 ? "+" : "") << i->second << " cents) ";
				if (nl == 3) {
					cout << endl;
					for (unsigned i = 0; i < 25; ++i) cout << " ";
					nl = 0;
				}
				++nl;
			}		
			cout << endl;
		}

		// pfilt  --------------------------------------------------------------
		cout << "filtering database...... ";  cout.flush ();
		vector<string> effective_orchestra = params.orchestra;
		map<string, vector <int> > instruments = source.tot_instruments;
		source.apply_filters (target.notes, effective_orchestra, instruments);
		cout << "done (" << source.database.size () << " entries)" << endl;

		// ga ------------------------------------------------------------------
		cout << "init population......... "; cout.flush ();
		vector<Individual> population (params.pop_size);
		gen_population (population, effective_orchestra, instruments, source.database, 
			target.features, params.pursuit);	
		cout << "done" << endl;

		float total_fitness = 0;
		vector<float> fitness;

		vector<Individual> best_pop;
		int fit_count = 0;
		float max_fit = 0;
		float old_fit = 0;
		int best_epoch = 0;
		cout << "searching............... "; cout.flush ();
		for (unsigned i = 0; i < params.max_epochs; ++i) {
			total_fitness = evaluate_population(population, target.features, 
				source.database, source.ncoeff);	

			fitness.push_back(total_fitness);

			vector<Individual> new_pop;
			gen_offspring_population(population, new_pop, params.pop_size, total_fitness,
				params.xover_rate, params.mutation_rate, params.sparsity, 
				effective_orchestra, instruments);
	
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
		cout << "done" << endl;

		ofstream fit ("fitness.txt");
		fit << "[";
		for (unsigned i = 0; i < fitness.size (); ++i) {
			fit << fitness[i] << " ";
		}
		fit << "]" << endl;
		fit.close ();

		// export --------------------------------------------------------------				
		if (best_pop.size () == 0) {
			best_pop = population;
		}

		vector<Individual> uniques;
		make_uniques(best_pop, uniques);
		evaluate_population(uniques, target.features, source.database, source.ncoeff);

		Individual best = get_best_individual(uniques);
		cout << "best fitness............ " << max_fit << " (epoch " << best_epoch << ", "
			<< uniques.size () << " individuals)" << endl;
		
		cout << "best solution........... ";
		unsigned n_instruments = effective_orchestra.size ();
		for (unsigned i = 0; i < n_instruments; ++i) {
			if (i != 0) for (unsigned i = 0; i < 25; ++i) cout << " ";
			if (best.chromosome[i] == -1) {
				cout << "-" << endl;
				continue;
			}
			for (unsigned h = 0; h < source.database[best.chromosome[i]].symbols.size (); ++h) {
				cout << source.database[best.chromosome[i]].symbols[h] << "\t";
			}
			cout << endl;
		}
		if (params.export_solutions > 0) {		
			cout << "saving best solutions... "; cout.flush ();
			std::sort (uniques.begin (), uniques.end ());
			std::reverse(uniques.begin (), uniques.end());

			if (params.export_solutions < uniques.size ()) uniques.resize(params.export_solutions);
			export_population(uniques, source.database, params, target.notes, 
				source.type, source.ncoeff);
			cout << "done" << endl;
		}

		cout << endl;	
    } catch (exception& e) {
        cout << "Error: " << e.what () << endl;
    } catch (...) {
        cout << "Fatal error: unknown exception" << endl;
    }
    return 0;
}

// EOF

