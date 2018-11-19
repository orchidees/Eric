/**
 @file
 orchidea.db.query.cpp
 
 @name
 orchidea.db.query.cpp
 
 @realname
 orchidea.db.query.cpp
 
 @type
 object
 
 @module
 orchidea
 
 @author
 Carmine Emanuele 
 
 @digest
 Browse an orchidea database
 
 @description
 Obtain specific samples from an orchidea database
 
 @discussion
 
 @category
 
 @keywords
 orchestration, instrumentation, database, orchidea, browse, filter, find
 
 @seealso
 orchidea.db.gen
 
 @owner
 Carmine Emanuele Cella
 */

#include "orchidea.h"
#include "tokenizer.h"
#include "utilities.h"
#include "orchidea.maxcommons.h"

#include "Parameters.h"
#include "Source.h"

#include <deque>
#include <string>
#include <sstream>
#include <vector>

#include <libgen.h>
#include <pthread.h>

#define ORCHIDEA_DBQUERY_MAX_THREADS 1

////////////////////////// object struct
typedef struct _dbquery {
    t_object    ob;
    
    // Dynamic attributes
    char        parallel;
    char        verbose;
    
    void        *out_1;
    void        *out_2;
    
    void*       n_proxy[2];
    long        n_in;
    
    pthread_t thread_pool[ORCHIDEA_DBQUERY_MAX_THREADS];
    int running_threads;

    Parameters<float> params;
    Source<float> * source;
} t_dbquery;

///////////////////////// function prototypes
//// standard set
void *orchmax_dbquery_new(t_symbol *s, long argc, t_atom *argv);
void orchmax_dbquery_free(t_dbquery *x);
void orchmax_dbquery_assist(t_dbquery *x, void *b, long m, long a, char *s);

void orchmax_dbquery_anything(t_dbquery *x, t_symbol *s, long ac, t_atom *av);
void orchmax_dbquery_bang(t_dbquery *x);


//////////////////////// global class pointer variable
void *orchmax_dbquery_class;


t_symbol *get_patch_path(t_dbquery *x) {
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
    
    return orchidea_conform_path(path);
}

// TO DO: IMPROVE THIS :)
t_symbol *strip_extension(t_symbol *s, char keep_dot) {
    if (!s) {
        return NULL;
    }
    
    char out[MAX_PATH_CHARS];
    snprintf_zero(out, MAX_PATH_CHARS, "%s", s->s_name);
    long l = strlen(out);
    
    // TO DO: support WINDOWS
    for (long i = l-2; i>=0; i--) {
        if (out[i] == '.') {
            if (keep_dot) out[i+1] = 0; else out[i] = 0;
            break;
        }
    }
    
    return gensym(out);
}

// will take care of freeing data->av after usage, if not NULL
void* orchidea_solve_dispatcher (void* d) {
    thread_data* data = (thread_data*) d;
    t_dbquery* x = (t_dbquery*) data->x;
    t_symbol* s = data->s;
    t_atom* av = data->av;
    long ac = data->ac;
    
    t_atom busy;
    atom_setlong(&busy, 1);
    outlet_anything(x->out_2, gensym("busy"), 1, &busy);
    
    if (x->parallel) {
        x->running_threads++;
        if (x->verbose) object_post((t_object*) x, "current thread n. %d", x->running_threads);
    }
    
    t_symbol* argument = 0;
    
    t_symbol *path = get_patch_path(x);
    if (x->verbose) object_post((t_object*) x, "path: %s", path->s_name);
    
    if (s == gensym("dbfiles")) {
        argument = atom_getsym(av);
        for (int i = 0; i < ac; ++i) {
            t_symbol *this_dbfile = orchidea_ezlocate_file(atom_getsym(av + i));
            if (this_dbfile) {
                x->params.db_files.push_back (this_dbfile->s_name);
                if (x->verbose) object_post((t_object*) x, "adding db file %s", this_dbfile->s_name);
            } else {
                object_error((t_object *)x, "can't add db file %s", this_dbfile->s_name);
            }
        }
        
        try {
            x->source->load ();
            t_atom cnt;
            atom_setlong(&cnt, x->source->database.size ());
            outlet_anything(x->out_2, gensym("size"), 1, &cnt);

            if (x->verbose) object_post((t_object *)x, "db files have been set correctly");
        } catch (std::exception& e) {
            object_error((t_object *)x, "error: %s", e.what ());
        }
    }

    atom_setlong(&busy, 0);
    
    // TODO: are we sure that we should output stuff from this custom thread?
    outlet_anything(x->out_2, gensym("busy"), 1, &busy);
    
    if (x->parallel) {
        x->running_threads--;
    }

    // FIXME: is memory deletion needed?
    if (data->av)
        sysmem_freeptr(data->av);
    sysmem_freeptr(data);
    
    return NULL;
}

