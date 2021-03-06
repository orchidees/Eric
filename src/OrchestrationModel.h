// OrchestrationModel.h
// 

#ifndef ORCHESTRATIONMODEL_H
#define ORCHESTRATIONMODEL_H 

#include "Parameters.h"
#include "Solution.h"
#include "Source.h"
#include "WavFile.h"
#include "algorithms.h"

#include <vector>
#include <map>
#include <string>
#include <iomanip>

template<typename T>
struct OrchestrationModel {
	OrchestrationModel (Parameters<T>* p) : ncoeff (0), segment (nullptr),
		parameters (p) {}

	void export_solutions (const std::string& prefix = "") {
		std::stringstream nn;
		nn << prefix << "summary.txt";
		std::ofstream solutions_summary (nn.str ());
		
		solutions_summary << "(orchestra ";
		for (unsigned i = 0; i < parameters->orchestra.size (); ++i) {
			solutions_summary << parameters->orchestra.at (i) << " ";
		}
		solutions_summary << ")" << std::endl;

		unsigned max_sols =  parameters->export_solutions < solutions.size () ? 
			 parameters->export_solutions : solutions.size ();

		solutions_summary << "(segment " 
			<< ((float) segment->start / DEFAULT_SR * 1000.) << std::endl;

		for (unsigned i = 0; i < max_sols; ++i) {
			std::vector<T> outleft;
			std::vector<T> outright;
			solutions[i].generate (outleft, outright, solutions_summary,
				segment, parameters, database, i, true);

			std::vector<T> mix (outleft.size () * 2);
			interleave(&mix[0], &outleft[0], &outright[0], outleft.size ());
			scale<T>(&mix[0], &mix[0], outleft.size () * 2, 2.);

			std::stringstream wav_name;
			wav_name << prefix << "solution." << std::setw(4) << std::setfill('0')
				<< i + 1 << ".wav";			
			WavOutFile outfile (wav_name.str ().c_str(), DEFAULT_SR, 16, 2);
			outfile.write(&mix[0], outleft.size () * 2);
		}
		solutions_summary << ")" << std::endl;
		solutions_summary.close ();
	}
	
	int ncoeff;
	Segment<T>* segment;
	Parameters<T>* parameters;

	std::vector<DB_entry<T>* > database;
	std::map<std::string, std::vector<int> > instruments;
	std::vector<std::string> orchestra;

	std::vector<Solution<T> > solutions;
	std::vector<T> fitness;
	std::vector<T> best_forecast;
};

#endif	// ORCHESTRATIONMODEL_H 

// EOF
