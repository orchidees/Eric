// Source.h
// 


#ifndef SOURCE_H
#define SOURCE_H 

#include "Parameters.h"
#include "utilities.h"

#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>

template<typename T>
struct DB_entry {
	std::string file;
	std::vector<T> features;
	std::deque<std::string> symbols;
};

template <typename T>
void extract_symbols (DB_entry<T>& e) {
	std::string file = removePath(e.file);
	file = removeExtension(file);

	std::deque<std::string> syms;
	tokenize (file, syms, "-"); 

	if (syms.size () == 4) e.symbols = syms; // instr technique note dynamics
	else if (syms.size () > 4) { // instr multi-technique note dynamics ...
		int pos = 1;
		for (unsigned i = 1; i < syms.size (); ++i) {
			if ((syms[i][0] == 'N' ||
				syms[i][0] == 'A' ||
				syms[i][0] == 'B' ||
				syms[i][0] == 'C' ||
				syms[i][0] == 'D' ||
				syms[i][0] == 'E' ||
				syms[i][0] == 'F' ||
				syms[i][0] == 'G') &&
				syms[i].size () <= 3) {
				pos = i;
				break;
			}
		}

		e.symbols.push_back (syms[0]);
		std::stringstream tmp;
		for (unsigned i = 1; i < pos; ++i) {
			tmp << syms[i];
			if (i != pos -1) tmp << "-";
		}
		e.symbols.push_back (tmp.str ());
		for (unsigned i = pos; i < syms.size (); ++i) {
			e.symbols.push_back (syms[i]);
		}
	} else {
		e.symbols = syms;
		while (e.symbols.size () < 4) { // add missing symbols (if needed)
			e.symbols.push_back ("N");
		}
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

template <typename T>
struct Source {
	Source (Parameters<T>* params) {
		parameters = params;
		load (parameters->db_files);
	}
	void load (const std::vector<std::string>& db_files) {
		database.clear ();
		tot_instruments.clear ();
		styles.clear ();
		pitches.clear ();
		dynamics.clear ();
		others.clear ();

		for (unsigned i = 0; i < db_files.size (); ++i) {
			std::ifstream db (db_files[i].c_str());
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
				
				DB_entry<T> e;
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

				if (e.features.size () != ncoeff + 1) { // nrg
					std::stringstream err;
					err << "invalid number of features in db at line " << lineno;
					throw std::runtime_error (err.str ());
				}

				database.push_back(e);
				++lineno;
			}
		}

		for (unsigned i = 0; i < database.size (); ++i) {
			insert_symbol (tot_instruments, database[i].symbols[0], i);
			insert_symbol (styles, database[i].symbols[1], i);
			insert_symbol (pitches, database[i].symbols[2], i);
			insert_symbol (dynamics, database[i].symbols[3], i);
			for (unsigned j = 4; j < database[i].symbols.size (); ++j) {
				insert_symbol (others, database[i].symbols[j], i);
			}
		}			
	}

	Parameters<T>* parameters;

	std::vector<DB_entry<T> > database;

	std::string type;
	int bsize;
	int hopsize;
	int ncoeff;

	std::map<std::string, std::vector<int> > tot_instruments;
	std::map<std::string, std::vector <int> > styles;
	std::map<std::string, std::vector <int> > pitches;
	std::map<std::string, std::vector <int> > dynamics;
	std::map<std::string, std::vector <int> > others;

};

#endif	// SOURCE_H 

// EOF
