// utilities.h
// 


#ifndef UTILITIES_H
#define UTILITIES_H 

#include "WavFile.h"
#include "algorithms.h"
#include "tokenizer.h"
#include "fourier.h"
#include "ClassicVerb.h"

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

void extract_symbols (DB_entry& e) {
	std::string file = removePath(e.file);
	file = removeExtension(file);

	tokenize (file, e.symbols, "-"); // instr technique note dynamics

	while (e.symbols.size () < 4) { // add missing symbols (if needed)
		e.symbols.push_back ("N");
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
	if (database.size () != 0) {
		if (database[0].features.size () != ncoeff) {
			throw std::runtime_error ("incompatible feature size among databases");
		}
	}

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

void apply_filters (const std::vector<DB_entry>& database, 
	std::map<std::string, int>& notes, const std::vector<std::string>& styles,
	const std::vector<std::string>& dynamics,
	std::vector<DB_entry>& outdb) {

	for (unsigned j = 0; j < database.size (); ++j) {
		bool note_check = notes.size () == 0 ? true : false;
		bool style_check = styles.size () == 0 ? true : false;
		bool dynamics_check = dynamics.size () == 0 ? true : false;

		for (std::map<std::string, int>::iterator i = notes.begin(); i != notes.end (); ++i) {
			if (database[j].symbols[2] == i->first) {
				note_check = true;
				break;
			}
		}

		for (unsigned i = 0; i < styles.size (); ++i) {
			if (database[j].symbols[1] == styles[i]) {
				style_check = true;
				break;
			}
		}

		for (unsigned i = 0; i < dynamics.size (); ++i) {
			if (database[j].symbols[3] == dynamics[i]) {
				dynamics_check = true;
				break;
			}
		}

		if (note_check && style_check && dynamics_check) {
			outdb.push_back(database[j]);
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

float cents_to_ratio (int cents) {
	float c = cents;
	c /= 1200.;
	return std::pow (2., c);
}
	
inline bool file_exists (const std::string& name) {
    std::ifstream f(name.c_str());
    return f.good();
}

void create_sound_mix (const std::vector<std::string>& files, 
	const std::vector<std::string>& sound_paths, 
	const std::vector<float>& ratios, 
	const std::vector<float>& pans, const char* outfile,
	float t60, const std::vector<float>& dry_wet) {
	std::vector <float*> pointers;
	std::vector <int> lengths;

	for (int i = 0; i < files.size (); ++i) {
		std::string full_name;
	            
        bool found = false;
        for (unsigned j = 0; j < sound_paths.size (); ++j) {
        	std::stringstream snd;
       		snd << sound_paths[j] << files[i];
       		full_name = snd.str ();

			if (file_exists (snd.str())) {
				
				found = true;
				break;
			}
		}

		if (!found) {
			std::stringstream msg;
			msg << "file " << full_name << " cannot be found";
			throw std::runtime_error (msg.str ());
		}
		
		WavInFile in (full_name.c_str ()); // raises exception on error
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

	int revSamples = (int) (44100. * t60);

	int maxPos = 0;
	int maxLen = maximum (&lengths[0], lengths.size (), maxPos);
	float* mix = new float[(maxLen + revSamples) * 2];
	memset (mix, 0, sizeof(float) * (maxLen + revSamples) * 2);

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

	if (dry_wet[1] != 0) { // skip computing if all dry
		float* left = new float[(maxLen + revSamples)];
		float* right = new float[(maxLen + revSamples)];
		memset(left, 0, (maxLen + revSamples) * sizeof(float));
		memset(right, 0, (maxLen + revSamples) * sizeof(float));

		deinterleave(mix, left, right, (maxLen + revSamples));
		ClassicVerb<float> cl(44100, (maxLen + revSamples), 6, 1, 0);
		cl.t60(t60);
		cl.gains(dry_wet[0], 0, dry_wet[1]);
		ClassicVerb<float> cr(44100, (maxLen + revSamples), 6, 1, 23);
		cr.t60(t60);
		cr.gains(dry_wet[0], 0, dry_wet[1]);

		cl.process(left, left, (maxLen + revSamples));
		cr.process(right, right, (maxLen + revSamples));

		interleave(mix, left, right, (maxLen + revSamples));			
		delete [] left;
		delete [] right;
	}

	WavOutFile out(outfile, 44100, 16, 2);
	out.write(mix, (maxLen + revSamples) * 2); 

	delete [] mix;
	for (unsigned i = 0; i < pointers.size (); ++i) {
		delete [] pointers[i];
	}
}	

#endif	// UTILITIES_H 

// EOF
