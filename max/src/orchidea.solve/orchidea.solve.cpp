/**
	@file
	orchidea.solve - main external for orchidea
*/

#include "orchidea.h"
#include "tokenizer.h"
#include "utilities.h"

#include "ext.h"							// standard Max include, always required
#include "ext_obex.h"						// required for new style Max object

#include <deque>
#include <string>
#include <sstream>

#include <libgen.h>
#include <pthread.h>

#define MAX_THREADS 1
#define MAX_SOUND_PATHS 256

////////////////////////// object struct
typedef struct _solver {
    t_object	ob;

    // Static attributes
    t_symbol*   segmentation;
    t_symbol*   connection;
    
    // Dynamic attributes
    t_symbol*   soundpaths[MAX_SOUND_PATHS];
    long        soundpaths_size;
    
    
    
    void		*out_1;
    
    char        must_rerun_analysis;
    t_symbol*   current_target;

    OrchideaHandle* orc_hand;
    pthread_t thread_pool[MAX_THREADS];
    int running_threads;
    
    void*       n_proxy[2];
    long        n_in;
} t_solver;

typedef struct _thread_data {
    t_solver* x;
    t_symbol* s;
    long ac;
    t_atom* av;
} thread_data;

///////////////////////// function prototypes
//// standard set
void *orchmax_solve_new(t_symbol *s, long argc, t_atom *argv);
void orchmax_solve_free(t_solver *x);
void orchmax_solve_assist(t_solver *x, void *b, long m, long a, char *s);

void orchmax_solve_anything(t_solver *x, t_symbol *s, long ac, t_atom *av);
void orchmax_solve_bang(t_solver *x);


//////////////////////// global class pointer variable
void *orchmax_solve_class;


t_solver* g_x; // global variable - any better idea?


void notifier (const char* action, float status) {
    t_atom a[2];
    atom_setsym(a, gensym(action));
    atom_setlong(a + 1, status);
    outlet_anything(g_x->out_1, gensym("status"), 2, a);
}



