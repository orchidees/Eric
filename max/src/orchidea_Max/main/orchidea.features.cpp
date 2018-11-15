/**
 @file
 orchidea.feature - database analysis for orchidea
 */

#include "analysis.h"
#include "tokenizer.h"

#include "ext.h"                            // standard Max include, always required
#include "ext_obex.h"                        // required for new style Max object

#include <deque>
#include <string>
#include <sstream>
#include <vector>
#include <string>

#include <libgen.h>
#include <pthread.h>

#define ORCHIDEA_FEATURES_MAX_THREADS 1

////////////////////////// object struct
typedef struct _session {
    t_object    ob;
    
    t_symbol*   file_name;
    long        win_size;
    long        hop_size;

    void        *out_2;
    void        *out_1;
    
    pthread_t thread_pool[ORCHIDEA_FEATURES_MAX_THREADS];
    int running_threads;
    std::vector<std::string> sounds;
    
} t_features;

typedef struct _thread_data {
    t_features* x;
    t_symbol* s;
    long ac;
    t_atom* av;
} thread_data;

///////////////////////// function prototypes
//// standard set
void *orchmax_features_new(t_symbol *s, long argc, t_atom *argv);
void orchmax_features_free(t_features *x);
void orchmax_features_assist(t_features *x, void *b, long m, long a, char *s);

void orchmax_features_anything(t_features *x, t_symbol *s, long ac, t_atom *av);
void orchmax_features_bang(t_features *x);


//////////////////////// global class pointer variable
void *orchmax_features_class;

void* orchidea_dispatcher (void* d) {
    
    thread_data* data = (thread_data*) d;
    t_features* x = data->x;
    
    t_atom busy;
    atom_setlong(&busy, 1);
    outlet_anything(x->out_2, gensym("busy"), 1, &busy);
    
    x->running_threads++;
    object_post((t_object*) x, "current thread n. %d", x->running_threads);
    
    if (strlen(x->file_name->s_name) == 0) {
        object_post((t_object*) x, "error: file name not set");
    }
    else {
        std::vector<float> features;
        compute_features<float> (x->file_name->s_name, features, x->win_size, x->hop_size, 4, "moments");
        
//        compute_features<float> (x->file_name->s_name, features,
//                                 x->win_size, x->hop_size, 4, "transients");
//
        
        t_atom out;
        
        atom_setfloat(&out, features[0]);
        outlet_anything(x->out_1, gensym("centroid"), 1, &out);
        atom_setfloat(&out, features[1]);
        outlet_anything(x->out_1, gensym("spread"), 1, &out);
        atom_setfloat(&out, features[2]);
        outlet_anything(x->out_1, gensym("skewness"), 1, &out);
        atom_setfloat(&out, features[3]);
        outlet_anything(x->out_1, gensym("kurtosis"), 1, &out);

        object_post((t_object *)x, "features have been computed correctly");
        
    }
    
    atom_setlong(&busy, 0);
    outlet_anything(x->out_2, gensym("busy"), 1, &busy);
    x->running_threads--;
    
    return NULL;
}
void ext_main(void *r) {
    t_class *c;
    
    c = class_new("orchidea.features", (method)  orchmax_features_new, (method)orchmax_features_free, (long)sizeof(t_features),
                  0L /* leave NULL!! */, A_GIMME, 0);
    
    // @description A bang triggers the orchestration.
    class_addmethod(c, (method)orchmax_features_bang,            "bang",            0);
    class_addmethod(c, (method)orchmax_features_anything,        "anything",    A_GIMME, 0);
    
    CLASS_ATTR_LONG(c, "windowsize", 0, t_features, win_size);
    CLASS_ATTR_STYLE(c, "windowsize", 0, "text");
    CLASS_ATTR_LABEL(c, "widowsize", 0, "Analysis Window Size");
    CLASS_ATTR_CATEGORY(c, "windowsize", 0, "Analysis");
    // @description Sets the size of the analysis window
    
    CLASS_ATTR_LONG(c, "hopsize", 0, t_features, hop_size);
    CLASS_ATTR_STYLE(c, "hopsize", 0, "text");
    CLASS_ATTR_LABEL(c, "hopsize", 0, "Analysis Hop Size");
    CLASS_ATTR_CATEGORY(c, "hopsize", 0, "Analysis");
    // @description Sets the hop size of the analysis
    
    class_register(CLASS_BOX, c);
    orchmax_features_class = c;
}

void orchmax_features_bang (t_features *x) {
    if (x->running_threads >= ORCHIDEA_FEATURES_MAX_THREADS) {
        object_warn((t_object*) x, "pending actions; please retry later...");
        return;
    }
    
    
    thread_data *d = (thread_data *)sysmem_newptr(sizeof(thread_data)); // delete after thread call - I think it works since thare are no modif during thread
    d->x = x;
    
    pthread_create(&x->thread_pool[x->running_threads], NULL, orchidea_dispatcher, (void*) d);
}

void orchmax_features_free(t_features *x) {
}

t_symbol *conform_path(t_symbol *path) {
    if (!path) {
        return NULL;
    }
    
    char outpath[MAX_PATH_CHARS];
    path_nameconform(path->s_name, outpath, PATH_STYLE_MAX, PATH_TYPE_BOOT);
    return gensym(outpath);
}

void orchmax_features_anything(t_features *x, t_symbol *s, long ac, t_atom *av) {
    // heavy actions are executed in a separated thread (or pool)
    if (x->running_threads >= ORCHIDEA_FEATURES_MAX_THREADS) {
        object_post((t_object*) x, "pending actions; please retry later...");
        return;
    }
    
    x->file_name = conform_path (ac == 0 ? s : atom_getsym(av));
    
    thread_data *d = (thread_data *)sysmem_newptr(sizeof(thread_data)); // delete after thread call - I think it works since thare are no modif during thread
    d->x = x;
    
    
    pthread_create(&x->thread_pool[x->running_threads], NULL, orchidea_dispatcher, (void*) d);
}

void* orchmax_features_new(t_symbol *s, long argc, t_atom *argv) {
    t_features *x = NULL;
    
    if ((x = (t_features *)object_alloc((t_class*)orchmax_features_class))) {
        
        x->running_threads = 0;

        x->win_size = 4096;
        x->hop_size = 2048;
        x->file_name = gensym("");

        attr_args_process(x, argc, argv);

        x->out_2 = outlet_new(x, NULL);
        x->out_1 = outlet_new(x, NULL);
    }
    
    return (x);
}

