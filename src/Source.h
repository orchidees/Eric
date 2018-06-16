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
struct Source {
	Source (Parameters<T>* params) {
		parameters = params;
		load (parameters->db_files);
	}
	void load (const std::vector<std::string>& db_files) {
		database.clear ();
		original_database.clear ();
		tot_instruments.clear ();
		styles.clear ();
		pitches.clear ();
		dynamics.clear ();
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

				if (e.features.size () != ncoeff) {
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
		}			

		actual_orchestra = parameters->orchestra;
		actual_instruments = tot_instruments;
	}

	void apply_filters (std::map<std::string, int>& notes) {
		original_database = database;
		database.clear ();
		actual_orchestra.clear ();
		actual_instruments.clear ();

		for (unsigned j = 0; j < original_database.size (); ++j) {
			bool note_check = notes.size () == 0 ? true : false;
			bool style_check = parameters->styles.size () == 0 ? true : false;
			bool dynamics_check = parameters->dynamics.size () == 0 ? true : false;

			for (std::map<std::string, int>::iterator i = notes.begin(); 
				i != notes.end (); ++i) {
				if (original_database[j].symbols[2] == i->first) {
					note_check = true;
					break;
				}
			}

			for (unsigned i = 0; i < parameters->styles.size (); ++i) {
				if (original_database[j].symbols[1] == parameters->styles[i]) {
					style_check = true;
					break;
				}
			}

			for (unsigned i = 0; i < parameters->dynamics.size (); ++i) {
				if (original_database[j].symbols[3] == parameters->dynamics[i]) {
					dynamics_check = true;
					break;
				}
			}

			if (note_check && style_check && dynamics_check) {
				database.push_back(original_database[j]);
			}
		}

		if (database.size () < 1) {
			throw std::runtime_error("empty search space; please check filters");
		}

		for (unsigned i = 0; i <database.size (); ++i) {
			insert_symbol (actual_instruments, database[i].symbols[0], i);
		}
		for (std::vector<std::string>::iterator i = parameters->orchestra.begin(); 
			i != parameters->orchestra.end ();
			++i) {
			if ((*i).find ("|") != std::string::npos) {
				std::deque<std::string> res;
				tokenize(*i, res, "|");
	
				bool missing = false;
				for (unsigned k = 0; k < res.size (); ++k) {
					std::map<std::string, std::vector<int> >::iterator it = 
						actual_instruments.find (res[k]);
					if (it == actual_instruments.end ()) {
						missing = true;
						break;
					}	
				}
				if (!missing) actual_orchestra.push_back(*i);
			} else {
				std::map<std::string, std::vector<int> >::iterator it = actual_instruments.find (*i);
				if (it != actual_instruments.end ()) {
					actual_orchestra.push_back(*i);
				}
			}
		}

		if (actual_orchestra.size () == 0) {
			throw std::runtime_error ("empty orchestra; please check filters");
		}

	}
	void clear_filters () {
		database = original_database;
		original_database.clear ();
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

	std::map<std::string, std::vector<int> > actual_instruments;	
	std::vector<std::string> actual_orchestra;
private:
	std::vector<DB_entry<T> > original_database;

	void extract_symbols (DB_entry<T>& e) {
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
};

#endif	// SOURCE_H 

// EOF
