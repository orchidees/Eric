// cpp_driver.cpp
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

#include <stdexcept>
#include <iostream>

using namespace std;

int main (int argc, char* argv[]) {
	try {
		cout << "[orchidea, ver. " << ORCHIDEA_VERSION_MAJOR << "." << 
		ORCHIDEA_VERSION_MINOR << "]" << endl << endl;
		cout << "C++ API test driver" << endl;
		cout << "(c) 2018, www.carminecella.com" << endl << endl;	

		if (argc != 3) {
			throw runtime_error ("syntax is 'cpp_driver target configuration");
		}

		Parameters<float> params (argv[2]);
		Source<float> source (&params);
		SoundTarget<float, FluxSegmentation> target (argv[1], &source, &params);
		GeneticOrchestra<float, AdditiveForecast, ClosestSolutions> ga (&params);
		Session<float, ClosestSolutions> session (&source, &params, &ga);
		ConnectionModel<float> connection;

		vector<OrchestrationModel<float> > orchestrations;	

		session.orchestrate (target, orchestrations);
		session.connect (orchestrations, connection);

		connection.export_solutions("");
	}
	catch (exception& e) {
		cout << "Error: " << e.what () << endl;
	}
	catch (...) {
		cout << "Fatal error: unknown exception" << endl;
	}
	return 0;
}

// EOF

