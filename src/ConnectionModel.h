// ConnectionModel.h
// 

#ifndef CONNECTIONMODEL_H
#define CONNECTIONMODEL_H 

#include "OrchestrationModel.h"

#include <vector>

template <typename T>
struct ConnectionModel {
	void export_solutions (const std::string& prefix = "") {
		std::stringstream nn;
		nn << prefix << "connection.txt";
		std::ofstream solutions_summary (nn.str ());

		std::vector<T> outleft;
		std::vector<T> outright;		
		for (unsigned i = 0; i < models.size (); ++i) {
			solutions_summary << ">" << i << " " << models[i]->segment->start << std::endl;

			models[i]->solutions[indices[i]].generate (outleft, outright, 
				solutions_summary,
				models[i]->segment, models[i]->parameters, models[i]->database);
		}

		std::vector<T> mix (outleft.size () * 2);
		interleave(&mix[0], &outleft[0], &outright[0], outleft.size ());
		scale<T>(&mix[0], &mix[0], outleft.size () * 2, 2.);

		WavOutFile outfile ("connection.wav", DEFAULT_SR, 16, 2);
		outfile.write(&mix[0], outleft.size () * 2);
		solutions_summary.close ();
	}

	std::vector<OrchestrationModel<T>* > models;
	std::vector<int> indices;
};
#endif	// CONNECTIONMODEL_H 

// EOF