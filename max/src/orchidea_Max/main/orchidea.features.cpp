/**
 @file
 orchidea.features.cpp
 
 @name
 orchidea.features
 
 @realname
 orchidea.features
 
 @type
 object
 
 @module
 orchidea
 
 @author
 Carmine Emanuele Cella
 
 @digest
 Extract average descriptors from audio files
 
 @description
 Analyzes the input audio files and outputs their basic average features (centroid, spread, skewness and kurtosis).
 
 @discussion
 This object can be used to analyse a single audio file to compute basic average features. Audio files must be sampled at 44100 Hz, 16 bit.
 
 @category
 orchidea utilities
 
 @keywords
 orchestration, instrumentation, analyze, moments, centroid, spread, skewness, kurtosis, descriptors, features
 
 @seealso
 orchidea.db.gen, orchidea.solve
 
 @owner
 Carmine Emanuele Cella
 */

#include "analysis.h"
#include "tokenizer.h"
#include "orchidea.maxcommons.h"

#include <deque>
#include <string>
#include <sstream>
#include <vector>
#include <string>

#include <libgen.h>
#include <pthread.h>

#define ORCHIDEA_FEATURES_MAX_THREADS 1
#define ORCHIDEA_FEATURES_MAX_FILENAMES 8192
#define ORCHIDEA_FEATURES_MAX_OUTLETS 64

////////////////////////// object struct
typedef struct _session {
    t_object    ob;
    
    t_symbol*   filenames[ORCHIDEA_FEATURES_MAX_FILENAMES];
    long        filenames_size;
    
    long        features[ORCHIDEA_FEATURES_MAX_OUTLETS]; // one of the e_orchidea_features
    long        features_size;
    
    long        win_size;
    long        hop_size;

    void        *out[ORCHIDEA_FEATURES_MAX_OUTLETS+1];
    long        num_outlets;
    
    char        parallel;
    char        verbose;
    
    pthread_t thread_pool[ORCHIDEA_FEATURES_MAX_THREADS];
    int running_threads;
    std::vector<std::string> sounds;
    
} t_features;

typedef enum _orchidea_features {
    ORCHFEAT_NONE = 0,
    ORCHFEAT_CENTROID = 1,
    ORCHFEAT_SPREAD = 2,
    ORCHFEAT_SKEWNESS = 3,
    ORCHFEAT_KURTOSIS = 4,
} e_orchidea_features;


///////////////////////// function prototypes
//// standard set
void *orchmax_features_new(t_symbol *s, long argc, t_atom *argv);
void orchmax_features_free(t_features *x);
void orchmax_features_assist(t_features *x, void *b, long m, long a, char *s);
void orchmax_features_inletinfo(t_features *x, void *b, long a, char *t);

void orchmax_features_anything(t_features *x, t_symbol *s, long ac, t_atom *av);
void orchmax_features_bang(t_features *x);


//////////////////////// global class pointer variable
void *orchmax_features_class;


long feature_symbol_to_long(t_symbol *s)
{
    if (s == gensym("centroid"))
        return ORCHFEAT_CENTROID;
    if (s == gensym("spread"))
        return ORCHFEAT_SPREAD;
    if (s == gensym("skewness"))
        return ORCHFEAT_SKEWNESS;
    if (s == gensym("kurtosis"))
        return ORCHFEAT_KURTOSIS;
    return ORCHFEAT_NONE;
}

void orchmax_features_send_busy_zero(t_features *x, t_symbol *s, long ac, t_atom *av) {
    t_atom busy;
    atom_setlong(&busy, 0);
    outlet_anything(x->out[x->num_outlets-1], gensym("busy"), 1, &busy);
}


void orchidea_features_outlet_do(t_features *x, long outlet_num, long ac, t_atom *av) {
    if (ac == 1) {
        outlet_float(x->out[outlet_num], atom_getfloat(av));
    } else {
        outlet_list(x->out[outlet_num], NULL, ac, av);
    }
}

