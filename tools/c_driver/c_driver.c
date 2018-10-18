// c_driver.c
// 

#include "orchidea.h"

#include <stdlib.h>
#include <stdio.h>

void notif (const char* action, float status) {
	printf ("%s: %g\n", action, status);
}

int main (int argc, char* argv[]) {
		printf ("[orchidea, ver. %d.%d]\n\n", ORCHIDEA_VERSION_MAJOR, 
			ORCHIDEA_VERSION_MINOR);
	printf ("C API test driver (shared)\n");
	printf ("(c) 2018, www.carminecella.com\n\n");
	
	if (argc != 4) {
		printf ("error: syntax is 'c_driver target.wav db_name sounds_folder\n");
		return -1;
	}

	OrchideaHandle* h = orchidea_create ();
	int err = ORCHIDEA_NO_ERROR;

	orchidea_set_notifier (h, notif);
	orchidea_reset_filters(h);

	const char* paths[] = {
		argv[2]
	};	
	orchidea_throw(h,orchidea_set_source (h, paths, 1));
	printf("%s\n", orchidea_dump_source (h));
	
	orchidea_throw(h, orchidea_set_target (h, argv[1]));	
	
	orchidea_throw (h, orchidea_set_search (h, "genetic"));

	const char* epochs[] = {
		"max_epochs",
		"300"
	};	
	orchidea_throw (h, orchidea_set_param (h, epochs, 2));

	const char* population[] = {
		"pop_size",
		"300"
	};	
	orchidea_throw (h, orchidea_set_param (h, population, 2));
	
	const char* orchestra[] = {
		"orchestra",
		"Ob",
		"Hn",
		"Vc"
	};
	orchidea_set_param (h, orchestra, 4);
	
	const char* styles[] = {
		"styles",
		"ord",
	};
	orchidea_set_param (h, styles, 2);
	
	const char* dynamics[] = {
		"dynamics",
		"pp",
		"p",
		"mp",
		"mf",
		"f",
		"ff",
		"fff"
	};
	orchidea_set_param (h, dynamics, 8);
	
	printf("orchestrating...");
	
	orchidea_throw(h, orchidea_orchestrate (h));
	printf ("done\n");
		orchidea_throw(h, orchidea_orchestrate (h));
	printf ("drrrrone\n");
	
	int orchestrations = 0;
	orchidea_num_segments(h, &orchestrations);
	for (int i = 0; i < orchestrations; ++i) {
		int solutions = 0;
		orchidea_throw(h, orchidea_solutions_per_segment(h, i, &solutions));
		printf ("segment %d: %d solution(s)\n", i, solutions);
	}
	

	const char* sound_paths[] = {
		"sound_paths",
		argv[3]
	};
	orchidea_set_param (h, sound_paths, 2);

	printf("exporting...");
	orchidea_throw(h, orchidea_export_solutions (h, "."));
	printf ("done\n");

	orchidea_destroy (h);

	return 0;
}

// EOF

