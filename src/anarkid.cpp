// anarkid.cpp
//

#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <map>

#include "analysis.h"
#include "utilities.h"

using namespace std;

const int BSIZE = 1024;
const int HOPSIZE = 512;
const int NUM_MFCC = 14;

// 1. compute MFCC of target
// 2. read text file for data in memory filename + coefficients
// 3. chromosome is sequence of random numbers from 1 to n files
// 4. mutation is +-r integer
// 5. evaluation is = some of corresponding envelopes and distance with target
// -- N instruments in solution if given, no choice for other params


int main (int argc, char* argv[]) {
    try {
		cout << "[anarkid, ver. 0.1]" << endl << endl;
		cout << "anarchist assisted orchestration" << endl;
		cout << "(c) 2018, www.carminecella.com" << endl << endl;

		if (argc != 6) {
			throw runtime_error("syntax is 'anarkid target.wav dbfile.txt xover_rate mutation_rate mutation_amplitude");
		}

		cout << "analysing target...";
		vector<float> target;
		compute_mfcc(argv[1], target, BSIZE, HOPSIZE, NUM_MFCC);
		cout << "done" << endl;

		cout << "loading database...";
		vector<db_entry> database;
		load_db (argv[2], database, NUM_MFCC);
		cout << "done" << endl;

		
		float xover_rate = atof (argv[3]);
		float mutation_rate = atof (argv[4]);
		float mutation_amplitude = atof (argv[5]);

		getchar ();

    } catch (exception& e) {
        cout << "Error: " << e.what () << endl;
    } catch (...) {
        cout << "Fatal error: unknown exception" << endl;
    }
    return 0;
}

// EOF

