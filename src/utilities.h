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

#include "WavFile.h"
#include "BMP24.h"
#include "algorithms.h"

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

template <typename T>
struct Config {
	std::string db_file;
	std::string sound_path;
	int n_instruments;
	int pop_size;
	int max_epochs;
	T xover_rate;
	T mutation_rate;
	int mutation_amp;
	T harmonic_filter;
	bool export_solutions;
};

template <typename T>
void read_config (const char* config_file, Config<T>* p) {

	std::ifstream config (config_file);
	if (!config.good ()) {
		throw std::runtime_error ("cannot open configuration file");
	}

    int line = 0;
    while (!config.eof ()) {
        std::string inp;
        std::string opcode;

        ++line;
        std::getline (config, inp, '\n');

        if (inp.size () == 0) continue;

        std::istringstream istr (inp, std::ios_base::out);

        std::vector <std::string> tokens;
        while (!istr.eof ()) {
            istr >> opcode;
            tokens.push_back (opcode);
        }

        if (tokens[0][0] == ';') continue;
        if (tokens.size () < 2) {
            std::stringstream err;
            err << "invalid syntax at line " << line;
            throw std::runtime_error (err.str ());
        }

        if (tokens[0] == "db_file") {
        	p->db_file = tokens[1];
        } else if (tokens[0] == "sound_path") {
        	p->sound_path = tokens[1];
        } else if (tokens[0] == "n_instruments") {
        	p->n_instruments = atol (tokens[1].c_str ());

        } else if (tokens[0] == "pop_size") {
        	p->pop_size = atol (tokens[1].c_str ());
        } else if (tokens[0] == "max_epochs") {
        	p->max_epochs = atol (tokens[1].c_str ());
        } else if (tokens[0] == "xover_rate") {
        	p->xover_rate = atof (tokens[1].c_str ());
        } else if (tokens[0] == "mutation_rate") {
        	p->mutation_rate = atof (tokens[1].c_str ());
        } else if (tokens[0] == "mutation_amp") {
        	p->mutation_amp = atol (tokens[1].c_str ());
        } else if (tokens[0] == "harmonic_filter") {
        	p->harmonic_filter = atof (tokens[1].c_str ());
        } else if (tokens[0] == "export_solutions") {
        	p->export_solutions = (bool) atol (tokens[1].c_str ());
        } else {
            std::stringstream err;
            err << "invalid token in configuration file at line " << line;
            throw std::runtime_error (err.str ());
        }
    }

	if (p->n_instruments <= 0) {
        throw std::runtime_error ("invalid number of instruments");
	}
	if (p->pop_size <= 0) {
        throw std::runtime_error ("invalid size for population");
	}	
	if (p->mutation_rate <= 0 || p->mutation_rate > 1 || p->xover_rate <= 0 ||
		p->xover_rate > 1) {
        throw std::runtime_error ("invalid xover or mutation rate");
	}	
}

struct db_entry {
	std::string file;
	std::vector<float> features;
};

void load_db (const char* dbfile, std::vector<db_entry>& database, 
	int& bsize, int& hopsize, int& ncoeff, std::string& type) {
	std::ifstream db (dbfile);
	if (!db.good ()) {
		throw std::runtime_error("cannot open db file");
	}

	db >> type >> bsize >> hopsize >> ncoeff;
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
	
		while (!linestream.eof ()) {
			std::string token;
			linestream >> token;
			float f = atof (token.c_str ());
			e.features.push_back(f);
		}

		if (e.features.size () != ncoeff) {
			std::cout << e.features.size () << " " << ncoeff << std::endl;
			throw std::runtime_error ("invalid number of features in db");
		}

		database.push_back(e);
	}
}

void harmonic_filter (const std::vector<db_entry>& database, std::map<std::string, int>& notes,
	std::vector<db_entry>& outdb) {

	for (unsigned j = 0; j < database.size (); ++j) {
		for (std::map<std::string, int>::iterator i = notes.begin(); i != notes.end (); ++i) {
			if (database[j].file.find (i->first) != std::string::npos) {
				outdb.push_back(database[j]);
				break;
			}
		}
	}
}
// -------------------------------------------------------------------------- //
void listdir (const char *name, const char* trailing_path, std::vector<std::string>& list) {
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

// -----------------------------------------------------------------------------
void plot_vector (const char* name, const std::vector<float>& target, 
	bool dots = false, unsigned height = 256) {
	int minPos = 0;
	int maxPos = 0;
	float min = minimum(&target[0], target.size (), minPos);
	float max = maximum(&target[0], target.size (), maxPos);
	float delta = max - min;

	BMP24 t (target.size (), height);
	t.background(127, 127, 127);

	for (unsigned z = 0; z < target.size (); ++z) {
		if (dots) {
			t.set (z, (int) ((float) height * target[z] / delta) + min, 0, 0, 0);
		} else {
			t.line(z, 0, z,(int) ((float) height * target[z] / delta) + min, 0, 0, 127, true);
		}	

	}
	t.grid (10, 10, 0, 0, 0);
	t.save (name);
}

// -----------------------------------------------------------------------------
void create_sound_mix (const std::vector<std::string>& files, 
	const char* sound_path, 
	const std::vector<float>& ratios, const char* outfile) {
	std::vector <float*> pointers;
	std::vector <int> lengths;

	for (int i = 0; i < files.size (); ++i) {
		std::stringstream snd;
		snd << sound_path << files[i];
		WavInFile in (snd.str ().c_str ()); // raises exception on error
		int sr = in.getSampleRate();
		int samples  = in.getNumSamples();
		int channels = in.getNumChannels ();
		int bits = in.getNumBits();

		if (sr != 44100) {
			throw std::runtime_error ("invalid sampling rate (must be 44100)");
		}
		if (channels > 2) {
			throw std::runtime_error ("unsupported number of channels");
		}
		if (bits != 16) {
			throw std::runtime_error ("unsupported number of bits");	
		}
		
		float* data = new float[samples * channels];
		float* right = new float[samples];
		float* left = new float[samples];

		in.read (data, samples * channels);

		if (channels == 2) {
			float* left = new float[samples];
		 	float* right = new float[samples];
			deinterleave (data, left, right, samples);
			for (unsigned i = 0; i < samples; ++i) {
				data[i] = (left[i] + right[i]) * .5;
			}		
		}

		delete [] right;
		delete [] left;
		pointers.push_back(data);
		lengths.push_back(samples * (1. / ratios[i]));
	}

	int maxPos = 0;
	int maxLen = maximum (&lengths[0], lengths.size (), maxPos);
	float* mix = new float[maxLen];
	memset (mix, 0, sizeof(float) * maxLen);

	for (unsigned i = 0; i < pointers.size (); ++i) {
		double phase = 0;
		double incr = ratios[i];
			for (unsigned j = 0; j < lengths[i]; ++j) {
			int index = (int) phase;
			double frac = phase - index;
			if (index >= lengths[i] - 1) break;
			float sample = pointers[i][index] * (1. - frac) + pointers[i][index + 1] * frac;
			mix[j] += (sample / pointers.size ());
			phase += incr;
			if (phase >= lengths[i]) break;
		}
	}

	WavOutFile out(outfile, 44100, 16, 1);
	out.write(mix, maxLen); 

	delete [] mix;
	for (unsigned i = 0; i < pointers.size (); ++i) {
		delete [] pointers[i];
	}
}	

#endif	// UTILITIES_H 

// EOF
