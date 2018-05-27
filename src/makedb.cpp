// makedb.cpp
// 

#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>

#include <dirent.h>

using namespace std;

// (0. read all files of a folder, compute MFCC and save a text file)

bool readDirectory (const string &directoryLocation, vector<string>& result) {
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(directoryLocation.c_str())) == NULL)   {
        return false;
    }

    while ((ent = readdir(dir)) != NULL)   {
        string entry( ent->d_name );
        result.push_back( entry );
    }

    if (closedir(dir) != 0)   {
    	return false;
    }

    return true;
}


int main (int argc, char* argv[]) {
	try {

    	std::vector<string> v;
    	readDirectory(argv[1], v);
    	for (unsigned i = 0; i < v.size (); ++i) {
    		cout << v[i] << endl;
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

