// orchestrate.cpp
//

#include "SoundTarget.h"
#include "Source.h"
#include "Parameters.h"
#include "GeneticOrchestra.h"
#include "Session.h" 
#include "forecasts.h"
#include "analysis.h"
#include "utilities.h"
#include "constants.h"
#include "config.h" 
#include "segmentations.h"
#include "OrchestrationModel.h"
#include "ConnectionModel.h"
#include "connections.h"

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

// TODO:  quantized tuning,
//	     dynamic symbolic constraints,
//       filter by octave,
//		 joint optimization

// IDEAS: NMF decomposition for temporality, self-similarity matrix, sound-types

// OTHER: AbstractAnalysis, StaticSpectralFeatures,  Matrix

int main (int argc, char* argv[]) {
	srand (time (NULL));

	cout << "[orchidea, ver. " << ORCHIDEA_VERSION_MAJOR << "." << 
		ORCHIDEA_VERSION_MINOR << "]" << endl << endl;
	cout << "assisted orchestration tool" << endl;
	cout << "(c) 2018, www.carminecella.com" << endl << endl;	

    try {
		if (argc != 3) {
			throw runtime_error("syntax is 'orchidea target.wav config.txt");
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

		// target --------------------------------------------------------------
		cout << "analysing target........ ";  cout.flush ();
		SoundTarget<float, FluxSegmentation> target (argv[1], &source, &params);
		cout << "done (" << target.segments.size () << " segments)" << endl;

		GeneticOrchestra<float, AdditiveForecast> ga (&params);
		Session<float, ClosestSolutions> session (&source, &params, &ga);
		vector<OrchestrationModel<float> > orchestrations;	
		cout << "searching............... "; cout.flush ();
		session.orchestrate(target, orchestrations);
		cout << "done" << endl;

		ConnectionModel<float> connection;
		cout << "connecting.............. "; cout.flush ();
		session.connect (orchestrations, connection);
		cout << "done" << endl;		

		// export -----------------------------------------------------------
		for (unsigned i = 0; i < orchestrations.size (); ++i) {
			cout << endl << "[SEGMENT " << i << "]" << endl;

			cout << "detected notes.......... ";
			print_coll<int> (cout, orchestrations[i].segment->notes, 25);
			cout << endl;

			stringstream prefix;
			prefix << "target_" << setw (3) << setfill('0') << i << "_";
			std::stringstream fit_name;
			fit_name << prefix.str () << "fitness.txt";			
			save_vector<float> (fit_name.str ().c_str (), orchestrations[i].fitness);
	
			if (orchestrations[i].solutions.size ()) {
				std::stringstream tar_name;
				tar_name << prefix.str () << "features.txt";
				save_vector(tar_name.str ().c_str (), orchestrations[i].segment->features);

				AdditiveForecast<float>::compute(orchestrations[i].solutions[0], 
					orchestrations[i].database, 
					orchestrations[i].best_forecast, orchestrations[i].segment->features,
					&params);
				normalize2(&orchestrations[i].best_forecast[0], 
					&orchestrations[i].best_forecast[0], 
					orchestrations[i].best_forecast.size());

				std::stringstream best_name;
				best_name << prefix.str () << "best_forecast.txt";							
				save_vector(best_name.str ().c_str (), orchestrations[i].best_forecast);
				cout << "best solution........... ";
				orchestrations[i].solutions[0].dump (cout, orchestrations[i].database, 25); // ranked first
				cout << endl;
			}

			if (params.export_solutions > 0) {		
				cout << "saving best solutions... "; cout.flush ();
				orchestrations[i].export_solutions(prefix.str ());
				cout << "done" << endl;
			}
		}


		cout << "saving connection....... "; cout.flush ();
		connection.export_solutions("");
		cout << "done" << endl;

    } catch (exception& e) {
        cout << "Error: " << e.what () << endl;
    } catch (...) {
        cout << "Fatal error: unknown exception" << endl;
    }
    return 0;
}

// EOF

