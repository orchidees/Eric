// StandardGA.h
// 


#ifndef STANDARDGA_H
#define STANDARDGA_H 

#include "utilities.h"

#include <map>
#include <string>
#include <vector>
#include <deque>

struct Comp{
    Comp( const std::vector<float>& v ) : _v(v) {}
    bool operator ()(int a, int b) {  
    	return _v[a] > _v[b]; 
    }
    const std::vector<float>& _v;
};

// -----------------------------------------------------------------------------

template <typename T>
struct Individual {
	std::vector<int> chromosome;
	float fitness;
	bool operator< (const Individual& rhs) const {
		return this->fitness < rhs.fitness;
	}
};

template <typename T>
struct StandardGA {
	std::vector<std::string> orchestra;
	std::map<std::string, std::vector<int> > instruments;
	std::vector<int> population;
private:
	void gen_random_chromosome (std::vector<int>& f) {
	 	f.resize(orchestra.size ());	
		for (unsigned i = 0; i < f.size (); ++i) {
			std::string inum = orchestra[i];

			std::deque<std::string> res;
			if (orchestra[i].find ("|") != std::string::npos) { // doublings
				tokenize(orchestra[i], res, "|");
				int p = rand () % res.size ();
				inum = res[p];
			}
			
			unsigned p = rand () % instruments[inum].size();		
			f[i] = instruments[inum][p];
		}
	}
	void gen_pursuit_chromosome (std::vector<int>& f, 
		const std::vector<std::string>& orchestra, 
		std::map<std::string, std::vector<int> >& instruments,
		const std::vector<DB_entry<float> >& database,
		const std::vector<float>& target,
		int kth) {

		f.resize(orchestra.size ());	

		std::vector<float> residual (target.size ());
		for (unsigned i = 0; i < target.size (); ++i) {
			residual[i] = target[i];
		}

		for (unsigned i = 0; i < f.size (); ++i) {		
			// std::cout << "i = " << i << std::endl;
			std::string inum = orchestra[i];

			std::deque<std::string> res;
			if (orchestra[i].find ("|") != std::string::npos) { // doublings
				tokenize(orchestra[i], res, "|");
				int p = rand () % res.size ();
				inum = res[p];
			}

			std::vector<float> moduli;
			std::vector<float> projections;
			std::vector<float> indexes;
			for (unsigned k = 0; k < instruments[inum].size (); ++k) {
				DB_entry<float> e = database[instruments[inum][k]];
				// std::vector<float> nfeat (e.features);
				// normalize(&nfeat[0], &nfeat[0], nfeat.size());

				float R = norm (&e.features[0], e.features.size()); // regularization
				float d = (inner_prod(&residual[0], &e.features[0], residual.size ()));
				projections.push_back(d);
				moduli.push_back(fabs (d) - R);
				indexes.push_back(instruments[inum][k]);
				// std::cout << k << " " << e.file << " " << fabs(d) << std::endl;
			}

			std::vector<int> vx (moduli.size ());
			for (unsigned k = 0; k < moduli.size(); ++k){
				vx[k]= k;
			}
			kth = kth > vx.size () ? vx.size () : kth;

			partial_sort (vx.begin(), vx.begin() + kth, vx.end (), Comp(moduli));

			unsigned p = rand () % kth;		
			f[i] = indexes[vx[p]];
			// std::cout << "SELECTED " << vx[p] << " " << database[f[i]].file << std::endl;
			float no = norm<float> (&database[f[i]].features[0], database[f[i]].features.size ());
			no *= no;
			for (unsigned k = 0; k < residual.size (); ++k) {
				residual[k] -= (projections[vx[p]] * database[f[i]].features[k] / no);
			}
			// std::cout << "--------------------------------------- " << norm (&residual[0], residual.size()) << std::endl;
		}
	}
};

#endif	// STANDARDGA_H 

// EOF
