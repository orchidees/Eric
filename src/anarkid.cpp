// anarkid.cpp
//

#include "Target.h"
#include "Source.h"
#include "Parameters.h"
#include "GeneticOrchestra.h"
#include "Session.h"
#include "analysis.h"
#include "utilities.h"
#include "constants.h"
#include "config.h"

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

// IDEE: NMF per scomposiione / temporalità; self-similarity matrix

// AbstractAnalysis, StaticSpectralFeatures,  Matrix, 
// Solution 

int main (int argc, char* argv[]) {
	srand (time (NULL));

	cout << "[anarkid, ver. " << ANARKID_VERSION_MAJOR << "." << 
		ANARKID_VERSION_MINOR << "]" << endl << endl;
	cout << "anarchist assisted orchestration" << endl;
	cout << "(c) 2018, www.carminecella.com" << endl << endl;	

    try {
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
		print_coll<int> (cout, source.tot_instruments, 25);
		cout << endl;
		cout << "styles.................. ";
		print_coll<int> (cout, source.styles, 25);
		cout << endl;
		cout << "pitches................. ";
		print_coll<int> (cout, source.pitches, 25); 
		cout << endl;
		cout << "dynamics................ ";
		print_coll<int> (cout, source.dynamics, 25);
		cout << endl;
 
		// target --------------------------------------------------------------
		cout << "analysing target........ ";  cout.flush ();
		Target<float> target (argv[1], &source, &params);
		cout << "done" << endl;
		if (params.partials_filtering) {			
			cout << "target pitches.......... ";
			print_coll<int> (cout, target.notes, 25);
			cout << endl;
		}

		// ga ------------------------------------------------------------------
		GeneticOrchestra<float> ga (&params);
		Session<float> session (&source, &params, &ga);
		
		cout << "searching............... "; cout.flush ();
		vector<Solution<float> > solutions;
		float max_fit = session.orchestrate(target, solutions);
		cout << "done" << endl;

		// export --------------------------------------------------------------				
		save_vector<float> ("fitness.txt", ga.fitness);
		cout << "best fitness............ " << max_fit << " (epoch " << 
			ga.best_epoch << ", " << solutions.size () << " individuals)" << endl;
		
		if (solutions.size ()) {
			cout << "best solution........... ";
			session.dump_solution(cout, solutions[0], 25);
			cout << endl;
		}

		if (params.export_solutions > 0) {		
			cout << "saving best solutions... "; cout.flush ();
			session.export_solutions(solutions);
			cout << "done" << endl;
		}
    } catch (exception& e) {
        cout << "Error: " << e.what () << endl;
    } catch (...) {
        cout << "Fatal error: unknown exception" << endl;
    }
    return 0;
}

// EOF

