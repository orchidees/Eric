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

		if (!models.size ()) return;

		solutions_summary << "[orchestra ";
		for (unsigned i = 0; i < models[0]->parameters->orchestra.size (); ++i) {
			solutions_summary << models[0]->parameters->orchestra.at (i) << " ";
		}
		solutions_summary << "]" << std::endl;
		
		std::vector<T> outleft;
		std::vector<T> outright;		
		for (unsigned i = 0; i < models.size (); ++i) {
			solutions_summary << "[segment " 
				<< ((float) models[i]->segment->start / DEFAULT_SR 	* 1000.) << std::endl;

			models[i]->solutions[indices[i]].generate (outleft, outright, 
				solutions_summary,
				models[i]->segment, models[i]->parameters, models[i]->database, indices[i]);
			solutions_summary << "]" << std::endl;
		}
		
		solutions_summary.close ();

		std::vector<T> mix (outleft.size () * 2);
		interleave(&mix[0], &outleft[0], &outright[0], outleft.size ());
		scale<T>(&mix[0], &mix[0], outleft.size () * 2, 2.);

		std::stringstream mm;
		mm << prefix << "connection.wav";
		WavOutFile outfile (mm.str ().c_str (), DEFAULT_SR, 16, 2);
		outfile.write(&mix[0], outleft.size () * 2);
	}

	std::vector<OrchestrationModel<T>* > models;
	std::vector<int> indices;
};
#endif	// CONNECTIONMODEL_H 

// EOF
