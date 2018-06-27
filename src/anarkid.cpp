// anarkid.cpp
//

#include "Target.h"
#include "Source.h"
#include "Parameters.h"
#include "GeneticOrchestra.h"
#include "Session.h"
#include "forecasts.h"
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
//       features multiple con pesi, filtro ottave

// IDEE: NMF per scomposizione / temporalità; self-similarity matrix

// AbstractAnalysis, StaticSpectralFeatures,  Matrix

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
		if (source.others.size ()) {
	 		cout << "others.................. ";
			print_coll<int> (cout, source.others, 25);
			cout << endl;
		}
		// ga ------------------------------------------------------------------
		GeneticOrchestra<float, AdditiveForecast> ga (&params);

		// target --------------------------------------------------------------
		cout << "analysing target........ ";  cout.flush ();
		Target<float> target (argv[1], &source, &params);
		cout << "done (" << target.segments.size () << " segments)" << endl;

		for (unsigned i = 0; i < target.segments.size (); ++i) {
			std::stringstream prefix;
			prefix << "target_" << setw(3) << setfill('0') << i << "_";
			cout << endl << "[TARGET " << i << "]" << std::endl;

			std::stringstream target_name;
			target_name << prefix.str () << "features.txt";
			save_vector<float> (target_name.str ().c_str (), target.segments[i].features);			
		
			if (params.partials_filtering) {			
				cout << "target pitches.......... ";
				print_coll<int> (cout, target.segments[i].notes, 25);
				cout << endl;
			}

			Session<float> session (&source, &params, &ga);
			
			cout << "searching............... "; cout.flush ();
			
			OrchestrationModel<float> model(&params);
			session.make_model (target.segments[i], model);
			float max_fit = session.orchestrate (model);
			cout << "done" << endl;

			// export -----------------------------------------------------------
			std::stringstream fit_name;
			fit_name << prefix.str () << "fitness.txt";			
			save_vector<float> (fit_name.str ().c_str (), model.fitness);
			cout << "best fitness............ " << max_fit << " (epoch " << 
				ga.best_epoch << ", " << model.solutions.size () << " individuals)" << endl;
		
			if (model.solutions.size ()) {
				AdditiveForecast<float>::compute(model.solutions[0], model.database, 
					model.best_forecast, model.segment->features, &params);
				normalize2(&model.best_forecast[0], &model.best_forecast[0], 
					model.best_forecast.size());

				std::stringstream best_name;
				best_name << prefix.str () << "best_forecast.txt";							
				save_vector(best_name.str ().c_str (), model.best_forecast);
				cout << "best solution........... ";
				model.solutions[0].dump (cout, model.database, 25); // ranked first
				cout << endl;
			}

			if (params.export_solutions > 0) {		
				cout << "saving best solutions... "; cout.flush ();
				model.export_solutions(prefix.str ());
				cout << "done" << endl;
			}
		}
    } catch (exception& e) {
        cout << "Error: " << e.what () << endl;
    } catch (...) {
        cout << "Fatal error: unknown exception" << endl;
    }
    return 0;
}

// EOF

