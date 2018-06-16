// anarkid.cpp
//

#include "Target.h"
#include "Source.h"
#include "Parameters.h"
#include "StandardGA.h"
#include "analysis.h"
#include "utilities.h"
#include "constants.h"
#include "solutions.h"

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
			//print_coll(cout, target.notes, 25);
			cout << endl;
		}

		// pfilt  --------------------------------------------------------------
		cout << "filtering database...... ";  cout.flush ();
		source.apply_filters (target.notes);
		cout << "done (" << source.database.size () << " entries)" << endl;

		// prepare search ------------------------------------------------------
		cout << "preparing search........ ";  cout.flush ();
		source.setup_orchestra();
		cout << "done" << endl;
		
		// ga ------------------------------------------------------------------
		StandardGA<float> ga (&source, &params);
		
		vector<Solution<float> > solutions;
		cout << "searching............... "; cout.flush ();
		float max_fit = ga.search(target, solutions);
		cout << "done" << endl;

		ofstream fit ("fitness.txt");
		fit << "[";
		for (unsigned i = 0; i < ga.fitness.size (); ++i) {
			fit << ga.fitness[i] << " ";
		}
		fit << "]" << endl;
		fit.close ();

		// export --------------------------------------------------------------				
		Solution<float> best = get_best_solution<float>(solutions);
		cout << "best fitness............ " << max_fit << " (epoch " << ga.best_epoch << ", "
			<< solutions.size () << " individuals)" << endl;
		
		cout << "best solution........... ";
		unsigned n_instruments = source.actual_orchestra.size ();
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

			if (params.export_solutions < solutions.size ()) solutions.resize(params.export_solutions);
			export_solutions(solutions, source.database, params, target.notes, 
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