// will take care of freeing data->av after usage, if not NULL
void* orchidea_dispatcher (void* d) {
    thread_data* data = (thread_data*) d;
    t_solver* x = data->x;
    t_symbol* s = data->s;
    t_atom* av = data->av;
    long ac = data->ac;

    t_atom busy;
    atom_setlong(&busy, 1);
    outlet_anything(x->out_1, gensym("busy"), 1, &busy);

    x->running_threads++;
    object_post((t_object*) x, "current thread n. %d", x->running_threads);

    t_symbol* argument = 0;

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

    if (s == gensym("dbfiles")) {
        argument = atom_getsym(av);
        char** sl  = (char**) malloc ((ac) * sizeof (char*));
        for (int i = 0; i < ac; ++i) {
            sl[i] = atom_getsym(av + i)->s_name;
            object_post((t_object*) x, "adding db file %s", sl[i]);
        }
        
        int r = orchidea_set_source(x->orc_hand, (const char**) sl, (int) ac);
        
        if (r != ORCHIDEA_NO_ERROR) {
            object_post((t_object *)x, "error: %s (%s)", orchidea_decode_error(r),
                        orchidea_get_error_details(x->orc_hand));
        }
        
        else {
            t_atom val;
            std::stringstream ss;
            ss << (std::string) orchidea_dump_source(x->orc_hand);
            post ("%s", ss.str ().c_str ());
//            while (!ss.eof ()) {
//                std::string line;
//                std::getline(ss, line);
                atom_setsym(&val, gensym(ss.str ().c_str ()));
                outlet_anything(x->out_1, gensym ("source"), 1, &val);
//            }

            object_post((t_object *)x, "db files have been set correctly");
        }
        free (sl);
    }
    else if (s == gensym ("orchestrate") || s == gensym("target")) {
        
        // DIRTY STUFF BY DANIELE, SORRY GUYS!
        if (s == gensym("target")) {
            argument = atom_getsym(av);
            if (x->current_target != argument) { // filename has changed
                // first analysis of target
                x->current_target = argument;
                object_post((t_object *)x, "setting target to %s...", argument->s_name);
                int r = orchidea_set_target(x->orc_hand, argument->s_name);
                if (r != ORCHIDEA_NO_ERROR) {
                    object_post((t_object *)x, "error: %s (%s)", orchidea_decode_error(r), orchidea_get_error_details(x->orc_hand));
                } else object_post((t_object *)x, "target has been set correctly");
                x->must_rerun_analysis = false;
            }
        }
        
        if (x->must_rerun_analysis) {
            // reanalysis of target
            int r = orchidea_set_target(x->orc_hand, x->current_target->s_name);
            if (r != ORCHIDEA_NO_ERROR) {
                object_post((t_object *)x, "error: %s (%s)", orchidea_decode_error(r), orchidea_get_error_details(x->orc_hand));
            } else object_post((t_object *)x, "target has been reanalysed correctly");
            x->must_rerun_analysis = false;
        }
        
        object_post((t_object*) x, "start orchestration");
        int r = orchidea_orchestrate(x->orc_hand);
        if (r != ORCHIDEA_NO_ERROR) {
            object_post((t_object *)x, "error: %s (%s)", orchidea_decode_error(r), orchidea_get_error_details(x->orc_hand));
        } else {
            system ("rm target*"); // FIXME: any better idea??
            system ("rm connection*"); // FIXME: any better idea??
            int n = 0;
            orchidea_num_segments(x->orc_hand, &n);
            for (unsigned i = 0; i < n; ++i) {
                int sols = 0;
                orchidea_solutions_per_segment(x->orc_hand, i, &sols);
                post ("seg %d, sols %d", i, sols);
            }
            r = orchidea_export_solutions(x->orc_hand, ".");
            object_post((t_object *)x, "%d segments(s) found", n);
            if (r != ORCHIDEA_NO_ERROR) {
                object_post((t_object *)x, "error: %s (%s)", orchidea_decode_error(r), orchidea_get_error_details(x->orc_hand));
            } else {
                t_atom vals;
                atom_setlong (&vals, n); // FIXME!!!
                outlet_anything(x->out_1, gensym("nb_solutions"),  1, &vals);

//                std::string sols = orchidea_get_last_solutions(x->orc_hand);
//                std::deque<std::string> sol_vector;
//                tokenize(sols, sol_vector, ">");
//                for (unsigned i = 0; i < sol_vector.size (); ++i) {
//                    atom_setsym (&vals, gensym(sol_vector[i].c_str ()));
//                    object_post((t_object*) x, "%s", sol_vector[i].c_str ());
//                    outlet_anything(x->out_1, gensym("solution"),  1, &vals);
//                }
            }
        }
    }
    atom_setlong(&busy, 0);
    outlet_anything(x->out_1, gensym("busy"), 1, &busy);
    x->running_threads--;
    
    if (data->av)
        sysmem_freeptr(data->av);
    
    return NULL;
}




//
//t_max_err orchmax_solve_notify(t_solver *x, t_symbol *s, t_symbol *msg, void *sender, void *data) {
//    t_symbol *attrname;
//    if (msg == gensym("attr_modified")) {       // check notification type
//        attrname = (t_symbol *)object_method((t_object *)data, gensym("getname"));      // ask attribute object for name
//        object_post((t_object *)x, "changed attr name is %s",attrname->s_name);
//    }
//    return 0;
//}

