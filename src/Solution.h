// Solution.h
// 

#ifndef SOLUTION_H
#define SOLUTION_H 

#include "Segment.h"
#include "Source.h"
#include "Parameters.h"

#include <vector>
#include <string>
#include <fstream>

template <typename T>
struct Solution {
	std::vector<int> indices;
	T fitness;
	bool operator< (const Solution<T>& rhs) const {
		return this->fitness < rhs.fitness;
	}
	bool is_empty () {
		int scount = 0; 
		for (unsigned j = 0; j < indices.size (); ++j) {
			if (indices[j] == -1) ++scount;
		}
		return scount == indices.size ();
	}	

	void save (const char* wav_name, std::ostream& summary, 
		Segment<T>* segment,
		Parameters<T>* parameters,
		const std::vector<DB_entry<T>* >& database) {
		std::vector<T> ratios;
		std::vector<std::string> files;
		std::vector<T> pans;
			

		for (unsigned j = 0; j < indices.size (); ++j) {
			if (indices[j] == -1) {
				summary << "-" << std::endl;
				continue; // silent instrument
			}	

			DB_entry<float>* d = database[indices[j]];
			files.push_back(d->file);
			if ( parameters->partials_filtering > 0) {
				T r = cents_to_ratio<T> (segment->notes[d->symbols[2]]);
				ratios.push_back (r);
			} else ratios.push_back (1.);

			if (d->symbols[0].find ("Fl") != std::string::npos)pans.push_back (.5);
			else if (d->symbols[0].find ("Picc") != std::string::npos)pans.push_back (.5);
			else if (d->symbols[0].find ("Acc") != std::string::npos) pans.push_back(.3);
			else if (d->symbols[0].find ("ASax") != std::string::npos) pans.push_back(.7);
			else if (d->symbols[0].find ("Ob") != std::string::npos) pans.push_back(.6);
			else if (d->symbols[0].find ("Cl") != std::string::npos) pans.push_back(.4);
			else if (d->symbols[0].find ("Bn") != std::string::npos) pans.push_back(.55);
			else if (d->symbols[0].find ("Hn") != std::string::npos) pans.push_back(.3);
			else if (d->symbols[0].find ("Tp") != std::string::npos) pans.push_back(.4);
			else if (d->symbols[0].find ("Tbn") != std::string::npos) pans.push_back(.55);
			else if (d->symbols[0].find ("BT") != std::string::npos) pans.push_back(.65);
			else if (d->symbols[0].find ("Hp") != std::string::npos) pans.push_back(.3);
			else if (d->symbols[0].find ("Vl") != std::string::npos) pans.push_back(.2);
			else if (d->symbols[0].find ("Va") != std::string::npos) pans.push_back(.55);
			else if (d->symbols[0].find ("Vc") != std::string::npos) pans.push_back(.8);
			else if (d->symbols[0].find ("Cb") != std::string::npos) pans.push_back(.7);
			else pans.push_back(.5);

			for (unsigned z = 0; z < d->symbols.size (); ++z) {
				summary << d->symbols[z] << " ";	
			}
			summary << d->file << std::endl;
		}

		create_sound_mix(files,  parameters->sound_paths, ratios, pans, segment->length,
			wav_name,  parameters->t60,  parameters->dry_wet);
		summary << std::endl;
	}	


	std::ostream& dump (std::ostream& out, 
		const std::vector<DB_entry<T>* >& database,
		int offset) {
		unsigned n_instruments = indices.size ();
		for (unsigned i = 0; i < n_instruments; ++i) {
			if (i != 0) for (unsigned i = 0; i < offset; ++i) out << " ";
			if (indices[i] == -1) {
				out << "-" << std::endl;
				continue;
			}
			for (unsigned h = 0; h < database[indices[i]]->symbols.size (); ++h) {
				out << database[indices[i]]->symbols[h] << "\t";
			}	
			out << std::endl;
		}

		return out;
	}	
	
};

template <typename T>
struct Comp{
    Comp(const std::vector<T>& v ) : _v(v) {}
    bool operator ()(int a, int b) {  
    	return _v[a] > _v[b]; 
    }
    const std::vector<T>& _v;
};

#endif	// SOLUTION_H 

// EOF
