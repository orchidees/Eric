// c_driver.c
// 

#include "orchidea.h"

#include <stdlib.h>
#include <stdio.h>

#define TOOL_PATH "."

int main (int argc, char* argv[]) {
	printf ("[orchidea - C API test driver]\n\n");

	// OrchideaHandle* h = orchidea_create ();
	// int err = ORCHIDEA_NO_ERROR;

	// orchidea_reset_filters(h);
	
	// orchidea_throw(h, orchidea_set_target (h, "WinchesterBell.wav", TOOL_PATH));

	// orchidea_throw(h,orchidea_set_source (h, "SOL_toyDB", TOOL_PATH));
	// printf("%s\n", orchidea_dump_source (h));
	
	// orchidea_throw (h, orchidea_set_search (h, "genetic", NULL));
	// orchidea_throw (h, orchidea_set_search_param (h, "n_iter", "100"));
	
	// const char* orchestra[] = {
	// 	"Ob",
	// 	"Hn",
	// 	"Vc"
	// };
	// orchidea_set_orchestra (h, orchestra, 3);
	
	// const char* criteria[] = {
	// 	"SpectralCentroidMean",
	// 	"SpectralSpreadMean",
	// 	//"PartialsMeanAmplitude",
	// 	"MelMeanAmplitude"
	// };
	// orchidea_set_criteria (h, criteria, 3);
	
	// const char* styles[] = {
	// 	"ord",
	// 	"cresc",
	// 	"nonvib",
	// };
	// orchidea_set_styles (h, styles, 3);
	
	// const char* dynamics[] = {
	// 	"ppff",
	// 	"ppp",
	// 	"pp",
	// 	"p",
	// 	"mp",
	// 	"mf",
	// 	"f",
	// 	"ff",
	// 	"fff"
	// };
	// orchidea_set_dynamics (h, dynamics, 9);

	// orchidea_set_MIDIcents (h, "2100", "10800");
	
	// orchidea_set_harmonic_filtering (h, 1);

	// printf("orchestrating...");
	// int nb_solutions = 0;
	// orchidea_throw(h, orchidea_orchestrate (h, &nb_solutions));
	// printf ("done\n");
	
	// printf("exporting...");
	// const char* sound_paths[] = {
	// 	"SOL_toy"
	// };
	// orchidea_set_sounds (h, sound_paths, 1);
	// orchidea_throw(h, orchidea_export_solutions (h, "solutions", NULL));
	// printf ("done\n");
	
	// printf("%s\n", orchidea_get_last_solutions (h));
	// printf ("solution(s) = %d\n", nb_solutions);

	// orchidea_destroy (h);

	return 0;
}

// EOF

