// makedb.cpp
// 

#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>

#include <dirent.h>

using namespace std;

// (0. read all files of a folder, compute MFCC and save a text file)

void listdir(const char *name, int indent) {
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(name))) return;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char path[1024];
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
            printf("%*s[%s]\n", indent, "", entry->d_name);
            listdir(path, indent + 2);
        } else {
            printf("%*s- %s\n", indent, "", entry->d_name);
        }
    }
    closedir(dir);
}

int main (int argc, char* argv[]) {
	try {
    	std::vector<string> v;
    	listdir (argv[1], 0);

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

