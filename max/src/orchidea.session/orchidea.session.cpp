/**
	@file
	orchidea.session - main external for orchidea
*/

#include "orchidea.h"
#include "tokenizer.h"

#include "ext.h"							// standard Max include, always required
#include "ext_obex.h"						// required for new style Max object

#include <deque>
#include <string>
#include <sstream>

#include <libgen.h>
#include <pthread.h>

#define MAX_THREADS 1

////////////////////////// object struct
typedef struct _session {
    t_object	ob;

    t_symbol	*name;
    void		*out_1;

    OrchideaHandle* orc_hand;
    pthread_t thread_pool[MAX_THREADS];
    int running_threads;
} t_session;

typedef struct _thread_data {
    t_session* x;
    t_symbol* s;
    long ac;
    t_atom* av;
} thread_data;

///////////////////////// function prototypes
//// standard set
void *orchmax_session_new(t_symbol *s, long argc, t_atom *argv);
void orchmax_session_free(t_session *x);
void orchmax_session_assist(t_session *x, void *b, long m, long a, char *s);

void orchmax_session_anything(t_session *x, t_symbol *s, long ac, t_atom *av);
void orchmax_session_bang(t_session *x);


//////////////////////// global class pointer variable
void *orchmax_session_class;


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
    t_atom* av = data->av;

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
    
    if (s == gensym("target")) {
        argument = atom_getsym(av);
        object_post((t_object *)x, "setting target to %s...", argument->s_name);
        int r = orchidea_set_target(x->orc_hand, argument->s_name, location);
        if (r != ORCHIDEA_NO_ERROR) {
            object_post((t_object *)x, "error: %s (%s)", orchidea_decode_error(r), orchidea_get_error_details(x->orc_hand));
        } else object_post((t_object *)x, "target has been set correctly");
    } else if (s == gensym("source")) {
        argument = atom_getsym(av);
        object_post((t_object *)x, "setting source to %s", argument->s_name);
        int r = orchidea_set_source(x->orc_hand, argument->s_name, location);
        if (r != ORCHIDEA_NO_ERROR) {
            object_post((t_object *)x, "error: %s (%s)", orchidea_decode_error(r), orchidea_get_error_details(x->orc_hand));
        } else {
            t_atom val;
            std::stringstream ss;
            ss << (std::string) orchidea_dump_source(x->orc_hand);
            while (!ss.eof ()) {
                std::string line;
                std::getline(ss, line);
                atom_setsym(&val, gensym(line.c_str ()));
                outlet_anything(x->out_1, gensym ("source"), 1, &val);
            }
            
            object_post((t_object *)x, "source has been set correctly");
        }
    } else if (s == gensym ("orchestrate")) {
        object_post((t_object*) x, "start orchestration");
        int n = 0;
        int r = orchidea_orchestrate(x->orc_hand, &n);
        if (r != ORCHIDEA_NO_ERROR) {
            object_post((t_object *)x, "error: %s (%s)", orchidea_decode_error(r), orchidea_get_error_details(x->orc_hand));
        } else {
            system ("rm -rf solutions"); // FIXME: any better idea??
            r = orchidea_export_solutions(x->orc_hand, "solutions", &notifier);
            object_post((t_object *)x, "%d solution(s) found", n);
            if (r != ORCHIDEA_NO_ERROR) {
                object_post((t_object *)x, "error: %s (%s)", orchidea_decode_error(r), orchidea_get_error_details(x->orc_hand));
            } else {
                t_atom vals;
                atom_setlong (&vals, n);
                outlet_anything(x->out_1, gensym("nb_solutions"),  1, &vals);
                
                std::string sols = orchidea_get_last_solutions(x->orc_hand);
                std::deque<std::string> sol_vector;
                tokenize(sols, sol_vector, ">");
                for (unsigned i = 0; i < sol_vector.size (); ++i) {
                    atom_setsym (&vals, gensym(sol_vector[i].c_str ()));
                    object_post((t_object*) x, "%s", sol_vector[i].c_str ());
                    outlet_anything(x->out_1, gensym("solution"),  1, &vals);
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

    c = class_new("orchidea.session", (method)orchmax_session_new, (method)orchmax_session_free, (long)sizeof(t_session),
                  0L /* leave NULL!! */, A_GIMME, 0);

    class_addmethod(c, (method)orchmax_session_anything,		"target",	A_GIMME, 0);
    class_addmethod(c, (method)orchmax_session_anything,        "source",    A_GIMME, 0);
    class_addmethod(c, (method)orchmax_session_anything,        "sounds",    A_GIMME, 0);
    class_addmethod(c, (method)orchmax_session_anything,        "search",    A_GIMME, 0);
    class_addmethod(c, (method)orchmax_session_anything,        "harmonicfilter", A_GIMME, 0);
    class_addmethod(c, (method)orchmax_session_anything,        "criteria",    A_GIMME, 0);
    class_addmethod(c, (method)orchmax_session_anything,        "orchestra",    A_GIMME, 0);
    class_addmethod(c, (method)orchmax_session_anything,        "styles",    A_GIMME, 0);
    class_addmethod(c, (method)orchmax_session_anything,        "dynamics",    A_GIMME, 0);
    class_addmethod(c, (method)orchmax_session_anything,        "MIDIcents",    A_GIMME, 0);
    class_addmethod(c, (method)orchmax_session_anything,        "reset",    A_GIMME, 0);
    class_addmethod(c, (method)orchmax_session_anything,        "orchestrate",    A_GIMME, 0);
    
    CLASS_ATTR_SYM(c, "name", 0, t_session, name);

    class_register(CLASS_BOX, c);
    orchmax_session_class = c;
}

void orchmax_session_free(t_session *x) {
    orchidea_destroy(x->orc_hand);
} 

void orchmax_session_anything(t_session *x, t_symbol *s, long ac, t_atom *av) {
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
    
    if (s == gensym("search")) {
        argument = atom_getsym(av);
        object_post((t_object *)x, "setting search to %s", argument->s_name);
        int r = orchidea_set_search(x->orc_hand, argument->s_name, &notifier);
        if (r != ORCHIDEA_NO_ERROR) {
            object_post((t_object *)x, "error: %s (%s)", orchidea_decode_error(r), orchidea_get_error_details(x->orc_hand));
        } else object_post((t_object *)x, "search has been set correctly");
    } else if (s == gensym("harmonicfilter")) {
        argument = atom_getsym(av);
        object_post((t_object *)x, "setting harmonic filtering to %s", argument->s_name);
        orchidea_set_harmonic_filtering(x->orc_hand, atoi (argument->s_name));
    } else if (s == gensym("criteria")) {
        char** sl  = (char**) malloc (ac * sizeof (char*));
        
        for (int i = 0; i < ac; ++i) {
            sl[i] = atom_getsym(av + i)->s_name;
            object_post((t_object*) x, "setting criterium %s", sl[i]);
        }
        
        orchidea_set_criteria(x->orc_hand, (const char**) sl, (int) ac);
        object_post((t_object *)x, "critera have been set correctly");
        free (sl);
    } else if (s == gensym("sounds")) {
        argument = atom_getsym(av);
        char** sl  = (char**) malloc (ac * sizeof (char*));
        
        for (int i = 0; i < ac; ++i) {
            sl[i] = atom_getsym(av + i)->s_name;
            object_post((t_object*) x, "setting sound folder %s", sl[i]);
        }
        
        orchidea_set_sounds(x->orc_hand, (const char**) sl, (int) ac);
        object_post((t_object *)x, "sounds have been set correctly");
        free (sl);
    }  else if (s == gensym("orchestra")) {
        argument = atom_getsym(av);
        char** sl  = (char**) malloc (ac * sizeof (char*));
        
        for (int i = 0; i < ac; ++i) {
            sl[i] = atom_getsym(av + i)->s_name;
            object_post((t_object*) x, "setting instrument %s", sl[i]);
        }
        
        orchidea_set_orchestra(x->orc_hand, (const char**) sl, (int) ac);
        object_post((t_object *)x, "orchestra has been set correctly");
        free (sl);
    } else if (s == gensym("styles")) {
        argument = atom_getsym(av);
        char** sl  = (char**) malloc (ac * sizeof (char*));
        
        for (int i = 0; i < ac; ++i) {
            sl[i] = atom_getsym(av + i)->s_name;
            object_post((t_object*) x, "setting filter %s", sl[i]);
        }
        
        orchidea_set_styles(x->orc_hand, (const char**) sl, (int) ac);
        object_post((t_object *)x, "styles have been set correctly");
        free (sl);
    } else if (s == gensym("dynamics")) {
        argument = atom_getsym(av);
        char** sl  = (char**) malloc (ac * sizeof (char*));
        
        for (int i = 0; i < ac; ++i) {
            sl[i] = atom_getsym(av + i)->s_name;
            object_post((t_object*) x, "setting dynamic %s", sl[i]);
        }
        
        orchidea_set_dynamics(x->orc_hand, (const char**) sl, (int) ac);
        object_post((t_object *)x, "dynamics have been set correctly");
        free (sl);
    } else if (s == gensym("MIDIcents")) {
        argument = atom_getsym(av);
        char** sl  = (char**) malloc (ac * sizeof (char*));
        
        for (int i = 0; i < ac; ++i) {
            sl[i] = atom_getsym(av + i)->s_name;
           object_post((t_object*) x, "setting MIDIcents ranage %s", sl[i]);
        }
        
        orchidea_set_MIDIcents(x->orc_hand, (const char*) sl[0], (const char*) sl[1]);
        object_post((t_object *)x, "MIDIcents have been set correctly");
        free (sl);
    } else if (s == gensym("reset")) {
        object_post((t_object*) x, "resetting all filters");
        
        orchidea_reset_filters(x->orc_hand);
    } else {
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

void *orchmax_session_new(t_symbol *s, long argc, t_atom *argv) {
    t_session *x = NULL;

    if ((x = (t_session *)object_alloc((t_class*)orchmax_session_class))) {
        x->name = gensym("");
        if (argc && argv) {
            x->name = atom_getsym(argv);
        }
        if (!x->name || x->name == gensym(""))
            x->name = symbol_unique();

        x->running_threads = 0;
        x->orc_hand = orchidea_create();
        
        x->out_1 = outlet_new(x, NULL);
    }
    g_x = x;
    return (x);
}