void* orchidea_dispatcher (void* d) {
    
    thread_data* data = (thread_data*) d;
    t_features* x = (t_features *)data->x;
    
    t_atom busy;
    atom_setlong(&busy, 1);
    outlet_anything(x->out[x->num_outlets-1], gensym("busy"), 1, &busy);
    
    if (x->parallel) {
        x->running_threads++;
        object_post((t_object*) x, "current thread n. %d", x->running_threads);
    }
    
    if (x->filenames_size == 0) {
        object_error((t_object*) x, "error: file name(s) not set");
    }
    else {
        t_atom *outlet_features[ORCHIDEA_FEATURES_MAX_OUTLETS];
        for (long i = 0; i < x->features_size; i++) {
            outlet_features[i] = (t_atom *)sysmem_newptr(x->filenames_size * sizeof(t_atom));
        }
        try {
            for (long i = 0; i < x->filenames_size; i++) {
                std::vector<float> features;
                if (x->filenames[i]) {
                    compute_features<float> (x->filenames[i]->s_name, features, x->win_size, x->hop_size, 4, "moments");
                    
                    //        compute_features<float> (x->file_name->s_name, features,
                    //                                 x->win_size, x->hop_size, 4, "transients");
                    //
                    
                    
                    for (long j = 0; j < x->features_size; j++) {
                        switch (x->features[j]) {
                            case ORCHFEAT_CENTROID:
                                atom_setfloat(outlet_features[j] + i, features[0]);
                                break;
                            case ORCHFEAT_SPREAD:
                                atom_setfloat(outlet_features[j] + i, features[1]);
                                break;
                            case ORCHFEAT_SKEWNESS:
                                atom_setfloat(outlet_features[j] + i, features[2]);
                                break;
                            case ORCHFEAT_KURTOSIS:
                                atom_setfloat(outlet_features[j] + i, features[3]);
                                break;
                            default:
                                atom_setfloat(outlet_features[j] + i, 0);
                                break;
                        }
                    }
                } else {
                    for (long j = 0; j < x->features_size; j++)
                        atom_setfloat(outlet_features[j] + i, 0);
                }
 
            }
            
            for (long i = x->num_outlets-2; i >= 0; i--)
                orchidea_features_outlet_do(x, i, x->filenames_size, outlet_features[i]);

            
            for (long i = 0; i < x->features_size; i++)
                sysmem_freeptr(outlet_features[i]);

            //        object_post((t_object *)x, "features have been computed correctly");

        } catch (std::exception& e){
            object_error((t_object *)x, "error: %s", e.what ());
        }
    }
    
    if (x->parallel) {
        x->running_threads--;
    }

    defer_low(x, (method)orchmax_features_send_busy_zero, NULL, 0, NULL);

    return NULL;
}
void ext_main(void *r) {
    t_class *c;
    
    c = class_new("orchidea.features", (method)  orchmax_features_new, (method)orchmax_features_free, (long)sizeof(t_features),
                  0L /* leave NULL!! */, A_GIMME, 0);
    
    // @method symbol/list @digest Set files and compute features
    // @description A symbol or a list in the left inlet sets the name or path of the file or files on which the features should be computed, triggers
    // the computation and outputs the result. Each feature is output through its corresponding outlet.
    class_addmethod(c, (method)orchmax_features_anything,        "anything",    A_GIMME, 0);

    // @method bang @digest Compute features
    // @description When a <m>bang</m> is received, the features are recomputed on the last input files.
    class_addmethod(c, (method)orchmax_features_bang,            "bang",            0);

    class_addmethod(c, (method)orchmax_features_assist,    "assist",        A_CANT,        0);
    class_addmethod(c, (method)orchmax_features_inletinfo,    "inletinfo",    A_CANT,        0);

    
    CLASS_ATTR_LONG(c, "windowsize", 0, t_features, win_size);
    CLASS_ATTR_STYLE(c, "windowsize", 0, "text");
    CLASS_ATTR_LABEL(c, "windowsize", 0, "Analysis Window Size");
    CLASS_ATTR_CATEGORY(c, "windowsize", 0, "Analysis");
    CLASS_ATTR_BASIC(c, "windowsize", 0);
    // @description Sets the size of the analysis window.
    
    CLASS_ATTR_LONG(c, "hopsize", 0, t_features, hop_size);
    CLASS_ATTR_STYLE(c, "hopsize", 0, "text");
    CLASS_ATTR_LABEL(c, "hopsize", 0, "Analysis Hop Size");
    CLASS_ATTR_CATEGORY(c, "hopsize", 0, "Analysis");
    CLASS_ATTR_BASIC(c, "hopsize", 0);
    // @description Sets the hop size of the analysis.
    
    CLASS_ATTR_CHAR(c, "verbose", 0, t_features, verbose);
    CLASS_ATTR_STYLE(c, "verbose", 0, "onoff");
    CLASS_ATTR_LABEL(c, "verbose", 0, "Verbose");
    // @description Toggles the verbose mode.
    
    CLASS_ATTR_CHAR(c, "parallel", 0, t_features, parallel);
    CLASS_ATTR_STYLE(c, "parallel", 0, "onoff");
    CLASS_ATTR_LABEL(c, "parallel", 0, "Parallel");
    // @description When this attribute is 1, the computations are performed in a separate thread. <br />
    // This is beyond the edge of legality in Max, so use this at your own risk: for instance, don't modify the object or close the patch while running,
    // because this will more than likely cause crashes.

    
    class_register(CLASS_BOX, c);
    orchmax_features_class = c;
}

