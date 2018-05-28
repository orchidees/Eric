// makedb.cpp
// 

#include "utilities.h"
#include "analysis.h"

#include <stdexcept>
#include <iostream>
#include <ctime>

using namespace std;

// (0. read all files of a folder, compute MFCC and save a text file)

const int BSIZE = 1024;
const int HOPSIZE = 512;
const int NUM_FEATURES = BSIZE / 4;

int main (int argc, char* argv[]) {
	cout << "[makedb, ver. 0.1]" << endl << endl;
	cout << "feature analysis for anarkid" << endl;
	cout << "(c) 2018, www.carminecella.com" << endl << endl;

	try {
        if (argc != 3) {
            throw runtime_error("syntax is 'makedb path dbfile.txt'");
        }

        ofstream out (argv[2]);
        if (!out.good ()) {
        	throw runtime_error ("cannot create output file");
        }

        cout << "parsing source folder...";
    	std::vector<string> files;
    	listdir (argv[1], argv[1], files);
    	cout << "done" << endl << endl;

    	ofstream errs ("errors.txt");
    	clock_t tic = clock ();
    	for (unsigned i = 0; i < files.size (); ++i) {    		
    		if (files[i].find (".wav") != string::npos) {
    			cout << "(" << i << "/" << files.size () << ") analysing " << files[i] << "...";
    			cout.flush();
    			try {
    				vector<float> features;
    				stringstream fullname;
    				fullname << argv[1] << files[i];
    				compute_features (fullname.str ().c_str (), features, 
    					BSIZE, HOPSIZE, NUM_FEATURES);	

    				out << files[i] << " ";
					for (int i = 0; i < NUM_FEATURES; ++i) {
						out << features[i] << " ";
					}
    				out << endl;
    				out.flush ();
    			} catch (exception& e) {
    				errs << files[i] << endl;
    				cout << e.what () << endl;
    			}
    			cout << "done" << endl;
    		}
    	}
    	clock_t toc = clock ();

    	cout << endl << "analysis performed in " << ((float) toc - tic) / CLOCKS_PER_SEC << " sec." << endl;

    	out.close ();
    	errs.close ();
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