void ext_main(void *r) {
    t_class *c;

    c = class_new("orchidea.solve", (method)orchmax_solve_new, (method)orchmax_solve_free, (long)sizeof(t_solver),
                  0L /* leave NULL!! */, A_GIMME, 0);

    // @method bang @digest Orchestrate
    // @description A bang triggers the orchestration.
    class_addmethod(c, (method)orchmax_solve_bang,            "bang",            0);
    class_addmethod(c, (method)orchmax_solve_anything,        "anything",    A_GIMME, 0);

    class_addmethod(c, (method)orchmax_solve_anything,        "search",    A_GIMME, 0);             // -> symbol
    class_addmethod(c, (method)orchmax_solve_anything,        "popsize", A_GIMME, 0);               // -> intero
    class_addmethod(c, (method)orchmax_solve_anything,        "maxepochs", A_GIMME, 0);             // -> intero
    class_addmethod(c, (method)orchmax_solve_anything,        "pursuit", A_GIMME, 0);               // -> intero
    class_addmethod(c, (method)orchmax_solve_anything,        "xoverrate", A_GIMME, 0);             // -> float (0-1)
    class_addmethod(c, (method)orchmax_solve_anything,        "mutatioinrate", A_GIMME, 0);         // -> float (0-1)
    class_addmethod(c, (method)orchmax_solve_anything,        "sparsity", A_GIMME, 0);              // -> float (0-1)
    class_addmethod(c, (method)orchmax_solve_anything,        "onsetsthreshold", A_GIMME, 0);       // -> float (anche > 1)
    class_addmethod(c, (method)orchmax_solve_anything,        "onsetstimegate", A_GIMME, 0);        // -> intero (in ms)
    class_addmethod(c, (method)orchmax_solve_anything,        "positivepenalization", A_GIMME, 0);  // -> float
    class_addmethod(c, (method)orchmax_solve_anything,        "negativepenalization", A_GIMME, 0);  // -> float
    class_addmethod(c, (method)orchmax_solve_anything,        "partialswindow", A_GIMME, 0);        // -> intero
    class_addmethod(c, (method)orchmax_solve_anything,        "partialsfilter", A_GIMME, 0);        // -> float (0-1)
    class_addmethod(c, (method)orchmax_solve_anything,        "orchestra",    A_GIMME, 0);          // -> sym_array (max 4096)
    class_addmethod(c, (method)orchmax_solve_anything,        "styles",    A_GIMME, 0);             // -> sym_array (max 4096)
    class_addmethod(c, (method)orchmax_solve_anything,        "dynamics",    A_GIMME, 0);           // -> sym_array (max 4096)
    class_addmethod(c, (method)orchmax_solve_anything,        "others",    A_GIMME, 0);             // -> sym_array (max 4096)
    class_addmethod(c, (method)orchmax_solve_anything,        "extrapitches",    A_GIMME, 0);       // -> sym_array (max 4096)
    class_addmethod(c, (method)orchmax_solve_anything,        "resetfilters",    A_GIMME, 0);  //-> messaggio
    
//    class_addmethod(c, (method)orchmax_solve_notify, "notify", A_CANT, 0);
    CLASS_ATTR_SYM(c, "segmentation", 0, t_solver, segmentation);
    CLASS_ATTR_SYM(c, "connection", 0, t_solver, connection);
    CLASS_ATTR_SYM_VARSIZE(c, "soundpaths", 0, t_solver, soundpaths, soundpaths_size, MAX_SOUND_PATHS);
    
//    CLASS_ATTR_SYM(c, "name", 0, t_solver, name);

    class_register(CLASS_BOX, c);
    orchmax_solve_class = c;
}

void orchmax_solve_free(t_solver *x) {
    long i;
    for (i = 1; i < 2; i++)
        object_free(x->n_proxy[i]);

    orchidea_destroy(x->orc_hand);
}

void orchmax_solve_bang(t_solver *x) {
    if (x->running_threads >= MAX_THREADS) {
        object_post((t_object*) x, "pending actions; please retry later...");
        return;
    }
    
    thread_data d; // delete after thread call - I think it works since thare are no modif during thread
    d.x = x;
    d.s = gensym("orchestrate");
    d.ac = 0;
    d.av = NULL;
    
    atom_setsym(d.av, gensym("orchestrate"));
    
    pthread_create(&x->thread_pool[x->running_threads], NULL, orchidea_dispatcher, (void*) &d);
}


// suppose soundpath is allocated with
void dbpath_to_soundpath(char *dbpath, char *soundpath)
{
    std::string src(dbpath);
    std::string out = removeExtension(removeExtension(src)); // intentional double call: the name should be XXXXXXX.featurename.db -> let's remove the last two parts
    snprintf(soundpath, MAX_PATH_CHARS, "%s", out.c_str());
}

