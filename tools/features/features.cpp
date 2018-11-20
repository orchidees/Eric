// features.cpp
// 

#include "analysis.h"
#include "config.h"

#include <stdexcept>
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main (int argc, char* argv[]) {
    srand (time (NULL));
    
    cout << "[orchidea, ver. " << ORCHIDEA_VERSION_MAJOR << "." << 
        ORCHIDEA_VERSION_MINOR << "]" << endl << endl;
	cout << "display a standard set of features on a file" << endl;
	cout << "(c) 2018, www.carminecella.com" << endl << endl;

	try {
        if (argc < 4) {
            throw runtime_error("syntax is 'features fftsize hopsize file1 file2 ...");
        }
      

        int bsize = atol (argv[1]);
        if (bsize < 2 || ((((~bsize + 1) & bsize) != bsize))) {
            throw runtime_error("invalid value for bsize");
        }

        int hopsize = atol (argv[2]);
        if (hopsize <= 0 || hopsize > bsize) {
            throw runtime_error("invalid value for hopsize");
        }
        
        for (int i = 3; i < argc; ++i) {
            vector<float> features;
            compute_features<float> (argv[i], features, bsize, hopsize, 4, "moments");
            cout << argv[i] << ": ";
            for (unsigned k = 0; k < 4; ++k) cout << setw(8) << features[k]; 
            cout << endl;
        }
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

