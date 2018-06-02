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
//	     incremento database, tuning quantizzato (??)
//	     strumenti doppi, check mfcc

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
		cout << "loading configuration..."; cout.flush ();
		Config<float> c;
		read_config(argv[2], &c);
		cout << "done" << endl;


		// db ------------------------------------------------------------------
		cout << "loading database...";  cout.flush ();
		vector<DB_entry> idb;
		int bsize = 1024;			// defaults
		int hopsize = 512;
		int ncoeff = bsize / 2;
		std::string type = "spectrum";
		load_db (c.db_file.c_str (), idb, bsize, hopsize, ncoeff, type);
		cout << "done" << endl;

		// target --------------------------------------------------------------
		cout << "analysing target...";  cout.flush ();
		vector<float> target (ncoeff);
		compute_features(argv[1], target, bsize, hopsize, ncoeff, type);
		plot_vector("target.bmp", target, 256, 256);
		cout << "done" << endl;

		// pfilt  --------------------------------------------------------------
		vector<DB_entry> database;
		map<string, int> notes;
		if (c.partials_filtering > 0) {
			cout << "partials filtering...";  cout.flush ();
			partials_to_notes (argv[1], notes, c.partials_window, c.partials_window / 4, 
				c.partials_filtering);
			partials_filter (idb, notes, database);
			if (database.size () < 1) {
				throw runtime_error("empty search space; please check filters");
			}
			cout << "done" << endl << endl;

			cout << "notes      : ";
			for (map<string, int>::iterator i = notes.begin(); i != notes.end (); ++i) {
				cout << i->first << " (" << 
					(i->second > 0 ? "+" : "") << i->second << " cents) ";
			}
			cout << endl;
		} else {
			database = idb;
			cout << endl;
		}

		cout << "features   : " << type << ", " << bsize << ", " << hopsize << ", "
			<< ncoeff << endl;
		cout << "parameters : " << c.xover_rate << ", " << c.mutation_rate << ", "
			 << c.sparsity << endl;

		// instr ---------------------------------------------------------------
		map<string, vector<int> > instruments;
		for (unsigned i = 0; i < database.size (); ++i) {
			string instr = database[i].symbols[0];
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
				err << "invalid instrument " << c.orchestra[i] << " specified";
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
				c.xover_rate, c.mutation_rate, c.sparsity, c.orchestra, instruments);
	
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
		evaluate_population(uniques, target, database, ncoeff);

		cout << "best fitness = " << max_fit << " (epoch " << best_epoch << ", "
			<< uniques.size () << " individuals)" << endl << endl;

		plot_vector("fitness.bmp", fitness, 256, 256);
		Individual best = get_best_individual(uniques);
		cout << "best solution: " << endl;
		unsigned n_instruments = c.orchestra.size ();
		for (unsigned i = 0; i < n_instruments; ++i) {
			if (best.chromosome[i] == -1) {
				cout << "\t-" << endl;
				continue;
			}
			for (unsigned h = 0; h < database[best.chromosome[i]].symbols.size (); ++h) {
				cout << "\t" << database[best.chromosome[i]].symbols[h] << " ";
			}
			cout << endl;
		}
		cout << endl;	

		std::vector<float> values (target.size (), 0);
		forecast_individual(best, database, values, ncoeff);
		plot_vector<float>("best.bmp", values);

		if (c.export_solutions > 0) {		
			cout << "saving best solutions..."; cout.flush ();
			std::sort (uniques.begin (), uniques.end ());
			std::reverse(uniques.begin (), uniques.end());

			if (c.export_solutions < uniques.size ()) uniques.resize(c.export_solutions);
			export_population(uniques, database, c, notes, type, ncoeff);
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