void ext_main(void *r) {
    t_class *c;
    
    c = class_new("orchidea.db.query", (method)orchmax_dbquery_new, (method)orchmax_dbquery_free, (long)sizeof(t_dbquery),
                  0L /* leave NULL!! */, A_GIMME, 0);
    
    class_addmethod(c, (method)orchmax_dbquery_anything,        "items",    A_GIMME, 0);
    class_addmethod(c, (method)orchmax_dbquery_anything,        "grep",    A_GIMME, 0);
    class_addmethod(c, (method)orchmax_dbquery_anything,        "anything",    A_GIMME, 0);
    
    CLASS_ATTR_CHAR(c, "verbose", 0, t_dbquery, verbose);
    CLASS_ATTR_STYLE(c, "verbose", 0, "onoff");
    CLASS_ATTR_LABEL(c, "verbose", 0, "Verbose");
    // @description Toggles the verbose mode
    
    CLASS_ATTR_CHAR(c, "parallel", 0, t_dbquery, parallel);
    CLASS_ATTR_STYLE(c, "parallel", 0, "onoff");
    CLASS_ATTR_LABEL(c, "parallel", 0, "Parallel");
    // @description When this attribute is 1, the computations are performed in a separate thread.
    
    class_register(CLASS_BOX, c);
    orchmax_dbquery_class = c;
}

void orchmax_dbquery_assist(t_dbquery *x, void *b, long m, long a, char *s) {
    if (m == ASSIST_INLET) {
        if (a == 1) {
            sprintf(s, "symbol/list: Database File(s)"); // @in 2 @type symbol/list @digest File or files containing the database (usually ending with .db)
        }
    } else {
        if (a == 0)
            sprintf(s, "list: Output Of Query");
        // @out 0 @type symbol/list @digest Output Of Query
        else
            sprintf(s, "list: Notifications"); // @out 1 @type list @digest Notifications
    }
}

void orchmax_dbquery_free(t_dbquery *x) {
    long i;
    for (i = 1; i < 2; i++)
        object_free(x->n_proxy[i]);

}

// suppose soundpath is allocated with
void dbpath_to_soundpath(char *dbpath, char *soundpath) {
    std::string src(dbpath);
    std::string out = removeExtension(removeExtension(src)); // intentional double call: the name should be XXXXXXX.featurename.db -> let's remove the last two parts
    snprintf(soundpath, MAX_PATH_CHARS, "%s", out.c_str());
}

void orchmax_dbquery_anything_do(t_dbquery *x, t_symbol *s, long ac, t_atom *av) {
    if (s == gensym("items") || s == gensym("grep")) {
        
        std::stringstream query;
        query << s->s_name << " ";
        for (int i = 0; i < ac; ++i) {
            query << atom_getsym (av + i)->s_name << " ";
        }
        post ("%s", query.str ().c_str ());
        std::vector<std::string> res;
        try {
            x->source->query (query.str ().c_str (), res);
            
            for (unsigned i = 0; i < res.size (); ++i) {
                outlet_anything(x->out_1, gensym (res[i].c_str ()), 0, NULL);
            }
        } catch (std::exception& e) {
            object_error((t_object *)x, "error: %s", e.what ());
        }
    } else {
        long inlet = proxy_getinlet((t_object *) x);
        
        thread_data *d = (thread_data *)sysmem_newptr(sizeof(thread_data)); // delete after thread call - I think it works since thare are no modif during thread
        d->x =(t_object *)x;
        
        if (inlet == 1) {
            // heavy actions are executed in a separated thread (or pool)
            if (x->running_threads >= ORCHIDEA_DBQUERY_MAX_THREADS) {
                object_warn((t_object*) x, "pending actions; please retry later...");
                return;
            }
            
            // set database
            long j = 0;
            d->s = gensym("dbfiles");
            d->ac = (s && s != gensym("list") ? ac + 1 : ac);
            d->av = (t_atom *)sysmem_newptr(d->ac * sizeof(t_atom));
            if (s && s != gensym("list")) {
                atom_setsym(d->av, s);
                j++;
            }
            for (long i = 0; i < ac; i++) {
                d->av[j++] = av[i];
            }
            
        }
        if (x->parallel) {
            pthread_create(&x->thread_pool[x->running_threads], NULL, orchidea_solve_dispatcher, (void*) d);
        } else {
            orchidea_solve_dispatcher(d);
        }
    }
}

void orchmax_dbquery_anything(t_dbquery *x, t_symbol *s, long ac, t_atom *av) {
    defer(x, (method)orchmax_dbquery_anything_do, s, ac, av);
}

void *orchmax_dbquery_new(t_symbol *s, long argc, t_atom *argv) {
    t_dbquery *x = NULL;
    
    if ((x = (t_dbquery *)object_alloc((t_class*)orchmax_dbquery_class))) {
        
        x->verbose = true; // just for now?
        
        x->n_proxy[1] = proxy_new((t_object *) x, 1, &x->n_in);

        x->running_threads = 0;
        x->parallel = 1; // DG: I'm not so sure this should be the default. I see the point, of course, but custom threading in Max is prone to crashes...
        
        
        attr_args_process(x, argc, argv);
        
        x->out_2 = outlet_new(x, NULL);
        x->out_1 = outlet_new(x, NULL);
        
        x->source = new Source<float> (&x->params);
        
    }
    
    return (x);
}

