// dbquery.cpp
// 

#include "config.h"
#include "Parameters.h"
#include "Source.h"

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
	cout << "database query tool" << endl;
	cout << "(c) 2018, www.carminecella.com" << endl << endl;

	try {
        if (argc < 3) {
            throw runtime_error("syntax is 'dbquery query dbfile1 dbfile2 ...'\n\n" \
            	"where query is composed as follows:\n"\
            	"list [instruments|styles|pitches|dynamics|others]\n" \
            	"search regexp\n" \
            	"\twhere regexp can be [c|.|^|$|*]\n"\
            	"\t\tc matches any literal character c\n" \
            	"\t\t. matches any single character\n" \
            	"\t\t^ matches the beginning of the input string\n" \
            	"\t\t$ matches the end of the input string\n" \
            	"\t\t* matches zero or more occurences of the previous character\n" \
            	"\t eg. search .*Fl.*4.*pp retrieves all flutes in octave 4 playing pianissimo\n");
        }

        Parameters<float> params;
        for (int i = 2; i < argc; ++i) {
        	params.db_files.push_back (argv[i]);
        }

        Source<float> source (&params);
        vector<string> results;
        source.query (argv[1], results);

        for (unsigned i = 0; i < results.size (); ++i) {
        	cout << results[i] << endl;
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

