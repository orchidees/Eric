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
void save_vector (const char* file, const std::vector<T>& v) {
	std::ofstream out (file);
	if (!out.good ()) {
		throw std::runtime_error ("cannot create output file");
	}

	for (unsigned i = 0; i < v.size (); ++i) {
		out << v[i] << " ";
	}
	out.close ();
}
// -----------------------------------------------------------------------------
template <typename T>
std::ostream& print_coll (std::ostream& out, std::map<std::string, std::vector<T> >& coll, 
	int offset) {
	int nl = 0;
	for (typename std::map<std::string, std::vector<T> >::iterator it = coll.begin ();
		it != coll.end (); ++it) {
		out << it->first << " ";
		++nl;
		if (nl == 5) {
			out << std::endl;
			for (unsigned j = 0; j < offset; ++j) out << " ";
			nl = 0;
		}
	}
	return out;
}

template <typename T>
std::ostream& print_coll (std::ostream& out, std::map<std::string, T >& coll, 
	int offset) {

	std::map<std::string, std::vector<int> > remap;
	for (std::map<std::string, int>::iterator it = coll.begin ();
		it != coll.end (); ++it) {
		std::vector<int> p;
		p.push_back(it->second);
		remap[it->first] = p;
	}
	return print_coll<T>(out, remap, offset);
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

template <typename T>
T cents_to_ratio (int cents) {
	T c = cents;
	c /= 1200.;
	return std::pow (2., c);
}
	
inline bool file_exists (const std::string& name) {
    std::ifstream f(name.c_str());
    return f.good();
}

template <typename T>
void create_sound_mix (const std::vector<std::string>& files, 
	const std::vector<std::string>& sound_paths, 
	const std::vector<T>& ratios, 
	const std::vector<T>& pans, const char* outfile,
	T t60, const std::vector<T>& dry_wet) {
	std::vector <T*> pointers;
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
		
		T* data = new T[samples * channels];
		T* right = new T[samples];
		T* left = new T[samples];

		in.read (data, samples * channels);

		if (channels == 2) {
			T* left = new T[samples];
		 	T* right = new T[samples];
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
	T* mix = new T[(maxLen + revSamples) * 2];
	memset (mix, 0, sizeof(T) * (maxLen + revSamples) * 2);

	for (unsigned i = 0; i < pointers.size (); ++i) {
		double phase = 0;
		double incr = ratios[i];
		for (unsigned j = 0; j < lengths[i]; ++j) {
			int index = (int) phase;
			double frac = phase - index;
			if (index >= lengths[i] - 1) break;
			T sample = pointers[i][index] * (1. - frac) + pointers[i][index + 1] * frac;
			T v = (sample / pointers.size ());
			mix[2 * j] += (v * (1. - pans[i]));
			mix[2 * j  + 1] += (v * pans[i]);
			phase += incr;
			if (phase >= lengths[i]) break;
		}
	}

	if (dry_wet[1] != 0) { // skip computing if all dry
		T* left = new T[(maxLen + revSamples)];
		T* right = new T[(maxLen + revSamples)];
		memset(left, 0, (maxLen + revSamples) * sizeof(T));
		memset(right, 0, (maxLen + revSamples) * sizeof(T));

		deinterleave(mix, left, right, (maxLen + revSamples));
		ClassicVerb<T> cl(44100, (maxLen + revSamples), 6, 1, 0);
		cl.t60(t60);
		cl.gains(dry_wet[0], 0, dry_wet[1]);
		ClassicVerb<T> cr(44100, (maxLen + revSamples), 6, 1, 23);
		cr.t60(t60);
		cr.gains(dry_wet[0], 0, dry_wet[1]);

		cl.process(left, left, (maxLen + revSamples));
		cr.process(right, right, (maxLen + revSamples));

		interleave(mix, left, right, (maxLen + revSamples));			
		delete [] left;
		delete [] right;
	}

	scale<float>(&mix[0], &mix[0], (maxLen + revSamples) * 2, 2.);

	WavOutFile out(outfile, 44100, 16, 2);
	out.write(mix, (maxLen + revSamples) * 2); 

	delete [] mix;
	for (unsigned i = 0; i < pointers.size (); ++i) {
		delete [] pointers[i];
	}
}	

#endif	// UTILITIES_H 

// EOF
