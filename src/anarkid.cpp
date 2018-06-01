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

// TODO: filtri, matching pursuit per startup e mutation,
//	     incremento database, gestione dati simbolici (?), miglioramento interfaccia codice
//		 correzione pitch, spazializzazione

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
		cout << "loading configuration...";
		Config<float> c;
		read_config(argv[2], &c);
		cout << "done" << endl;


		// db ------------------------------------------------------------------
		cout << "loading database...";
		vector<DB_entry> idb;
		int bsize = 1024;			// defaults
		int hopsize = 512;
		int ncoeff = bsize / 2;
		std::string type = "spectrum";
		load_db (c.db_file.c_str (), idb, bsize, hopsize, ncoeff, type);
		cout << "done" << endl;

		// target --------------------------------------------------------------
		cout << "analysing target...";
		vector<float> target (ncoeff);
		compute_features(argv[1], target, bsize, hopsize, ncoeff, type);
		normalize(&target[0], &target[0], ncoeff);
		cout << "done" << endl;

		// pfilt  --------------------------------------------------------------
		vector<DB_entry> database;
		if (c.partials_filtering > 0) {
			cout << "partials filtering...";
			map<string, int> notes;
			get_notes (argv[1], notes, bsize, hopsize, c.partials_filtering);
			
			harmonic_filter(idb, notes, database);
			if (database.size () < 1) {
				throw runtime_error("empty search space; please check filters");
			}
			cout << "done" << endl << endl;


			cout << "notes      : ";
			for (map<string, int>::iterator i = notes.begin(); i != notes.end (); ++i) {
				cout << i->first << " ";
			}
			cout << endl;
		} else {
			database = idb;
			cout << endl;
		}

		cout << "features   : " << type << ", " << bsize << ", " << hopsize << ", "
			<< ncoeff << endl;
		cout << "parameters : " << c.xover_rate << ", " << c.mutation_rate << ", "
			<< c.mutation_amp << endl;

		// instr ---------------------------------------------------------------
		map<string, vector<int> > instruments;
		for (unsigned i = 0; i < database.size (); ++i) {
			string instr = get_instrument(database[i]);
			map<string, vector<int> >::iterator it = instruments.find (instr);
			if (it == instruments.end ()) {
				vector<int> d;
				d.push_back(i);
				instruments[instr] = d;
			} else {
				instruments[instr].push_back (i);
			}
		}			

		int nl = 0;
		cout << "instruments: ";
		for (map<string, vector<int> >::iterator it = instruments.begin ();
			it != instruments.end (); ++it) {
			cout << it->first << " ";
			++nl;
			if (nl == 6) {
				cout << endl << "             ";
				nl = 0;
			}
		}
		cout << endl << endl;

		for (unsigned i = 0; i < c.orchestra.size (); ++i) {
			map<string, vector<int> >::iterator it = instruments.find (c.orchestra[i]);
			if (it == instruments.end ()) {
				std::stringstream err;
				err << "invalid isntrument " << c.orchestra[i] << " specified";
				throw runtime_error(err.str ());
			}
		}
		
		// ga ------------------------------------------------------------------
		vector<Individual> population (c.pop_size);
		gen_random_population (population, c.orchestra, instruments);

		float total_fitness = 0;
		vector<float> fitness;

		vector<Individual> best_pop;
		int fit_count = 0;
		float max_fit = 0;
		float old_fit = 0;
		int best_epoch = 0;
		cout << "searching..."; cout.flush ();
		for (unsigned i = 0; i < c.max_epochs; ++i) {
			total_fitness = evaluate_population(population, target, database, ncoeff);	

			fitness.push_back(total_fitness);

			vector<Individual> new_pop;
			gen_offspring_population(population, new_pop, c.pop_size, total_fitness,
				c.xover_rate, c.mutation_rate, c.mutation_amp,
				c.orchestra, instruments);
	
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
		cout << "done" << endl << endl;

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

		cout << "best fitness = " << max_fit << " (epoch " << best_epoch << ", "
			<< uniques.size () << " individuals)" << endl << endl;

		Individual best = get_best_individual(uniques);
		cout << "best solution: " << endl;
		unsigned n_instruments = c.orchestra.size ();
		for (unsigned i = 0; i < n_instruments; ++i) {
			cout << "\t" << database[best.chromosome[i]].file << endl;
		}
		cout << endl;	

		if (c.export_solutions) {		
			cout << "saving best solutions..."; cout.flush ();
			if  (c.max_exported < uniques.size ()) uniques.resize (c.max_exported);

			export_population(uniques, database, c.sound_path.c_str (), 
				type, ncoeff);
			cout << "done" << endl;
		}
    } catch (exception& e) {
        cout << "Error: " << e.what () << endl;
    } catch (...) {
        cout << "Fatal error: unknown exception" << endl;
    }
    return 0;
}

// EOF

