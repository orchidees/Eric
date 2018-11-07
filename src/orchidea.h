// orchidea.h - C interface
// 

#ifndef ORCHIDEA_H
#define ORCHIDEA_H 

#include "config.h"

struct OrchideaHandle; // An opaque type that we'll use as a handle
typedef struct OrchideaHandle OrchideaHandle;

// TODO:
//		- getters: features of target, source explorer?

#ifdef __cplusplus 
extern "C" {
#endif
	enum {
		ORCHIDEA_NO_ERROR,
		ORCHIDEA_TARGET_ERROR,
		ORCHIDEA_DB_ERROR,
		ORCHIDEA_INVALID_PARAMETER,
		ORCHIDEA_TARGET_NOT_DEFINED,
		ORCHIDEA_SOURCE_NOT_DEFINED,
		ORCHIDEA_SEARCH_NOT_DEFINED,
		ORCHIDEA_INVALID_SEARCH_ALGORITHM,
		ORCHIDEA_INVALID_SEGMENT,
		ORCHIDEA_NO_SOUNDS,
		ORCHIDEA_EXPORT_ERROR,
		ORCHIDEA_ORCHESTRATION_ERROR,
		ORCHIDEA_NO_INSTRUMENTS,
		ORCHIDEA_ANALYSIS_ERROR
	};
	

	#ifndef NOTIFIER_TYPE
	#define NOTIFIER_TYPE
	typedef void (*orchidea_notifier) (const char* action, float status);
	#endif

	OrchideaHandle* orchidea_create (const char* segmentation, const char* connection,
		const char* search);
	void orchidea_destroy (OrchideaHandle* h);

	void orchidea_set_notifier (OrchideaHandle* h, orchidea_notifier notifier);

	int orchidea_set_target (OrchideaHandle* h, const char* filename);
	int orchidea_set_source (OrchideaHandle* h, const char* db_path[], int size);
	const char* orchidea_dump_source (OrchideaHandle* h);

	int orchidea_set_search (OrchideaHandle* h, const char* algorithm);
	int orchidea_set_param (OrchideaHandle* h, const char* param[], int size);
	void orchidea_reset_filters (OrchideaHandle* h);

	int orchidea_orchestrate (OrchideaHandle* h);
	void orchidea_num_segments (OrchideaHandle* h, int* segments);
	int orchidea_solutions_per_segment (OrchideaHandle* h, int segment_number, 
		int* solutions);

	int orchidea_export_solutions (OrchideaHandle* h, const char* out_path);

	int orchidea_analyse_sounds (OrchideaHandle* h, const char* sound_folder, 
		const char* db_name, int bsize, int hopsize, int ncoeff, const char* feature);

	const char* orchidea_get_error_details (OrchideaHandle* h);
	const char* orchidea_decode_error (int error);
	void orchidea_throw (OrchideaHandle* h, int err); 
#ifdef __cplusplus
}
#endif

#endif	// ORCHIDEA_H 

// EOF
