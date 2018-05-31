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

// TODO: strumenti, filtri, matching pursuit per startup e mutation,
//	     incremento database, gestione dati simbolici, miglioramento interfaccia codice
//		 cambiare plot in 512x512..., gestire diversity, correzione pitch

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

		//#define TEST_FEATURES
		#ifdef TEST_FEATURES
			vector<float> mag, env;
			compute_features(argv[1], mag, 2048, 512, 1024, "spectrum");
			compute_features(argv[1], env, 2048, 512, 1024, "specenv");
			ofstream out ("test_features.txt");
			out << "[";
			for (unsigned i = 0; i < mag.size (); ++i) {
				out << mag[i] << " ";
			}
			out << "]" << endl << endl;
			out << "[";
			for (unsigned i = 0; i < mag.size (); ++i) {
				out << env[i] << " ";
			}
			out << "]" << endl;

			return 0;
		#endif


		cout << "loading configuration...";
		Config<float> c;
		read_config(argv[2], &c);
		cout << "done" << endl;

		cout << "loading database...";
		vector<db_entry> idb;
		int bsize = 1024;			// defaults
		int hopsize = 512;
		int ncoeff = bsize / 2;
		std::string type = "spectrum";

		load_db (c.db_file.c_str (), idb, bsize, hopsize, ncoeff, type);
		cout << "done" << endl;

		cout << "analysing target...";
		vector<float> target (ncoeff);
		compute_features(argv[1], target, bsize, hopsize, ncoeff, type);
		normalize(&target[0], &target[0], ncoeff);
		cout << "done" << endl;
		plot_vector("target.bmp", target, false, ncoeff);

		vector<db_entry> database;
		if (c.harmonic_filter > 0) {
			cout << "harmonic filtering...";
			map<string, int> notes;
			get_notes (argv[1], notes, bsize, hopsize, c.harmonic_filter);
			
			harmonic_filter(idb, notes, database);
			cout << "done" << endl << endl;

			cout << "notes     : ";
			for (map<string, int>::iterator i = notes.begin(); i != notes.end (); ++i) {
				cout << i->first << " ";
			}
			cout << endl;
		} else {
			database = idb;
			cout << endl;
		}

		cout << "features  : " << type << ", " << bsize << ", " << hopsize << ", "
			<< ncoeff << endl;
		cout << "parameters: " << c.xover_rate << ", " << c.mutation_rate << ", "
			<< c.mutation_amp << endl << endl;

		vector<Individual> population (c.pop_size);
		gen_random_population (population, c.n_instruments, database.size ());

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
			genereate_population(population, new_pop, c.pop_size, total_fitness,
				c.xover_rate, c.mutation_rate, c.mutation_amp, database.size ());
	
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
				
		vector<Individual> uniques;
		make_uniques(best_pop, uniques);

		cout << "best fitness = " << max_fit << " (epoch " << best_epoch << ", "
			<< uniques.size () << " individuals)" << endl << endl;

		Individual best = get_best_individual(uniques);
		cout << "best solution: " << endl;
		for (unsigned i = 0; i < c.n_instruments; ++i) {
			cout << "\t" << database[best.chromosome[i]].file << endl;
		}
		cout << endl;	

		if (c.export_solutions) {		
			cout << "saving best solutions..."; cout.flush ();
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

