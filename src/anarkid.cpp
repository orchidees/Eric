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
// 5. evaluation is = some of corresponding envelopes and distance with target
// -- N instruments in solution if given, no choice for other params


// TODO: avg con peso energie, finestrature su FFT, harmonic filter, strumenti, filtri
//
int main (int argc, char* argv[]) {
    try {
    	srand (time (NULL));

		cout << "[anarkid, ver. 0.1]" << endl << endl;
		cout << "anarchist assisted orchestration" << endl;
		cout << "(c) 2018, www.carminecella.com" << endl << endl;

		if (argc != 3) {
			throw runtime_error("syntax is 'anarkid target.wav config.txt");
		}

		cout << "loading configuration...";
		Config<float> c;
		read_config(argv[2], &c);
		cout << "done" << endl;

		cout << "loading database...";
		vector<db_entry> database;
		int bsize = 1024;
		int hopsize = 512;
		int ncoeff = 14;
		std::string type = "spectrum";

		load_db (c.db_file.c_str (), database, bsize, hopsize, ncoeff, type);
		cout << "done" << endl;

		cout << "analysing target...";
		vector<float> target (ncoeff);
		compute_features(argv[1], target, bsize, hopsize, ncoeff, type);
		normalize(&target[0], &target[0], ncoeff);
		cout << "done" << endl << endl;
		plot_vector("target.bmp", target, type == "mfcc" ? true : false, false, ncoeff);

		cout << "features  : " << type << ", " << bsize << ", " << hopsize << ", "
			<< ncoeff << endl;
		cout << "parameters: " << c.xover_rate << ", " << c.mutation_rate << ", "
			<< c.mutation_amp << endl << endl;

		vector<Individual> population (c.pop_size);
		gen_random_population (population, c.n_instruments, database.size ());

		float total_fitness = 0;
		vector<float> fitness;

		vector<Individual> bests;
		int fit_count = 0;
		float old_fit = 0;
		for (unsigned i = 0; i < c.max_epochs; ++i) {
			total_fitness = evaluate_population(population, target, database, ncoeff);	

			fitness.push_back(total_fitness);

			cout <<  "epoch = " << setw (5) << i << " - fitness = " << total_fitness << endl;
			vector<Individual> new_pop;
			genereate_population(population, new_pop, c.pop_size, total_fitness,
				c.xover_rate, c.mutation_rate, c.mutation_amp, database.size ());
	
			Individual best = get_best_individual(new_pop);				
			bests.push_back (best);

			copy_population (new_pop, population);

			if (total_fitness >= LARGE_VALUE) break;
			if (old_fit == total_fitness) ++fit_count;
			if (fit_count > 10) break;
			old_fit = total_fitness;
		}
		cout << endl;

		ofstream fit ("fitness.txt");
		fit << "[";
		for (unsigned i = 0; i < fitness.size (); ++i) {
			fit << fitness[i] << " ";
		}
		fit << "]" << endl;
		fit.close ();

		Individual best = get_best_individual(population);
		cout << "final fitness = " << total_fitness << endl << endl;
		cout << "best solution: " << endl;
		for (unsigned i = 0; i < c.n_instruments; ++i) {
			cout << "\t" << database[best.chromosome[i]].file << endl;
		}
		cout << endl;	

		if (c.export_sol) {		
			cout << "saving best solutions..."; cout.flush ();
			export_population(population, database, c.sound_path.c_str (), type, ncoeff);
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

