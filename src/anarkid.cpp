// anarkid.cpp
//

#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <map>
#include <iomanip>

#include "analysis.h"
#include "utilities.h"
#include "ga.h"
#include "BMP24.h"

using namespace std;

const int BSIZE = 1024;
const int HOPSIZE = 512;
const int NUM_FEATURES = BSIZE / 4;

const int POP_SIZE = 100;
const int NUM_INSTR = 20;
const int MAX_EPOCHS = 1000;

// 1. compute MFCC of target
// 2. read text file for data in memory filename + coefficients
// 3. chromosome is sequence of random numbers from 1 to n files
// 4. mutation is +-r integer
// 5. evaluation is = some of corresponding envelopes and distance with target
// -- N instruments in solution if given, no choice for other params

int main (int argc, char* argv[]) {
    try {
		cout << "[anarkid, ver. 0.1]" << endl << endl;
		cout << "anarchist assisted orchestration" << endl;
		cout << "(c) 2018, www.carminecella.com" << endl << endl;

		if (argc != 7) {
			throw runtime_error("syntax is 'anarkid target.wav dbfile.txt xover_rate mutation_rate mutation_amplitude sound_path");
		}

		cout << "analysing target...";
		vector<float> target;
		compute_features(argv[1], target, BSIZE, HOPSIZE, NUM_FEATURES);
		cout << "done" << endl;

		cout << "loading database...";
		vector<db_entry> database;
		load_db (argv[2], database, NUM_FEATURES);
		cout << "done" << endl;

		float xover_rate = atof (argv[3]);
		float mutation_rate = atof (argv[4]);
		float mutation_amplitude = atof (argv[5]);

		int maxPos = 0;
		float max = maximum(&target[0], target.size (), maxPos);
		BMP24 t (NUM_FEATURES, 256);
		for (unsigned z = 0; z < target.size (); ++z) {
			t.set (z, (int) 128 + (128. * target[z] / max), 0, 127, 0);
		}
		t.save ("target.bmp");

		vector<Individual> population (POP_SIZE);
		gen_random_population (population, NUM_INSTR, database.size ());

		float total_fitness = 0;
		vector<float> fitness;

		ofstream solutions ("solutions.txt");
		solutions << "target: " << argv[1] << endl << endl;

		int fit_count = 0;
		float old_fit = 0;
		for (unsigned i = 0; i < MAX_EPOCHS; ++i) {
			total_fitness = evaluate_population(population, target, database, NUM_FEATURES);	

			fitness.push_back(total_fitness);

			cout <<  "epoch: " << setw (4) << i << " - total fitness = " << total_fitness << endl;
			vector<Individual> new_pop (POP_SIZE);
			genereate_population(population, new_pop, POP_SIZE, total_fitness,
				xover_rate, mutation_rate, mutation_amplitude, database.size ());

			Individual best = get_best_individual(new_pop);				
			std::vector<float> values (target.size (), 0);
			
			forecast_individual(best, database, values, NUM_FEATURES);
			maxPos = 0;
			max = maximum(&values[0], values.size (), maxPos);

			BMP24 b (NUM_FEATURES, 256);
			for (unsigned z = 0; z < values.size (); ++z) {
				b.set (z, (int) (128. * (values[z]) / max) + 128, 0, 127, 0);
			}
			std::stringstream name_bmp;
			name_bmp << "best_at_epoch_" << i << ".bmp";
			b.save (name_bmp.str ().c_str ());

			std::stringstream name_wav;
			name_wav << "best_at_epoch_" << i << ".wav";			
			vector<string> files;
			vector<float> ratios (NUM_INSTR, 1);
			decode_chromosome(best.chromosome, database, files);

			create_sound_mix(files, argv[6], ratios, name_wav.str ().c_str ());
			for (unsigned z = 0; z < files.size (); ++z) {
				solutions << files[z] << " ";
			}
			solutions << endl;

			copy_population (new_pop, population);

			if (total_fitness >= LARGE_VALUE) break;
			if (old_fit == total_fitness) ++fit_count;
			if (fit_count > 10) break;
			old_fit = total_fitness;
		}
	
		cout << endl;
		Individual best = get_best_individual(population);
		
		cout << "final fitness = " << total_fitness << endl << endl;

		cout << "best solution: " << endl;
		for (unsigned i = 0; i < NUM_INSTR; ++i) {
			cout << "\t" << database[best.chromosome[i]].file << endl;
		}
		cout << endl;

		BMP24 ft (fitness.size (), 256);
		maxPos = 0;
		max = maximum(&fitness[0], fitness.size (), maxPos);

		for (unsigned z = 0; z < fitness.size (); ++z) {
			ft.set (z, (int) (128. * (fitness[z]) / max) + 128, 0, 127, 0);
		}
		ft.save ("fitness.bmp");

    } catch (exception& e) {
        cout << "Error: " << e.what () << endl;
    } catch (...) {
        cout << "Fatal error: unknown exception" << endl;
    }
    return 0;
}

// EOF

