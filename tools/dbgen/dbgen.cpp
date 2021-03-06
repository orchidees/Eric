// dbgen.cpp
// 

#include "utilities.h"
#include "analysis.h"
#include "config.h"
#include "Callback.h"

#include <stdexcept>
#include <iostream>
#include <ctime>

using namespace std;

// (0. read all files of a folder, compute features and save a text file)


void notifier (const char* msg, void* data) {
    cout << msg << endl;
    cout.flush ();
}

int main (int argc, char* argv[]) {
    srand (time (NULL));
    
    cout << "[orchidea, ver. " << ORCHIDEA_VERSION_MAJOR << "." << 
        ORCHIDEA_VERSION_MINOR << "]" << endl << endl;
	cout << "feature analysis tool" << endl;
	cout << "(c) 2018, www.carminecella.com" << endl << endl;

	try {
        if (argc != 7) {
            throw runtime_error("syntax is 'dbgen path dbfile.txt feature_type bsize hopsize ncoeff'" \
                "\n\nwhere feature_type = [spectrum | logspec | specpeaks | specenv | mfcc | moments]\n");
        }

        ofstream out (argv[2]);
        if (!out.good ()) {
        	throw runtime_error ("cannot create output file");
        }
        

        int bsize = atol (argv[4]);
        if (bsize < 2 || ((((~bsize + 1) & bsize) != bsize))) {
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
        
        cout << "parsing source folder...";
    	vector<string> files;
    	listdir (argv[1], argv[1], files); 
    	cout << "done" << endl << endl;

    	clock_t tic = clock ();
        vector<string> err_files;
        Callback c;
        c.notifier = notifier;
        c.user_data = nullptr;
        make_db<float>(argv[1], files, out, bsize, hopsize, ncoeff, argv[3], 
            err_files, &c);
    	clock_t toc = clock (); 

        if (err_files.size ()) {
            std::stringstream errors;
            cout << endl << "** warning: " << err_files.size () << " file(s) could not be analysed ** " << endl;
        }

    	cout << endl << "analysis performed in " << ((float) toc - tic) / CLOCKS_PER_SEC << " sec." << endl;

    	out.close ();
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

