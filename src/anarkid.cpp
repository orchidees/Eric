// anarkid.cpp
//

#include "analysis.h"
#include "utilities.h"
#include "constants.h"
#include "ga.h"

#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <ctime>

using namespace std;

// 1. compute MFCC of target
// 2. read text file for data in memory filename + coefficients
// 3. chromosome is sequence of random numbers from 1 to n files
// 4. mutation is +-r integer
// 5. evaluation is = sum of corresponding envelopes and distance with target

// TODO: matching pursuit per startup e mutation,
//	     tuning quantizzato (??)
//	     check mfcc, riverbero 

// REFACTOR: miglioramento interfaccia codice

const int MAX_EQUAL_FITNESS = 15;

int main (int argc, char* argv[]) {
    try {
    	srand (time (NULL));

		cout << "[anarkid, ver. 0.1]" << endl << endl;
		cout << "anarchist assisted orchestration" << endl;
		cout << "(c) 2018, www.carminecella.com" << endl << endl;

		if (argc != 3) {
			throw runtime_error("syntax is 'anarkid target.wav config.txt");
		}

		// config --------------------------------------------------------------
		cout << "loading configuration... "; cout.flush ();
		Config<float> c;
		read_config(argv[2], &c);
		cout << "done" << endl;
		cout << "parameters.............. " << c.xover_rate << ", " << c.mutation_rate << ", "
			 << c.sparsity << endl;

		// db ------------------------------------------------------------------
		cout << "loading databases....... ";  cout.flush ();
		vector<DB_entry> idb;
		int bsize = 1024;			// defaults
		int hopsize = 512;
		int ncoeff = bsize / 2;
		std::string type = "spectrum";
		for (unsigned i = 0; i < c.db_files.size (); ++i) {
			load_db (c.db_files[i].c_str (), idb, bsize, hopsize, ncoeff, type);
		}
		cout << "done (" << idb.size () << " entries)" << endl;
		cout << "features................ " << type << ", " << bsize << ", " << hopsize << ", "
			<< ncoeff << endl;
		
		// symbols -------------------------------------------------------------
		cout << "gathering symbols....... "; cout.flush();
		map<string, vector<int> > tot_instruments;
		map<string, vector <int> > styles;
		map<string, vector <int> > pitches;
		map<string, vector <int> > dynamics;
		for (unsigned i = 0; i < idb.size (); ++i) {
			insert_symbol (tot_instruments, idb[i].symbols[0], i);
			insert_symbol (styles, idb[i].symbols[1], i);
			insert_symbol (pitches, idb[i].symbols[2], i);
			insert_symbol (dynamics, idb[i].symbols[3], i);
		}			
		cout << "done" << endl;
		cout << "instruments............. ";
		print_coll (cout, tot_instruments, 25);
		cout << endl;
		cout << "styles.................. ";
		print_coll (cout, styles, 25);
		cout << endl;
		cout << "pitches................. ";
		print_coll (cout, pitches, 25); 
		cout << endl;
		cout << "dynamics................ ";
		print_coll (cout, dynamics, 25);
		cout << endl;

		// pfilt  --------------------------------------------------------------
		vector<DB_entry> database;
		map<string, int> notes;
		
		cout << "filtering database...... ";  cout.flush ();

		for (unsigned i = 0; i < c.extra_pitches.size (); ++i) {
			notes[c.extra_pitches[i]] = 0;
		}		
		if (c.partials_filtering > 0) {
			partials_to_notes (argv[1], notes, c.partials_window, c.partials_window / 4, 
				c.partials_filtering);	
		}
		apply_filters (idb, notes, c.styles, c.dynamics, database);

		if (database.size () < 1) {
			throw runtime_error("empty search space; please check filters");
		}
		cout << "done (" << database.size () << " entries)" << endl;

		if (c.partials_filtering) {
			cout << "target pitches.......... ";
			int nl = 0;
			for (map<string, int>::iterator i = notes.begin(); i != notes.end (); ++i) {
				cout << i->first << " (" << 
					(i->second > 0 ? "+" : "") << i->second << " cents) ";
				if (nl == 3) {
					cout << endl;
					for (unsigned i = 0; i < 25; ++i) cout << " ";
					nl = 0;
				}
				++nl;
			}		
			cout << endl;
		}

		// check ---------------------------------------------------------------
		cout << "checking instruments.... "; cout.flush();
		map<string, vector <int> > instruments;
		vector<string> effective_orchestra;
		for (unsigned i = 0; i < database.size (); ++i) {
			insert_symbol (instruments, database[i].symbols[0], i);
		}
		for (vector<string>::iterator i = c.orchestra.begin(); i != c.orchestra.end ();
			++i) {
			if ((*i).find ("|") != string::npos) {
				deque<string> res;
				tokenize(*i, res, "|");
	
				bool missing = false;
				for (unsigned k = 0; k < res.size (); ++k) {
					map<string, vector<int> >::iterator it = instruments.find (res[k]);
					if (it == instruments.end ()) {
						missing = true;
						break;
					}	
				}
				if (!missing) effective_orchestra.push_back(*i);
			} else {
				map<string, vector<int> >::iterator it = instruments.find (*i);
				if (it != instruments.end ()) {
					effective_orchestra.push_back(*i);
				}
			}
		}
		if (effective_orchestra.size () == 0) {
			throw runtime_error ("empty orchestra; please check filters");
		}
		cout << "done" << endl;
 
		// target --------------------------------------------------------------
		cout << "analysing target........ ";  cout.flush ();
		vector<float> target (ncoeff);
		compute_features(argv[1], target, bsize, hopsize, ncoeff, type);
		cout << "done" << endl;

		// ga ------------------------------------------------------------------
		cout << "init population......... "; cout.flush ();
		vector<Individual> population (c.pop_size);
		gen_population (population, effective_orchestra, instruments, database, 
			target, c.pursuit);	
		// export_population(population, database, c, notes, type, ncoeff, "pursuit");
		cout << "done" << endl;

		float total_fitness = 0;
		vector<float> fitness;

		vector<Individual> best_pop;
		int fit_count = 0;
		float max_fit = 0;
		float old_fit = 0;
		int best_epoch = 0;
		cout << "searching............... "; cout.flush ();
		for (unsigned i = 0; i < c.max_epochs; ++i) {
			total_fitness = evaluate_population(population, target, database, ncoeff);	

			fitness.push_back(total_fitness);

			vector<Individual> new_pop;
			gen_offspring_population(population, new_pop, c.pop_size, total_fitness,
				c.xover_rate, c.mutation_rate, c.sparsity, effective_orchestra, instruments);
	
			copy_population (new_pop, population);

			if (max_fit < total_fitness) {
				max_fit = total_fitness;
				best_pop = new_pop;
				best_epoch = i;
			}
			if (total_fitness >= LARGE_VALUE) break;
			if (old_fit == total_fitness) ++fit_count;
			if (fit_count > MAX_EQUAL_FITNESS) break;
			old_fit = total_fitness;
		}
		cout << "done" << endl;

		ofstream fit ("fitness.txt");
		fit << "[";
		for (unsigned i = 0; i < fitness.size (); ++i) {
			fit << fitness[i] << " ";
		}
		fit << "]" << endl;
		fit.close ();

		// export --------------------------------------------------------------				
		vector<Individual> uniques;
		make_uniques(best_pop, uniques);
		evaluate_population(uniques, target, database, ncoeff);

		Individual best = get_best_individual(uniques);
		cout << "best fitness............ " << max_fit << " (epoch " << best_epoch << ", "
			<< uniques.size () << " individuals)" << endl;
		
		cout << "best solution........... ";
		unsigned n_instruments = effective_orchestra.size ();
		for (unsigned i = 0; i < n_instruments; ++i) {
			if (i != 0) for (unsigned i = 0; i < 25; ++i) cout << " ";
			if (best.chromosome[i] == -1) {
				cout << "-" << endl;
				continue;
			}
			for (unsigned h = 0; h < database[best.chromosome[i]].symbols.size (); ++h) {
				cout << database[best.chromosome[i]].symbols[h] << "\t";
			}
			cout << endl;
		}
		if (c.export_solutions > 0) {		
			cout << "saving best solutions... "; cout.flush ();
			std::sort (uniques.begin (), uniques.end ());
			std::reverse(uniques.begin (), uniques.end());

			if (c.export_solutions < uniques.size ()) uniques.resize(c.export_solutions);
			export_population(uniques, database, c, notes, type, ncoeff);
			cout << "done" << endl;
		}

		cout << endl;	
    } catch (exception& e) {
        cout << "Error: " << e.what () << endl;
    } catch (...) {
        cout << "Fatal error: unknown exception" << endl;
    }
    return 0;
}

// EOF

