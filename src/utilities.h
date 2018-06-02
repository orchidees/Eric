// utilities.h
// 


#ifndef UTILITIES_H
#define UTILITIES_H 

#include "WavFile.h"
#include "BMP24.h"
#include "algorithms.h"
#include "tokenizer.h"
#include "FFT.h"

#include <dirent.h>

#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <stdexcept>
#include <iostream>
#include <map>
#include <deque>

struct DB_entry {
	std::string file;
	std::vector<float> features;
	std::deque<std::string> symbols;
};

template <typename T>
struct Config {
	std::string db_file;
	std::string sound_path;
	std::vector<std::string> orchestra;
	int pop_size;
	int max_epochs;
	T xover_rate;
	T mutation_rate;
	T sparsity;
	int partials_window;
	T partials_filtering;
	int export_solutions;
};

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
        } else if (tokens[0] == "orchestra") {
        	for (unsigned i = 1; i < tokens.size (); ++i) {
        		p->orchestra.push_back (tokens[i]);
        	}
        } else if (tokens[0] == "pop_size") {
        	p->pop_size = atol (tokens[1].c_str ());
        } else if (tokens[0] == "max_epochs") {
        	p->max_epochs = atol (tokens[1].c_str ());
        } else if (tokens[0] == "xover_rate") {
        	p->xover_rate = atof (tokens[1].c_str ());
        } else if (tokens[0] == "mutation_rate") {
        	p->mutation_rate = atof (tokens[1].c_str ());
        } else if (tokens[0] == "sparsity") {
        	p->sparsity = atof (tokens[1].c_str ());
        } else if (tokens[0] == "partials_window") {
        	p->partials_window = atol (tokens[1].c_str ());
        } else if (tokens[0] == "partials_filtering") {
        	p->partials_filtering = atof (tokens[1].c_str ());
        } else if (tokens[0] == "export_solutions") {
        	p->export_solutions = atol (tokens[1].c_str ());
        } else {
            std::stringstream err;
            err << "invalid token in configuration file at line " << line;
            throw std::runtime_error (err.str ());
        }
    }

	if (p->orchestra.size() <= 0) {
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

void extract_symbols (DB_entry& e) {
	std::string file = removePath(e.file);
	file = removeExtension(file);

	tokenize (file, e.symbols, "-"); // instr technique note dynamics

	if (e.symbols.size () < 4) {
		std::stringstream err;
		err << "invalid symbols in "  << e.file;
		throw std::runtime_error (err.str ());
	}
}

void insert_symbol (std::map<std::string, std::vector<int> >& coll,
	const std::string& key, int index) {
	std::map<std::string, std::vector<int> >::iterator it = coll.find (key);
	if (it == coll.end ()) {
		std::vector<int> d;
		d.push_back(index);
		coll[key] = d;
	} else {
		coll[key].push_back (index);
	}
}

void print_coll (std::ostream& out, std::map<std::string, std::vector<int> >& coll, 
	int offset) {
	int nl = 0;
	for (std::map<std::string, std::vector<int> >::iterator it = coll.begin ();
		it != coll.end (); ++it) {
		out << it->first << " ";
		++nl;
		if (nl == 6) {
			out << std::endl;
			for (unsigned j = 0; j < offset; ++j) out << " ";
			nl = 0;
		}
	}
}
void load_db (const char* dbfile, std::vector<DB_entry>& database, 
	int& bsize, int& hopsize, int& ncoeff, std::string& type) {
	std::ifstream db (dbfile);
	if (!db.good ()) {
		throw std::runtime_error("cannot open db file");
	}

	db >> type >> bsize >> hopsize >> ncoeff;

	int lineno = 1;
	while (!db.eof ()) {
		std::string line;
		std::getline(db, line);
		line = trim (line);
		
		if (line.size () == 0) continue;

		std::stringstream linestream;
		linestream << line;
		
		DB_entry e;
		linestream >> e.file;
		if (e.file.size () == 0) {
			std::stringstream err;
			err << "invalid filename in db at line " << lineno;
			throw std::runtime_error (err.str ());
		}

		extract_symbols (e);
		while (!linestream.eof ()) {
			std::string token;
			linestream >> token;
			float f = atof (token.c_str ());
			e.features.push_back(f);
		}

		if (e.features.size () != ncoeff) {
			std::stringstream err;
			err << "invalid number of features in db at line " << lineno;
			throw std::runtime_error (err.str ());
		}

		database.push_back(e);
		++lineno;
	}
}

void partials_filter (const std::vector<DB_entry>& database, std::map<std::string, int>& notes,
	std::vector<DB_entry>& outdb) {

	for (unsigned j = 0; j < database.size (); ++j) {
		for (std::map<std::string, int>::iterator i = notes.begin(); i != notes.end (); ++i) {
			if (database[j].symbols[2] == i->first) {
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
template <typename T>
void plot_vector (const char* name, const std::vector<T>& target, 
	unsigned width = 256, unsigned height = 256) {
	int minPos = 0;
	int maxPos = 0;
	float min = minimum(&target[0], target.size (), minPos);
	float max = maximum(&target[0], target.size (), maxPos);
	float delta = max - min;

	BMP24 t (width, height);
	t.background(127, 127, 127);

	float stretch = (float)width / (target.size ());
	for (unsigned z = 0; z < target.size (); ++z) {
		// t.line(
		// 	(int) (z * stretch), 
		// 	(int) ((float) height * (target[z] - min)) / delta, 
		// 	(int) ((z + 1) * stretch), 
		// 	(int) ((float) height * (target[z + 1] - min)) / delta, 0, 0, 127);

		t.line(
			(int) ((float) z * stretch), 
			(int) 0, 
			(int) ((float) z * stretch), 
			(int) ((float) height * (target[z] - min)) / delta, 0, 0, 127, true);		
	}
	t.grid (10, 10, 0, 0, 0);
	t.save (name);
}

// -----------------------------------------------------------------------------

float cents_to_ratio (int cents) {
	float c = cents;
	c /= 1200.;
	return std::pow (2., c);
}
	
void create_sound_mix (const std::vector<std::string>& files, 
	const char* sound_path, 
	const std::vector<float>& ratios, 
	const std::vector<float>& pans, const char* outfile) {
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
	float* mix = new float[maxLen * 2];
	memset (mix, 0, sizeof(float) * maxLen * 2);

	for (unsigned i = 0; i < pointers.size (); ++i) {
		double phase = 0;
		double incr = ratios[i];
		for (unsigned j = 0; j < lengths[i]; ++j) {
			int index = (int) phase;
			double frac = phase - index;
			if (index >= lengths[i] - 1) break;
			float sample = pointers[i][index] * (1. - frac) + pointers[i][index + 1] * frac;
			float v = (sample / pointers.size ());
			mix[2 * j] += (v * (1. - pans[i]));
			mix[2 * j  + 1] += (v * pans[i]);
			phase += incr;
			if (phase >= lengths[i]) break;
		}
	}

	WavOutFile out(outfile, 44100, 16, 2);
	out.write(mix, maxLen * 2); 

	delete [] mix;
	for (unsigned i = 0; i < pointers.size (); ++i) {
		delete [] pointers[i];
	}
}	

#endif	// UTILITIES_H 

// EOF
