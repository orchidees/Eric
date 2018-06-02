// makedb.cpp
// 

#include "utilities.h"
#include "analysis.h"

#include <stdexcept>
#include <iostream>
#include <ctime>

using namespace std;

// (0. read all files of a folder, compute MFCC and save a text file)

int main (int argc, char* argv[]) {
    srand (time (NULL));
    
	cout << "[makedb, ver. 0.1]" << endl << endl;
	cout << "feature analysis for anarkid" << endl;
	cout << "(c) 2018, www.carminecella.com" << endl << endl;

	try {
        if (argc != 7) {
            throw runtime_error("syntax is 'makedb path dbfile.txt feature_type bsize hopsize ncoeff'" \
                "\n\nwhere feature_type = [spectrum | specenv | mfcc]\n");
        }

        ofstream out (argv[2]);
        if (!out.good ()) {
        	throw runtime_error ("cannot create output file");
        }
        

        int bsize = atol (argv[4]);
        if (bsize <= 0) {
            throw runtime_error("invalid value for bsize");
        }

        int hopsize = atol (argv[5]);
        if (hopsize <= 0 || hopsize > bsize) {
            throw runtime_error("invalid value for hopsize");
        }

        int ncoeff = atol (argv[6]);
        if (ncoeff <= 0 || ncoeff > bsize / 2) {
            throw runtime_error("invalid number of coefficients requested");
        }
        
        out << argv[3] << " " << bsize << " " << hopsize << " " << ncoeff << endl;

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
    					bsize, hopsize, ncoeff, (string) (argv[3]));	

    				out << files[i] << " ";
					for (int i = 0; i < features.size (); ++i) {
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

