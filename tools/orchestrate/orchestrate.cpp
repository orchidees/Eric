// orchestrate.cpp
//

#include "SoundTarget.h"
#include "Source.h"
#include "Parameters.h"
#include "GeneticOrchestra.h"
#include "Session.h" 
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
		
		// target --------------------------------------------------------------
		cout << "analysing target........ ";  cout.flush ();
		SoundTarget<float, FluxSegmentation> target (argv[1], &source, &params);
		cout << "done (" << target.segments.size () << " segments)" << endl;

		GeneticOrchestra<float, AdditiveForecast, ClosestSolutions> ga (&params);
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
		cout << "exporting solutions..... "; cout.flush ();
		session.export_solutions ("", orchestrations, connection);
		cout << "done" << endl << endl;		

		ofstream numsegm ("segments.txt");
		numsegm << orchestrations.size ();
		numsegm.close ();

    } catch (exception& e) {
        cout << "Error: " << e.what () << endl;
    } catch (...) {
        cout << "Fatal error: unknown exception" << endl;
    }
    return 0;
}

// EOF