void orchmax_features_bang_do(t_features *x, t_symbol *s, long ac, t_atom *av) {

    if (x->running_threads >= ORCHIDEA_FEATURES_MAX_THREADS) {
        object_warn((t_object*) x, "pending actions; please retry later...");
        return;
    }
    
    
    thread_data *d = (thread_data *)sysmem_newptr(sizeof(thread_data)); // delete after thread call - I think it works since thare are no modif during thread
    d->x = (t_object *)x;
    
    if (x->parallel) {
        pthread_create(&x->thread_pool[x->running_threads], NULL, orchidea_dispatcher, (void*) d);
    } else {
        orchidea_dispatcher(d);
    }
}

void orchmax_features_bang(t_features *x) {
    defer(x, (method)orchmax_features_bang_do, NULL, 0, NULL);
}

void orchmax_features_free(t_features *x) {
}


void orchmax_features_assist(t_features *x, void *b, long m, long a, char *s)
{
    if (m == ASSIST_INLET) {
        sprintf(s, "symbol: Filename(s)"); // @in 0 @type symbol @digest Name of file or files to be analyzed
    } else {
        if (a == 0)
            sprintf(s, "list: Features"); // @out 0 @loop 1 @type float/list @digest Computed features
                                          // @description For each argument, an outlet is created that will outpu the feature described by that argument.
        else
            sprintf(s, "anything: Notifications"); // @out 1 @type anything @digest Notifications
    }
}


void orchmax_features_inletinfo(t_features *x, void *b, long a, char *t)
{
    if (a)
        *t = 1;
}



void orchmax_features_anything_do(t_features *x, t_symbol *s, long ac, t_atom *av) {
    // heavy actions are executed in a separated thread (or pool)
    if (x->running_threads >= ORCHIDEA_FEATURES_MAX_THREADS) {
        object_post((t_object*) x, "pending actions; please retry later...");
        return;
    }

    x->filenames_size = 0;
    if (ac == 0) {
        if (s) {
            x->filenames[0] = orchidea_ezlocate_file(s);
            x->filenames_size = 1;
        }
    } else {
        if (s != gensym("list")) {
            x->filenames[x->filenames_size++] = orchidea_ezlocate_file(s);
        }
        for (long i = 0; i < ac; i++) {
            if (atom_gettype(av + i) == A_SYM) {
                x->filenames[x->filenames_size++] = orchidea_ezlocate_file(atom_getsym(av + i));
            } else {
                object_warn((t_object *)x, "non-symbol atom introduced, will be ignored");
            }
        }
    }
    
    thread_data *d = (thread_data *)sysmem_newptr(sizeof(thread_data)); // delete after thread call - I think it works since thare are no modif during thread
    d->x = (t_object *)x;
    
    if (x->parallel) {
        pthread_create(&x->thread_pool[x->running_threads], NULL, orchidea_dispatcher, (void*) d);
    } else {
        orchidea_dispatcher(d);
    }
}

void orchmax_features_anything(t_features *x, t_symbol *s, long ac, t_atom *av) {
    defer(x, (method)orchmax_features_anything_do, s, ac, av);
}

void* orchmax_features_new(t_symbol *s, long argc, t_atom *argv) {
    t_features *x = NULL;
    long true_ac = attr_args_offset(argc, argv);

    if ((x = (t_features *)object_alloc((t_class*)orchmax_features_class))) {
        
        x->running_threads = 0;

        x->win_size = 4096;
        x->hop_size = 2048;
        x->filenames_size = 0;
        
        x->parallel = 0;
        x->verbose = 0;
        
        if (true_ac) {
            
            attr_args_process(x, argc, argv);
            
            if (true_ac > ORCHIDEA_FEATURES_MAX_OUTLETS - 1) {
                true_ac = ORCHIDEA_FEATURES_MAX_OUTLETS - 1;
            }
            
            x->num_outlets = true_ac + 1;
            x->features_size = true_ac;
            x->out[x->num_outlets - 1] = outlet_new(x, NULL); // notification outlet

            // @arg 0 @name features @type symbol/list @digest Features
            // @description The names of the features to retrieve. For each of the feature, a dedicated outlet is created that will output it.
            // Features can be one of the following symbols: "centroid", "spread", "skewness", "kurtosis".
            
            for (long i = true_ac - 1; i >= 0; i--) {
                if (atom_gettype(argv+i) == A_SYM) {
                    t_symbol *feature_sym = atom_getsym(argv+i);
                    long feature_as_long = feature_symbol_to_long(feature_sym);
                    if (feature_as_long != ORCHFEAT_NONE) {
                        x->features[i] = feature_as_long;
                    } else {
                        object_error((t_object *)x, "error: unknown feature '%s'", feature_sym ? feature_sym->s_name : "");
                        x->features[i] = ORCHFEAT_NONE;
                        return NULL;
                    }
                } else {
                    object_warn((t_object *)x, "error: non-symbol feature detected");
                    x->features[i] = ORCHFEAT_NONE;
                    return NULL;
                }
                x->out[i] = outlet_new(x, NULL);
            }
            
            
        } else {
            object_error((t_object *)x, "error: no features defined as arguments");
            return NULL;
        }
    }
    
    return (x);
}


