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
