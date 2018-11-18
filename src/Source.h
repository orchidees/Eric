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
#include <iomanip>

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
		load ();
	}
	void item_to_vector (std::map<std::string, std::vector<int> > item,
		std::vector<std::string>& results) {
		for (std::map<std::string, std::vector<int> >::iterator it = item.begin ();
			it != item.end (); ++it) {
			results.push_back(it->first);
		}		
	}
	void query (const std::string& query, std::vector<std::string>& results) {
		std::stringstream tmp;
		tmp << query;
		std::vector<std::string> tokens;
		while (!tmp.eof ()) {
			std::string tok;
			tmp >> tok;
			tokens.push_back(tok);
		}

		if (tokens.size () < 2) {
			throw std::runtime_error ("invalid syntax in query");
		}

		if (tokens[0] == "search") {
			const char* regexp = tokens[1].c_str ();
			for (unsigned j = 0; j <  database.size (); ++j) {
				if (match ((char*) regexp, (char*) database[j].file.c_str ())) {
					results.push_back (database[j].file);
				}
			}
		} else if (tokens[0] == "list") {
			for (unsigned i = 1; i < tokens.size (); ++i) {
				if (tokens[i] == "instruments") {
					item_to_vector(tot_instruments, results);
				} else if (tokens[i] == "styles") {
					item_to_vector(styles, results);
				} else if (tokens[i] == "pitches") {
					item_to_vector(pitches, results);
				} else if (tokens[i] == "dynamics") {
					item_to_vector(dynamics, results);
				} else if (tokens[i] == "others") {
					item_to_vector(others, results);
				} else {
					throw std::runtime_error ("invalid item for list");
				}
			}					
		} else {
			throw std::runtime_error ("invalid query requested");
		}
	}

	void load () {
		if (parameters->db_files.size () == 0) return;

		database.clear ();
		tot_instruments.clear ();
		styles.clear ();
		pitches.clear ();
		dynamics.clear ();
		others.clear ();

		for (unsigned i = 0; i < parameters->db_files.size (); ++i) {
			std::ifstream db (parameters->db_files[i].c_str());

			if (!db.good ()) {
				std::stringstream msg;
				msg << "cannot open db file [" << parameters->db_files[i].c_str() << "]";
				throw std::runtime_error(msg.str ());
			}

			db >> type >> bsize >> hopsize >> ncoeff;
			if (database.size () != 0) {
				if (database[0].features.size () != ncoeff) {
					throw std::runtime_error ("incompatible feature size among databases");
				}
			}
			if (db.fail ()) throw std::runtime_error ("cannot process db file");

			int lineno = 1;
			while (!db.eof () ) {
				std::string line;
				std::getline(db, line, '\n');
				line = trim (line);
				++lineno;
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

				if (e.features.size () != ncoeff) { //+ 1) { // nrg
					std::stringstream err;
					err << "invalid number of features in db at line " << lineno;
					throw std::runtime_error (err.str ());
				}

				database.push_back(e);
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

	void dump (std::ostream& output, int offset = 0, int columns = 0) {
		output << std::setw(offset + 13) <<  "[instruments " ;
		print_coll<int> (output, tot_instruments, offset, columns);
		output << "]" << std::endl;
		output << std::setw(offset + 8) << "[styles ";
		print_coll<int> (output, styles, offset, columns);
		output << "]" << std::endl;
		output << std::setw(offset + 9) << "[pitches ";
		print_coll<int> (output, pitches, offset, columns); 
		output << "]" << std::endl;
		output << std::setw(offset + 10) << "[dynamics ";
		print_coll<int> (output, dynamics, offset, columns);
		output << "]" << std::endl;
		if (others.size ()) {
	 		output << std::setw(offset + 8) << "[others ";
			print_coll<int> (output, others, offset, columns);
			output << "]" << std::endl;
		}
	}
};

#endif	// SOURCE_H 

// EOF
