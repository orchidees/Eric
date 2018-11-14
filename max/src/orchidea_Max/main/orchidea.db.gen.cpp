/**
 @file
 orchidea.dbgen - main external for orchidea
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

#define MAX_THREADS 1

////////////////////////// object struct
typedef struct _session {
    t_object    ob;
    
    t_symbol    *name;
    void        *out_1;
    
    OrchideaHandle* orc_hand;
    pthread_t thread_pool[MAX_THREADS];
    int running_threads;
    std::vector<std::string> sounds;
    t_symbol* db_folder;
    
} t_session;

typedef struct _thread_data {
    t_session* x;
    t_symbol* s;
    long ac;
    t_atom* av;
} thread_data;

///////////////////////// function prototypes
//// standard set
void *orchmax_dbgen_new(t_symbol *s, long argc, t_atom *argv);
void orchmax_dbgen_free(t_session *x);
void orchmax_dbgen_assist(t_session *x, void *b, long m, long a, char *s);

void orchmax_dbgen_anything(t_session *x, t_symbol *s, long ac, t_atom *av);
void orchmax_dbgen_bang(t_session *x);


//////////////////////// global class pointer variable
void *orchmax_dbgen_class;


t_session* g_x; // global variable - any better idea?


void notifier (const char* action, float status) {
    t_atom a[2];
    atom_setsym(a, gensym(action));
    atom_setlong(a + 1, status);
    outlet_anything(g_x->out_1, gensym("status"), 2, a);
}

void* orchidea_dispatcher (void* d) {
    
    thread_data* data = (thread_data*) d;
    t_session* x = data->x;
    t_symbol* s = data->s;
    
    t_atom busy;
    atom_setlong(&busy, 1);
    outlet_anything(x->out_1, gensym("busy"), 1, &busy);
    
    x->running_threads++;
    object_post((t_object*) x, "current thread n. %d", x->running_threads);
    
    t_object *patcher, *parent, *tmp;
    object_obex_lookup(x, gensym("#P"), &patcher);
    parent = patcher;
    do {
        tmp = jpatcher_get_parentpatcher(parent);
        if (tmp) {
            parent = tmp;
        }
    } while (tmp != NULL);
    
    t_symbol *path = object_attr_getsym(parent, gensym("filepath"));
    object_post((t_object*) x, "path: %s", path->s_name);
    
    char outname[1024];
    char* location = 0;
    if (path != NULL) {
        path_nameconform(path->s_name, outname, PATH_STYLE_MAX, PATH_TYPE_BOOT);
        location = dirname (outname);
    } else {
        location = (char*) malloc(1024);
        location = (char*) ".";
    }
    
    //post ("setting current location to: %s", location);
    chdir(location);
    
    if (s == gensym ("analyse")) {
        object_post((t_object*) x, "start analysis");
        
        if (x->sounds.size () == 0 || strlen(x->db_folder->s_name) == 0) {
            object_post((t_object*) x, "error: sound folders or db folder not set");
            
        }
        else {
            int r = 0;
            for (unsigned i = 0; i < x->sounds.size (); ++i) {
                object_post((t_object*) x, "analysing %s...", x->sounds.at(i).c_str ());

                r = orchidea_analyse_sounds (x->orc_hand, x->db_folder->s_name, x->name->s_name,
                                                 4096, 2048, 1024, "spectrum");
                
                if (r != ORCHIDEA_NO_ERROR) {
                    object_post((t_object *)x, "error: %s (%s)", orchidea_decode_error(r), orchidea_get_error_details(x->orc_hand));
                } else {
                    object_post((t_object *)x, "analysis has been done correctly");
                }
            }
        }
    }
    atom_setlong(&busy, 0);
    outlet_anything(x->out_1, gensym("busy"), 1, &busy);
    x->running_threads--;
    return NULL;
}
void ext_main(void *r) {
    t_class *c;
    
    c = class_new("orchidea.db.gen", (method)  orchmax_dbgen_new, (method)orchmax_dbgen_free, (long)sizeof(t_session),
                  0L /* leave NULL!! */, A_GIMME, 0);
    
    class_addmethod(c, (method)orchmax_dbgen_anything,        "database",    A_GIMME, 0);
    class_addmethod(c, (method)orchmax_dbgen_anything,        "sounds",    A_GIMME, 0);
    class_addmethod(c, (method)orchmax_dbgen_anything,        "analyse",    A_GIMME, 0);
    CLASS_ATTR_SYM(c, "name", 0, t_session, name);
    
    class_register(CLASS_BOX, c);
    orchmax_dbgen_class = c;
}

void orchmax_dbgen_free(t_session *x) {
    orchidea_destroy(x->orc_hand);
}

void orchmax_dbgen_anything(t_session *x, t_symbol *s, long ac, t_atom *av) {
    t_symbol* argument = 0;
    
    t_object *patcher;
    object_obex_lookup(x, gensym("#P"), &patcher);
    t_symbol *path = object_attr_getsym(patcher, gensym("filepath"));
    char outname[1024];
    char* location = 0;
    if (path != NULL) {
        path_nameconform(path->s_name, outname, PATH_STYLE_MAX, PATH_TYPE_BOOT);
        location = dirname (outname);
    } else {
        location = (char*) malloc(1024);
        location = (char*) ".";
    }
    
    //post ("setting current location to: %s", location);
    chdir(location);
    
    if (s == gensym("sounds")) {
        argument = atom_getsym(av);
        
        x->sounds.clear ();
        for (int i = 0; i < ac; ++i) {
            x->sounds.push_back (atom_getsym(av + i)->s_name);
            object_post((t_object*) x, "adding sound folder %s", atom_getsym(av + i)->s_name);
        }
        object_post((t_object *)x, "sounds have been added correctly");
        
    } if (s == gensym("database")) {
        x->db_folder = atom_getsym(av);
        object_post((t_object *)x, "setting database to %s",  x->db_folder->s_name);
        object_post((t_object *)x, "database has been set correctly");
    }  else {
        // heavy actions are executed in a separated thread (or pool)
        if (x->running_threads >= MAX_THREADS) {
            object_post((t_object*) x, "pending actions; please retry later...");
            return;
        }
        
        thread_data d; // delete after thread call - I think it works since thare are no modif during thread
        d.x = x; d.s = s; d.ac =  ac; d.av = av;
        
        pthread_create(&x->thread_pool[x->running_threads], NULL, orchidea_dispatcher, (void*) &d);
    }
}

void *orchmax_dbgen_new(t_symbol *s, long argc, t_atom *argv) {
    t_session *x = NULL;
    
    if ((x = (t_session *)object_alloc((t_class*)orchmax_dbgen_class))) {
        x->name = gensym("");
        if (argc && argv) {
            x->name = atom_getsym(argv);
        }
        if (!x->name || x->name == gensym(""))
            x->name = symbol_unique();
        
        x->running_threads = 0;
        x->orc_hand = orchidea_create("flux", "closest");
        
        x->out_1 = outlet_new(x, NULL);
    }
    g_x = x;
    return (x);
}

