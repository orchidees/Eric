// forecasts.h
// 


#ifndef FORECASTS_H
#define FORECASTS_H 

#include "Source.h"
#include "OptimizerI.h"

#include <vector>

template <typename T>
struct AdditiveForecast {
	static void compute (const Solution<T>& id, 
		const std::vector<DB_entry<T>>& database, 
		std::vector<T>& forecast, const std::vector<T>& target) {

		for (unsigned i = 0; i < id.indices.size (); ++i) {
			if (id.indices[i] == -1) continue; // silent instrument
			DB_entry<T> e = database[id.indices[i]];

			for (unsigned j = 0; j < target.size (); ++j) {
				forecast[j] += e.features[j] / id.indices.size ();	
			}
		}
	}
};

template <typename T>
struct ProjectiveForecast {
	static void compute (const Solution<T>& id, 
		const std::vector<DB_entry<T>>& database, 
		std::vector<T>& forecast, const std::vector<T>& target) {


		for (unsigned i = 0; i < id.indices.size (); ++i) {
			if (id.indices[i] == -1) continue; // silent instrument
			DB_entry<T> e = database[id.indices[i]];
			
			T no = norm<T>(&e.features[0], e.features.size ());
			T prod = inner_prod(&target[0], &e.features[0], target.size ());
			no *= no;

			for (unsigned j = 0; j < target.size (); ++j) {
				forecast[j] += (prod * e.features[j] / no);
			}
		}
	}
};

template <typename T>
struct EnergyLevelForecast {
	static void compute (const Solution<T>& id, 
		const std::vector<DB_entry<T>>& database, 
		std::vector<T>& forecast, const std::vector<T>& target) {

		T tot_nrg = 0;
		for (unsigned i = 0; i < id.indices.size (); ++i) {
			if (id.indices[i] == -1) continue; // silent instrument
			DB_entry<T> e = database[id.indices[i]];
			
			T nrg = map_dynamics (e);

			for (unsigned j = 0; j < target.size (); ++j) {
				forecast[j] += nrg * e.features[j];	
				tot_nrg += nrg;
			}
		}
		
		for (unsigned j = 0; j < target.size (); ++j) {
			forecast[j] = (tot_nrg != 0 ? forecast[j] / tot_nrg : 0);
		}
	}
private:
	static T map_dynamics (const DB_entry<T>& e) {
		if (e.symbols[3] == "ppp") return 1;
		if (e.symbols[3] == "pp") return 2;
		if (e.symbols[3] == "p") return 3;
		if (e.symbols[3] == "mp") return 4;
		if (e.symbols[3] == "mf") return 5;
		if (e.symbols[3] == "f") return 6;
		if (e.symbols[3] == "ff") return 7;
		if (e.symbols[3] == "fff") return 8;

		return 1;
	}
};

#endif	// FORECASTS_H 

// EOF