void orchmax_solve_anything(t_solver *x, t_symbol *s, long ac, t_atom *av) {
    t_symbol* argument = 0;
    
//    t_object *patcher;
//    object_obex_lookup(x, gensym("#P"), &patcher);
//    t_symbol *path = object_attr_getsym(patcher, gensym("filepath"));
//    char outname[1024];
//    char* location = 0;
//    if (path != NULL) {
//        path_nameconform(path->s_name, outname, PATH_STYLE_MAX, PATH_TYPE_BOOT);
//        location = dirname (outname);
//    } else {
//        location = (char*) malloc(1024);
//        location = (char*) ".";
//    }
//
//    //post ("setting current location to: %s", location);
//    chdir(location);
//
    if (s == gensym("search")) {
        argument = atom_getsym(av);
        object_post((t_object *)x, "setting search to %s", argument->s_name);
        int r = orchidea_set_search(x->orc_hand, argument->s_name);
        if (r != ORCHIDEA_NO_ERROR) {
            object_post((t_object *)x, "error: %s (%s)", orchidea_decode_error(r),
                        orchidea_get_error_details(x->orc_hand));
        } else object_post((t_object *)x, "search has been set correctly");
    } else if (s == gensym("popsize")) {
        argument = atom_getsym(av);
        char** sl  = (char**)sysmem_newptr(2 * sizeof (char*));
        sl[0] = (char*) "pop_size";
        sl[1] = (char*) argument->s_name;
        orchidea_set_param(x->orc_hand, (const char**) sl, (int) 2);
        object_post((t_object *)x, "population size has been set correctly");
        sysmem_freeptr(sl);
    }
    else if (s == gensym("maxepochs")) {
        argument = atom_getsym(av);
        char** sl  = (char**) malloc (2 * sizeof (char*));
        sl[0] = (char*) "max_epochs";
        sl[1] = (char*) argument->s_name;
        orchidea_set_param(x->orc_hand, (const char**) sl, (int) 2);
        object_post((t_object *)x, "max number of epochs has been set correctly");
        free (sl);
    }
    else if (s == gensym("xoverrate")) {
        argument = atom_getsym(av);
        char** sl  = (char**) malloc (2 * sizeof (char*));
        sl[0] = (char*) "xover_rate";
        sl[1] = (char*) argument->s_name;
        orchidea_set_param(x->orc_hand, (const char**) sl, (int) 2);
        object_post((t_object *)x, "cross-over rate has been set correctly");
        free (sl);
    }
    else if (s == gensym("mutationrate")) {
        argument = atom_getsym(av);
        char** sl  = (char**) malloc (2 * sizeof (char*));
        sl[0] = (char*) "mutation_rate";
        sl[1] = (char*) argument->s_name;
        orchidea_set_param(x->orc_hand, (const char**) sl, (int) 2);
        object_post((t_object *)x, "mutation rate has been set correctly");
        free (sl);
    }
    else if (s == gensym("pursuit")) {
        argument = atom_getsym(av);
        char** sl  = (char**) malloc (2 * sizeof (char*));
        sl[0] = (char*) "pursuit";
        sl[1] = (char*) argument->s_name;
        orchidea_set_param(x->orc_hand, (const char**) sl, (int) 2);
        object_post((t_object *)x, "relaxed pursuit has been set correctly");
        free (sl);
    }
    else if (s == gensym("sparsity")) {
        argument = atom_getsym(av);
        char** sl  = (char**) malloc (2 * sizeof (char*));
        sl[0] = (char*) "sparsity";
        sl[1] = (char*) argument->s_name;
        orchidea_set_param(x->orc_hand, (const char**) sl, (int) 2);
        object_post((t_object *)x, "sparsity has been set correctly");
        free (sl);
    }
    else if (s == gensym("negativepenalization")) {
        argument = atom_getsym(av);
        char** sl  = (char**) malloc (2 * sizeof (char*));
        sl[0] = (char*) "negative_penalization";
        sl[1] = (char*) argument->s_name;
        orchidea_set_param(x->orc_hand, (const char**) sl, (int) 2);
        object_post((t_object *)x, "negative penalization has been set correctly");
        free (sl);
    }
    else if (s == gensym("positivepenalization")) {
        argument = atom_getsym(av);
        char** sl  = (char**) malloc (2 * sizeof (char*));
        sl[0] = (char*) "positive_penalization";
        sl[1] = (char*) argument->s_name;
        orchidea_set_param(x->orc_hand, (const char**) sl, (int) 2);
        object_post((t_object *)x, "positive penalization has been set correctly");
        free (sl);
    }
    else if (s == gensym("onsetsthreshold")) {
        argument = atom_getsym(av);
        char** sl  = (char**) malloc (2 * sizeof (char*));
        sl[0] = (char*) "onsets_threshold";
        sl[1] = (char*) argument->s_name;
        post ("%s, %g, %s, %s", sl[1], atof (sl[1]), argument->s_name,
              atom_getsym(av)->s_name);
        x->must_rerun_analysis = true;
        orchidea_set_param(x->orc_hand, (const char**) sl, (int) 2);
        object_post((t_object *)x, "onsets threshold has been set correctly");
        free (sl);
    }
    else if (s == gensym("onsetstimegate")) {
        argument = atom_getsym(av);
        char** sl  = (char**) malloc (2 * sizeof (char*));
        sl[0] = (char*) "onsets_timegate";
        sl[1] = (char*) argument->s_name;
        post ("%s, %g, %s, %s", sl[1], atof (sl[1]), argument->s_name,
              atom_getsym(av)->s_name);
        x->must_rerun_analysis = true;
        orchidea_set_param(x->orc_hand, (const char**) sl, (int) 2);
        object_post((t_object *)x, "onsets timegate has been set correctly");
        free (sl);
    }
    else if (s == gensym("partialswindow")) {
        argument = atom_getsym(av);
        char** sl  = (char**) malloc (2 * sizeof (char*));
        sl[0] = (char*) "partials_window";
        sl[1] = (char*) argument->s_name;
        orchidea_set_param(x->orc_hand, (const char**) sl, (int) 2);
        object_post((t_object *)x, "partials window has been set correctly");
        free (sl);
    }
    else if (s == gensym("partialsfilter")) {
        argument = atom_getsym(av);
        char** sl  = (char**) malloc (2 * sizeof (char*));
        sl[0] = (char*) "partials_filter";
        sl[1] = (char*) argument->s_name;
        orchidea_set_param(x->orc_hand, (const char**) sl, (int) 2);
        object_post((t_object *)x, "partials filter has been set correctly");
        free (sl);
    }
    else if (s == gensym("soundpaths")) {
        argument = atom_getsym(av);
        char** sl  = (char**) malloc ((ac + 1) * sizeof (char*));

        sl[0] = (char*) "sound_paths";
        for (int i = 0; i < ac; ++i) {
            t_symbol *this_path = atom_getsym(av + i);
            sl[i + 1] = this_path->s_name;
            x->soundpaths[i] = this_path;
            object_post((t_object*) x, "adding sound folder %s", sl[i + 1]);
        }
        x->soundpaths_size = ac;


        orchidea_set_param(x->orc_hand, (const char**) sl, (int) ac + 1);
        object_post((t_object *)x, "sounds have been set correctly");
        free (sl);
    }
    else if (s == gensym("orchestra")) {
        argument = atom_getsym(av);
        char** sl  = (char**) malloc ((ac + 1) * sizeof (char*));

        sl[0] = (char*) "orchestra";
        for (int i = 0; i < ac; ++i) {
            sl[i + 1] = atom_getsym(av + i)->s_name;
            object_post((t_object*) x, "setting instrument %s", sl[i + 1]);
        }

        orchidea_set_param(x->orc_hand, (const char**) sl, (int) ac + 1);
        object_post((t_object *)x, "orchestra has been set correctly");
        free (sl);
    }
    else if (s == gensym("styles")) {
        argument = atom_getsym(av);
        char** sl  = (char**) malloc ((ac + 1) * sizeof (char*));

        sl[0] = (char*) "styles";
        for (int i = 0; i < ac; ++i) {
            sl[i + 1] = atom_getsym(av + i)->s_name;
            object_post((t_object*) x, "setting style %s", sl[i + 1]);
        }

        orchidea_set_param(x->orc_hand, (const char**) sl, (int) ac + 1);
        object_post((t_object *)x, "styles have been set correctly");
        free (sl);
    }
    else if (s == gensym("dynamics")) {
        argument = atom_getsym(av);
        char** sl  = (char**) malloc ((ac + 1) * sizeof (char*));

        sl[0] = (char*) "dynamics";
        for (int i = 0; i < ac; ++i) {
            sl[i + 1] = atom_getsym(av + i)->s_name;
            object_post((t_object*) x, "setting dynamics %s", sl[i + 1]);
        }

        orchidea_set_param(x->orc_hand, (const char**) sl, (int) ac + 1);
        object_post((t_object *)x, "dynamics have been set correctly");
        free (sl);
    }
    else if (s == gensym("others")) {
        argument = atom_getsym(av);
        char** sl  = (char**) malloc ((ac + 1) * sizeof (char*));
        
        sl[0] = (char*) "others";
        for (int i = 0; i < ac; ++i) {
            sl[i + 1] = atom_getsym(av + i)->s_name;
            object_post((t_object*) x, "setting other filter %s", sl[i + 1]);
        }
        
        orchidea_set_param(x->orc_hand, (const char**) sl, (int) ac + 1);
        object_post((t_object *)x, "other filters have been set correctly");
        free (sl);
    }
    else if (s == gensym("extrapitches")) {
        argument = atom_getsym(av);
        char** sl  = (char**) malloc ((ac + 1) * sizeof (char*));
        
        sl[0] = (char*) "extra_pitches";
        for (int i = 0; i < ac; ++i) {
            sl[i + 1] = atom_getsym(av + i)->s_name;
            object_post((t_object*) x, "adding extra pitch %s", sl[i + 1]);
        }
        
        orchidea_set_param(x->orc_hand, (const char**) sl, (int) ac + 1);
        object_post((t_object *)x, "extra pitches have been set correctly");
        free (sl);
    }
    else if (s == gensym("resetfilters")) {
        object_post((t_object*) x, "resetting all filters");

        orchidea_reset_filters(x->orc_hand);
        
    } else {
        long inlet = proxy_getinlet((t_object *) x);

        // heavy actions are executed in a separated thread (or pool)
        if (x->running_threads >= MAX_THREADS) {
            object_post((t_object*) x, "pending actions; please retry later...");
            return;
        }

        thread_data d; // delete after thread call - I think it works since thare are no modif during thread
        d.x = x;
        
        if (inlet == 0) {
            // set target and orchestrate
            d.s = gensym("target");
            d.ac = 1;
            d.av = (t_atom *)sysmem_newptr(sizeof(t_atom));
            atom_setsym(d.av, s ? s : (ac ? atom_getsym(av) : gensym("none") /*should never happen*/));
        } else {
            // set database
            long j = 0;
            d.s = gensym("dbfiles");
            d.ac = (s && s != gensym("list") ? ac + 1 : ac);
            d.av = (t_atom *)sysmem_newptr(d.ac * sizeof(t_atom));
            if (s && s != gensym("list")) {
                atom_setsym(d.av, s);
                j++;
            }
            for (long i = 0; i < ac; i++)
                d.av[j++] = av[i];
            
            // setting sound paths properly, if soundpaths is default
            char** sl  = (char**)sysmem_newptr((ac + 1) * sizeof (char*));
            sl[0] = (char*) "sound_paths";
            for (long i = 1; i < ac + 1; i++) {
                sl[i] = (char *)sysmem_newptr(MAX_PATH_CHARS * sizeof(char));
            }
            for (long i = 0; i < d.ac; i++) { // cycle on each of the db file names
                if (i >= x->soundpaths_size || x->soundpaths[i] == gensym("default")) { // if the soundpath attribute is "default"
                    t_symbol *this_path = atom_getsym(d.av+i); // take the current db filename
                    if (this_path) {
                        dbpath_to_soundpath(this_path->s_name, sl[i+1]); // if it exists (should ALWAYS be the case), strip it
                    } else {
                        snprintf_zero(sl[i+1], MAX_PATH_CHARS, "%s", x->soundpaths[i]->s_name);
                    }
                } else {
                    snprintf_zero(sl[i+1], MAX_PATH_CHARS, "%s", x->soundpaths[i]->s_name);
                }
            }
            orchidea_set_param(x->orc_hand, (const char**) sl, (int) ac + 1);
            object_post((t_object *)x, "sounds have been set correctly");
            for (long i = 1; i < ac + 1; i++) {
                sysmem_freeptr(sl[i]);
            }
            sysmem_freeptr(sl);
            
        }
        pthread_create(&x->thread_pool[x->running_threads], NULL, orchidea_dispatcher, (void*) &d);
    }
}

void *orchmax_solve_new(t_symbol *s, long argc, t_atom *argv) {
    t_solver *x = NULL;
    g_x = x;
    
    if ((x = (t_solver *)object_alloc((t_class*)orchmax_solve_class))) {
//        x->name = gensym("");
//        if (argc && argv) {
//            x->name = atom_getsym(argv);
//        }
//        if (!x->name || x->name == gensym(""))
//            x->name = symbol_unique();

        // flux and closest are only hard-codable in the max object. Initializing hard-coded attributes:
        x->segmentation = gensym("flux");
        x->connection = gensym("closest");
        
        // initializing attributes:
        x->soundpaths[0] = gensym("default");
        x->soundpaths_size = 1;

        x->n_proxy[1] = proxy_new((t_object *) x, 1, &x->n_in);
        
        attr_args_process(x, argc, argv);
        
        x->running_threads = 0;
        x->orc_hand = orchidea_create (x->segmentation->s_name, x->connection->s_name);
//        x->orc_hand = orchidea_create ("flux", "closest");
        
        orchidea_set_notifier(x->orc_hand, notifier);
        
        x->out_1 = outlet_new(x, NULL);
        
    }
    g_x = x;
    return (x);
}
