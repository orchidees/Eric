/**
 @file
 orchidea.db.gen - main external for orchidea
 */

#include "orchidea.h"
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

#define ORCHIDEA_DBGEN_MAX_THREADS 1

////////////////////////// object struct
typedef struct _session {
    t_object    ob;
    
    t_symbol*   db_folder;
    long        win_size;
    long        hop_size;
    long        num_dimensions;
    t_symbol*   feature_name;
    
    void        *out_1;

    OrchideaHandle* orc_hand;
    pthread_t thread_pool[ORCHIDEA_DBGEN_MAX_THREADS];
    int running_threads;
    std::vector<std::string> sounds;
    
    
} t_dbgen;

typedef struct _thread_data {
    t_dbgen* x;
    t_symbol* s;
    long ac;
    t_atom* av;
} thread_data;

///////////////////////// function prototypes
//// standard set
void *orchmax_dbgen_new(t_symbol *s, long argc, t_atom *argv);
void orchmax_dbgen_free(t_dbgen *x);
void orchmax_dbgen_assist(t_dbgen *x, void *b, long m, long a, char *s);

void orchmax_dbgen_anything(t_dbgen *x, t_symbol *s, long ac, t_atom *av);
void orchmax_dbgen_bang(t_dbgen *x);


//////////////////////// global class pointer variable
void *orchmax_dbgen_class;

t_dbgen* g_x; // global variable - any better idea?

void notifier (const char* action, float status) {
    t_atom a[2];
    atom_setsym(a, gensym(action));
    atom_setlong(a + 1, status);
    outlet_anything(g_x->out_1, gensym("status"), 2, a);
}

void* orchidea_dispatcher (void* d) {
    
    thread_data* data = (thread_data*) d;
    t_dbgen* x = data->x;
    
    t_atom busy;
    atom_setlong(&busy, 1);
    outlet_anything(x->out_1, gensym("busy"), 1, &busy);
    
    x->running_threads++;
    object_post((t_object*) x, "current thread n. %d", x->running_threads);    

    if (strlen(x->db_folder->s_name) == 0 || strlen (x->feature_name->s_name) == 0) {
        object_post((t_object*) x, "error: feature name or db folder not set");
    }
    else {
        int r = 0;
        
        r = orchidea_analyse_sounds (x->orc_hand, x->db_folder->s_name, "/tmp/test.db",
                                         (int) x->win_size, (int) x->hop_size,
                                         (int) x->num_dimensions,
                                         x->feature_name->s_name);
        post ("MOTHERFUCKER");
        if (r != ORCHIDEA_NO_ERROR) {
            object_post((t_object *)x, "error: %s (%s)", orchidea_decode_error(r),
                        orchidea_get_error_details(x->orc_hand));
        } else {
            object_post((t_object *)x, "analysis has been done correctly");
        }

    }

    atom_setlong(&busy, 0);
    outlet_anything(x->out_1, gensym("busy"), 1, &busy);
    x->running_threads--;
    
    return NULL;
}
void ext_main(void *r) {
    t_class *c;
    
    c = class_new("orchidea.db.gen", (method)  orchmax_dbgen_new, (method)orchmax_dbgen_free, (long)sizeof(t_dbgen),
                  0L /* leave NULL!! */, A_GIMME, 0);

    // @description A bang triggers the orchestration.
    class_addmethod(c, (method)orchmax_dbgen_bang,            "bang",            0);
    class_addmethod(c, (method)orchmax_dbgen_anything,        "anything",    A_GIMME, 0);
    
    CLASS_ATTR_LONG(c, "windowsize", 0, t_dbgen, win_size);
    CLASS_ATTR_STYLE(c, "windowsize", 0, "text");
    CLASS_ATTR_LABEL(c, "widowsize", 0, "Analysis Window Size");
    // @description Sets the size of the analysis window

    CLASS_ATTR_LONG(c, "hopsize", 0, t_dbgen, hop_size);
    CLASS_ATTR_STYLE(c, "hopsize", 0, "text");
    CLASS_ATTR_LABEL(c, "hopsize", 0, "Analysis Hop Size");
    // @description Sets the hop size of the analysis

    CLASS_ATTR_LONG(c, "numdimensions", 0, t_dbgen, num_dimensions);
    CLASS_ATTR_STYLE(c, "numdimensions", 0, "text");
    CLASS_ATTR_LABEL(c, "numdimensions", 0, "Number Of Dimensions To Store");
    // @description Sets the hop size of the analysis

    
    CLASS_ATTR_SYM(c, "feature", 0, t_dbgen, feature_name);
    CLASS_ATTR_STYLE(c, "feature", 0, "text");
    CLASS_ATTR_LABEL(c, "feature", 0, "Name Of Feature");
    // @description Sets the name of the feature to be used for analysis
    
    class_register(CLASS_BOX, c);
    orchmax_dbgen_class = c;
}

void orchmax_dbgen_bang (t_dbgen *x) {
    if (x->running_threads >= ORCHIDEA_DBGEN_MAX_THREADS) {
        object_warn((t_object*) x, "pending actions; please retry later...");
        return;
    }
    

    thread_data *d = (thread_data *)sysmem_newptr(sizeof(thread_data)); // delete after thread call - I think it works since thare are no modif during thread
    d->x = x;
    
    pthread_create(&x->thread_pool[x->running_threads], NULL, orchidea_dispatcher, (void*) d);
}

void orchmax_dbgen_free(t_dbgen *x) {
    orchidea_destroy(x->orc_hand);
}

t_symbol *conform_path(t_symbol *path) {
    if (!path) {
        return NULL;
    }
    
    char outpath[MAX_PATH_CHARS];
    path_nameconform(path->s_name, outpath, PATH_STYLE_MAX, PATH_TYPE_BOOT);
    return gensym(outpath);
}

void orchmax_dbgen_anything(t_dbgen *x, t_symbol *s, long ac, t_atom *av) {
    // heavy actions are executed in a separated thread (or pool)
    if (x->running_threads >= ORCHIDEA_DBGEN_MAX_THREADS) {
        object_post((t_object*) x, "pending actions; please retry later...");
        return;
    }

    x->db_folder = conform_path (ac == 0 ? s : atom_getsym(av));

    thread_data *d = (thread_data *)sysmem_newptr(sizeof(thread_data)); // delete after thread call - I think it works since thare are no modif during thread
    d->x = x;
    

    pthread_create(&x->thread_pool[x->running_threads], NULL, orchidea_dispatcher, (void*) d);
}

void *orchmax_dbgen_new(t_symbol *s, long argc, t_atom *argv) {
    t_dbgen *x = NULL;
    
    if ((x = (t_dbgen *)object_alloc((t_class*)orchmax_dbgen_class))) {

        x->running_threads = 0;
        x->orc_hand = orchidea_create("flux", "closest");
        
        orchidea_set_notifier(x->orc_hand, notifier);
        
        x->win_size = 4096;
        x->hop_size = 2048;
        x->num_dimensions = 1024;
        x->feature_name = gensym ("spectrum");
        x->db_folder = gensym ("");
        
        attr_args_process(x, argc, argv);
        
        x->out_1 = outlet_new(x, NULL);
    }
    g_x = x;
    return (x);
}

