// utilities.h
// 


#ifndef UTILITIES_H
#define UTILITIES_H 

#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <stdexcept>
#include <iostream>
#include <map>

#include <dirent.h>

// -----------------------------------------------------------------------------
template <typename T>
void serialize (std::ostream& out , const T* data, int size) {
	for (int i = 0; i < size; ++i) {
		out.write ((char*) &data[i], sizeof (T));
	}
}

template <typename T>
void serialize (const std::string& name, const T* data, int size) {
	std::ofstream out (name.c_str (), std::ios::binary);
	if (!out.good ()) {
		std::string err = "cannot create " + name;
		throw std::runtime_error (err.c_str ());
	}
	serialize(out, data, size);
	out.close ();
}

template <typename T>
void deserialize (const std::string& name, T* data, int size) {
	std::ifstream in (name.c_str (), std::ios::binary);
	if (!in.good ()) {
		std::string err = "cannot open " + name;
		throw std::runtime_error (err.c_str ());
	}
	for (int i = 0; i < size; ++i) {
		in.read ((char*) &data[i], sizeof (T));
	}
	in.close ();
}

// -----------------------------------------------------------------------------
std::string removePath (const std::string& in) {
	size_t pos = std::string::npos;
	pos = in.find_last_of ("/");
	if (pos != std::string::npos) {
		return in.substr (pos + 1, in.size () - pos);
	} else return in;
}

std::string removeExtension (const std::string& in) {
	size_t pos = std::string::npos;
	pos = in.find_last_of (".");
	if (pos != std::string::npos) {
		return in.substr (0, pos);
	} else return in;
}

std::string trim (std::string const& source, 
	char const* delims = " \t\r\n") {
	std::string result (source);
	std::string::size_type index = result.find_last_not_of (delims);
	if (index != std::string::npos)
		result.erase (++index);
	
	index = result.find_first_not_of (delims);
	if (index != std::string::npos)
		result.erase (0, index);
	else
		result.erase ();
	return result;
}	


void erase_substring (std::string & mainStr, const std::string & toErase) {
	// Search for the substring in string
	size_t pos = mainStr.find(toErase);
 
	if (pos != std::string::npos) {
		// If found then erase it from string
		mainStr.erase(pos, toErase.length());
	}
}

// -----------------------------------------------------------------------------

struct db_entry {
	std::string file;
	std::vector<float> features;
};

void load_db (const char* dbfile, std::vector<db_entry>& database, int ncoeff) {
	std::ifstream db (dbfile);
	if (!db.good ()) {
		throw std::runtime_error("cannot open db file");
	}

	while (!db.eof ()) {
		std::string line;
		std::getline(db, line);
		line = trim (line);
		
		if (line.size () == 0) continue;

		std::stringstream linestream;
		linestream << line;
		
		db_entry e;
		linestream >> e.file;
		if (e.file.size () == 0) {
			throw std::runtime_error ("invalid file name in db");
		}
		
		std::cout << e.file << " ";
		while (!linestream.eof ()) {
			std::string token;
			linestream >> token;
			float f = atof (token.c_str ());
			e.features.push_back(f);
			std::cout << f << " ";
		}

		std::cout << std::endl;
		if (e.features.size () != ncoeff) {
			std::cout << e.features.size () << " " << ncoeff << std::endl;
			throw std::runtime_error ("invalid number of features in db");
		}

		database.push_back(e);
	}
}

// -------------------------------------------------------------------------- //
void listdir(const char *name, const char* trailing_path, std::vector<std::string>& list) {
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(name))) return;

    
    while ((entry = readdir(dir)) != NULL) {
        std::stringstream path;
        path << name << "/" << entry->d_name;

        if (entry->d_type == DT_DIR) {            
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
    
            listdir(path.str ().c_str (), trailing_path, list);
        } else {
        	std::string remove_root = path.str ();
        	std::string root_str = trailing_path;
        	erase_substring(remove_root, root_str);
            list.push_back(remove_root);
        }
    }
    closedir(dir);
}
// -----------------------------------------------------------------------------
template <typename T>	
inline void convert16to32 (const short* in, T* out, int size) {
	for (int i = 0; i < size; ++i) {
		out[i] = (T) in[i] / 32768.;
	}
}

template <typename T>
inline void convert32to16 (const T* in, short* out, int size) {
	for (int i = 0; i < size; ++i) {
		out[i] = (short) (in[i] * 32768.);
	}
}

template <typename T>
inline void interleave16to32 (const short* in, T* L, T* R, int size) {
	for (int i = 0; i < size; ++i) {
		L[i] = (T) in[i * 2] / 32767;
		R[i] = (T) in[i * 2 + 1] / 32767;
	}
}

inline void deinterleave32to16 (const float* L, const float* R, short* out, int size) {
	for (int i = 0; i < size; ++i) {
		out[2 * i] = (short) (L[i] * 32767);
		out[2 * i + 1] = (short) (R[i] * 32767);
	}
}

template <typename T>
void interleave (T* stereo, const T* l, const T* r, int n) {
	for (int i = 0; i < n; ++i) {
		stereo[2 * i] = l[i];
		stereo[2 * i + 1] = r[i];
	}
}

template <typename T>
void deinterleave (const T* stereo, T* l, T* r, int n) {
	for (int i = 0; i < n; ++i) {
		l[i] = stereo[2 * i];
		r[i] = stereo[2 * i + 1];
	}
}	

#endif	// UTILITIES_H 

// EOF
