/**
 @file
 orchidea.db.browse.cpp
 
 @name
 orchidea.db.browse
 
 @realname
 orchidea.db.browse
 
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

#include "ext.h"							// standard Max include, always required
#include "ext_obex.h"						// required for new style Max object

#include <deque>
#include <string>
#include <sstream>

#include <libgen.h>
#include <pthread.h>

#define ORCHIDEA_SOLVE_MAX_THREADS 1
#define ORCHIDEA_SOLVE_MAX_SOUND_PATHS 256
#define ORCHIDEA_SOLVE_MAX_ORCHESTRA 4096
#define ORCHIDEA_SOLVE_MAX_STYLES 4096
#define ORCHIDEA_SOLVE_MAX_DYNAMICS 256
#define ORCHIDEA_SOLVE_MAX_OTHERS 2048
#define ORCHIDEA_SOLVE_MAX_EXTRAPITCHES 1024

////////////////////////// object struct
typedef struct _solver {
    t_object	ob;

    // Static attributes
    t_symbol*   segmentation;
    t_symbol*   connection;
    
    // Dynamic attributes
    t_symbol*   soundpaths[ORCHIDEA_SOLVE_MAX_SOUND_PATHS];
    long        soundpaths_size;
    t_symbol*   prefix;
    t_symbol*   search;
    long        popsize;
    long        maxepochs;
    long        pursuit;
    double      xoverrate;
    double      mutationrate;
    double      sparsity;
    double      negativepenalization;
    double      positivepenalization;
    double      onsetthreshold;
    double      onsettimegate;
    long        partialswindow;
    double      partialsfilter;
    t_symbol    *orchestra[ORCHIDEA_SOLVE_MAX_ORCHESTRA];
    long        orchestra_size;
    t_symbol    *styles[ORCHIDEA_SOLVE_MAX_STYLES];
    long        styles_size;
    t_symbol    *dynamics[ORCHIDEA_SOLVE_MAX_DYNAMICS];
    long        dynamics_size;
    t_symbol    *others[ORCHIDEA_SOLVE_MAX_OTHERS];
    long        others_size;
    t_symbol    *extrapitches[ORCHIDEA_SOLVE_MAX_EXTRAPITCHES];
    long        extrapitches_size;

    char        parallel;
    char        verbose;

    void		*out_1;
    void        *out_2;

    char        must_rerun_analysis;
    t_symbol*   current_target;

    OrchideaHandle* orc_hand;
    pthread_t thread_pool[ORCHIDEA_SOLVE_MAX_THREADS];
    int running_threads;
    
    void*       n_proxy[3];
    long        n_in;

    Callback*   callback;
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

//// SETTERS

void orchidea_set_param_long(OrchideaHandle *orc_hand, t_symbol *param, long val) {
    char** sl  = (char**)sysmem_newptr(2 * sizeof (char*));
    sl[0] = sysmem_newptr(256 * sizeof(char));
    sl[1] = sysmem_newptr(2048 * sizeof(char));
    snprintf_zero(sl[0], 256, "%s", param->s_name);
    snprintf_zero(sl[1], 2048, "%ld", val);
    orchidea_set_param(orc_hand, (const char**) sl, (int) 2);
    sysmem_freeptr(sl[0]);
    sysmem_freeptr(sl[1]);
    sysmem_freeptr(sl);
}

void orchidea_set_param_double(OrchideaHandle *orc_hand, t_symbol *param, double val) {
    char** sl  = (char**)sysmem_newptr(2 * sizeof (char*));
    sl[0] = sysmem_newptr(256 * sizeof(char));
    sl[1] = sysmem_newptr(2048 * sizeof(char));
    snprintf_zero(sl[0], 256, "%s", param->s_name);
    snprintf_zero(sl[1], 2048, "%.4f", val);
    orchidea_set_param(orc_hand, (const char**) sl, (int) 2);
    sysmem_freeptr(sl[0]);
    sysmem_freeptr(sl[1]);
    sysmem_freeptr(sl);
}

void orchidea_set_param_symarray(OrchideaHandle *orc_hand, t_symbol *param, long size, t_symbol **array) {
    char** sl  = (char**)sysmem_newptr((size + 1) * sizeof (char*));
    sl[0] = sysmem_newptr(256 * sizeof(char));
    snprintf_zero(sl[0], 256, "%s", param->s_name);
    for (long i = 1; i < size + 1; i++) {
        sl[i] = sysmem_newptr(2048 * sizeof(char));
        snprintf_zero(sl[i], 2048, "%s", array[i-1]->s_name);
    }
    orchidea_set_param(orc_hand, (const char**) sl, (int) size + 1);
    for (long i = 0; i < size + 1; i++)
        sysmem_freeptr(sl[i]);
    sysmem_freeptr(sl);
}


t_max_err orchmax_solve_setattr_search(t_solver *x, void *attr, long ac, t_atom *av) {
    if (ac && av) {
        t_symbol *s = atom_getsym(av);
        x->search = s;
        if (x->verbose) object_post((t_object *)x, "setting search to %s", s->s_name);
        int r = orchidea_set_search(x->orc_hand, s->s_name);
        if (r != ORCHIDEA_NO_ERROR) {
            object_error((t_object *)x, "error: %s (%s)", orchidea_decode_error(r),
                        orchidea_get_error_details(x->orc_hand));
        } else {
            if (x->verbose) object_post((t_object *)x, "search has been set correctly");
        }
    }
    return MAX_ERR_NONE;
}


t_max_err orchmax_solve_setattr_popsize(t_solver *x, void *attr, long ac, t_atom *av){
    if (ac && av) {
        orchidea_set_param_long(x->orc_hand, gensym("pop_size"), x->popsize = atom_getlong(av));
        if (x->verbose) object_post((t_object *)x, "population size has been set correctly");
    }
    return MAX_ERR_NONE;
}

t_max_err orchmax_solve_setattr_maxepochs(t_solver *x, void *attr, long ac, t_atom *av) {
    if (ac && av) {
        orchidea_set_param_long(x->orc_hand, gensym("max_epochs"), x->maxepochs = atom_getlong(av));
        if (x->verbose) object_post((t_object *)x, "max number of epochs has been set correctly");
    }
    return MAX_ERR_NONE;
}


t_max_err orchmax_solve_setattr_pursuit(t_solver *x, void *attr, long ac, t_atom *av) {
    if (ac && av) {
        orchidea_set_param_long(x->orc_hand, gensym("pursuit"), x->pursuit = atom_getlong(av));
        if (x->verbose) object_post((t_object *)x, "relaxed pursuit has been set correctly");
    }
    return MAX_ERR_NONE;
}


t_max_err orchmax_solve_setattr_xoverrate(t_solver *x, void *attr, long ac, t_atom *av) {
    if (ac && av) {
        orchidea_set_param_double(x->orc_hand, gensym("xover_rate"), x->xoverrate = atom_getfloat(av));
        if (x->verbose) object_post((t_object *)x, "cross-over rate has been set correctly");
    }
    return MAX_ERR_NONE;
}

t_max_err orchmax_solve_setattr_mutationrate(t_solver *x, void *attr, long ac, t_atom *av) {
    if (ac && av) {
        orchidea_set_param_double(x->orc_hand, gensym("mutation_rate"), x->mutationrate = atom_getfloat(av));
        if (x->verbose) object_post((t_object *)x, "mutation rate has been set correctly");
    }
    return MAX_ERR_NONE;
}

t_max_err orchmax_solve_setattr_sparsity(t_solver *x, void *attr, long ac, t_atom *av) {
    if (ac && av) {
        orchidea_set_param_double(x->orc_hand, gensym("sparsity"), x->sparsity = atom_getfloat(av));
        if (x->verbose) object_post((t_object *)x, "sparsity has been set correctly");
    }
    return MAX_ERR_NONE;
}

t_max_err orchmax_solve_setattr_negativepenalization(t_solver *x, void *attr, long ac, t_atom *av) {
    if (ac && av) {
        orchidea_set_param_double(x->orc_hand, gensym("negative_penalization"), x->negativepenalization = atom_getfloat(av));
        if (x->verbose) object_post((t_object *)x, "negative penalization has been set correctly");
    }
    return MAX_ERR_NONE;
}

t_max_err orchmax_solve_setattr_positivepenalization(t_solver *x, void *attr, long ac, t_atom *av) {
    if (ac && av) {
        orchidea_set_param_double(x->orc_hand, gensym("positive_penalization"), x->positivepenalization = atom_getfloat(av));
        if (x->verbose) object_post((t_object *)x, "positive penalization has been set correctly");
    }
    return MAX_ERR_NONE;
}

t_max_err orchmax_solve_setattr_onsetthreshold(t_solver *x, void *attr, long ac, t_atom *av) {
    if (ac && av) {
        orchidea_set_param_double(x->orc_hand, gensym("onsets_threshold"), x->onsetthreshold = atom_getfloat(av));
        x->must_rerun_analysis = true;
        if (x->verbose) object_post((t_object *)x, "onset threshold has been set correctly");
    }
    return MAX_ERR_NONE;
}

t_max_err orchmax_solve_setattr_onsettimegate(t_solver *x, void *attr, long ac, t_atom *av) {
    if (ac && av) {
        orchidea_set_param_double(x->orc_hand, gensym("onsets_timegate"), (x->onsettimegate = atom_getfloat(av))/1000.);
        x->must_rerun_analysis = true;
        if (x->verbose) object_post((t_object *)x, "onset timegate has been set correctly");
    }
    return MAX_ERR_NONE;
}

t_max_err orchmax_solve_setattr_partialswindow(t_solver *x, void *attr, long ac, t_atom *av) {
    if (ac && av) {
        orchidea_set_param_long(x->orc_hand, gensym("partials_window"), x->partialswindow = atom_getlong(av));
        x->must_rerun_analysis = true;
        if (x->verbose) object_post((t_object *)x, "partials window has been set correctly");
    }
    return MAX_ERR_NONE;
}

t_max_err orchmax_solve_setattr_partialsfilter(t_solver *x, void *attr, long ac, t_atom *av) {
    if (ac && av) {
        orchidea_set_param_double(x->orc_hand, gensym("partials_filter"), x->partialsfilter = atom_getfloat(av));
        x->must_rerun_analysis = true;
        if (x->verbose) object_post((t_object *)x, "partials filter has been set correctly");
    }
    return MAX_ERR_NONE;
}

t_max_err orchmax_solve_setattr_orchestra(t_solver *x, void *attr, long ac, t_atom *av) {
    if (ac && av) {
        for (long i = 0; i < ac && i < ORCHIDEA_SOLVE_MAX_ORCHESTRA; i++) {
            x->orchestra[i] = atom_getsym(av+i);
        }
        x->orchestra_size = ac;
        orchidea_set_param_symarray(x->orc_hand, gensym("orchestra"), x->orchestra_size, x->orchestra);
        if (x->verbose) object_post((t_object *)x, "orchestra has been set correctly");
    }
    return MAX_ERR_NONE;
}

t_max_err orchmax_solve_setattr_styles(t_solver *x, void *attr, long ac, t_atom *av) {
    if (ac && av) {
        for (long i = 0; i < ac && i < ORCHIDEA_SOLVE_MAX_STYLES; i++) {
            x->styles[i] = atom_getsym(av+i);
        }
        x->styles_size = ac;
        orchidea_set_param_symarray(x->orc_hand, gensym("styles"), x->styles_size, x->styles);
        if (x->verbose) object_post((t_object *)x, "styles have been set correctly");
    }
    return MAX_ERR_NONE;
}

t_max_err orchmax_solve_setattr_dynamics(t_solver *x, void *attr, long ac, t_atom *av) {
    if (ac && av) {
        for (long i = 0; i < ac && i < ORCHIDEA_SOLVE_MAX_DYNAMICS; i++) {
            x->dynamics[i] = atom_getsym(av+i);
        }
        x->dynamics_size = ac;
        orchidea_set_param_symarray(x->orc_hand, gensym("dynamics"), x->dynamics_size, x->dynamics);
        if (x->verbose) object_post((t_object *)x, "dynamics have been set correctly");
    }
    return MAX_ERR_NONE;
}

t_max_err orchmax_solve_setattr_others(t_solver *x, void *attr, long ac, t_atom *av) {
    if (ac && av) {
        for (long i = 0; i < ac && i < ORCHIDEA_SOLVE_MAX_OTHERS; i++) {
            x->others[i] = atom_getsym(av+i);
        }
        x->others_size = ac;
        orchidea_set_param_symarray(x->orc_hand, gensym("others"), x->others_size, x->others);
        if (x->verbose) object_post((t_object *)x, "other filters have been set correctly");
    }
    return MAX_ERR_NONE;
}

t_max_err orchmax_solve_setattr_extrapitches(t_solver *x, void *attr, long ac, t_atom *av) {
    if (ac && av) {
        for (long i = 0; i < ac && i < ORCHIDEA_SOLVE_MAX_EXTRAPITCHES; i++) {
            x->extrapitches[i] = atom_getsym(av+i);
        }
        x->extrapitches_size = ac;
        orchidea_set_param_symarray(x->orc_hand, gensym("extra_pitches"), x->extrapitches_size, x->extrapitches);
        if (x->verbose) object_post((t_object *)x, "extra pitches have been set correctly");
    }
    return MAX_ERR_NONE;
}

t_max_err orchmax_solve_setattr_soundpaths(t_solver *x, void *attr, long ac, t_atom *av) {
    if (ac && av) {
        for (long i = 0; i < ac && i < ORCHIDEA_SOLVE_MAX_SOUND_PATHS; i++) {
            x->soundpaths[i] = atom_getsym(av+i);
        }
        x->soundpaths_size = ac;
        orchidea_set_param_symarray(x->orc_hand, gensym("sound_paths"), x->soundpaths_size, x->soundpaths);
        if (x->verbose) object_post((t_object *)x, "sound paths have been set correctly");
    }
    return MAX_ERR_NONE;
}


t_symbol *conform_path(t_symbol *path) {
    if (!path) {
        return NULL;
    }
    
    char outpath[MAX_PATH_CHARS];
    path_nameconform(path->s_name, outpath, PATH_STYLE_MAX, PATH_TYPE_BOOT);
    return gensym(outpath);
}

t_symbol *get_patch_path(t_solver *x) {
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
    
    return conform_path(path);
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
    t_solver* x = data->x;
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
        char** sl  = (char**) malloc ((ac) * sizeof (char*));
        for (int i = 0; i < ac; ++i) {
            t_symbol *this_dbfile = conform_path(atom_getsym(av + i));
            if (this_dbfile) {
                sl[i] = this_dbfile->s_name;
                if (x->verbose) object_post((t_object*) x, "adding db file %s", sl[i]);
            } else {
                object_error((t_object *)x, "can't add db file %s", sl[i]);
            }
        }
        
        int r = orchidea_set_source(x->orc_hand, (const char**) sl, (int) ac);
        
        if (r != ORCHIDEA_NO_ERROR) {
            object_error((t_object *)x, "error: %s (%s)", orchidea_decode_error(r),
                        orchidea_get_error_details(x->orc_hand));
        }
        
        else {
            t_atom val;
            std::stringstream ss;
            ss << (std::string) orchidea_dump_source(x->orc_hand);
//            post ("%s", ss.str ().c_str ());
//            while (!ss.eof ()) {
//                std::string line;
//                std::getline(ss, line);
                atom_setsym(&val, gensym(ss.str ().c_str ()));
                outlet_anything(x->out_2, gensym ("source"), 1, &val);
//            }

            if (x->verbose) object_post((t_object *)x, "db files have been set correctly");
        }
        free (sl);
    }
    else if (s == gensym ("orchestrate") || s == gensym("target")) {
        if (s == gensym("target")) {
            argument = conform_path(atom_getsym(av));
            if (x->current_target != argument) { // filename has changed
                // first analysis of target
                x->current_target = argument;
                if (x->verbose) object_post((t_object *)x, "setting target to %s...", argument->s_name);
                int r = orchidea_set_target(x->orc_hand, argument->s_name);
                if (r != ORCHIDEA_NO_ERROR) {
                    object_error((t_object *)x, "error: %s (%s)", orchidea_decode_error(r), orchidea_get_error_details(x->orc_hand));
                } else {
                    if (x->verbose) object_post((t_object *)x, "target has been set correctly");
                }
                x->must_rerun_analysis = false;
            }
        }
        
        if (x->must_rerun_analysis) {
            // reanalysis of target
            int r = orchidea_set_target(x->orc_hand, x->current_target ? "" : x->current_target->s_name);
            if (r != ORCHIDEA_NO_ERROR) {
                object_error((t_object *)x, "error: %s (%s)", orchidea_decode_error(r), orchidea_get_error_details(x->orc_hand));
            } else {
                if (x->verbose) object_post((t_object *)x, "target has been reanalysed correctly");
            }
            x->must_rerun_analysis = false;
        }
        
        
        if (x->verbose) object_post((t_object*) x, "start orchestration");
        int r = orchidea_orchestrate(x->orc_hand);
        if (r != ORCHIDEA_NO_ERROR) {
            object_error((t_object *)x, "error: %s (%s)", orchidea_decode_error(r), orchidea_get_error_details(x->orc_hand));
        } else {
            // TODO: clearing files automatically???
//            if (x->autoclear) {
//            }
            int n = 0;
            orchidea_num_segments(x->orc_hand, &n);
            for (unsigned i = 0; i < n; ++i) {
                int sols = 0;
                orchidea_solutions_per_segment(x->orc_hand, i, &sols);
            }
            
            char outprefix[MAX_PATH_CHARS];
            if (x->prefix && strlen(x->prefix->s_name) > 0) {
                snprintf_zero(outprefix, MAX_PATH_CHARS, "%s", x->prefix->s_name);
            } else {
                // default case
                short path = 0, newpath = 0;
                char filename[MAX_PATH_CHARS];
                t_symbol *default_path = strip_extension(x->current_target, false);
                std::string foldername = removePath(default_path->s_name) + "_orchidea";
                path_frompathname(x->current_target->s_name, &path, filename);
                path_createfolder(path, foldername.c_str(), &newpath);
                snprintf_zero(outprefix, MAX_PATH_CHARS, "%s_orchidea/%s.", default_path->s_name, foldername.c_str());
            }
            r = orchidea_export_solutions(x->orc_hand, outprefix);
            if (x->verbose) object_post((t_object *)x, "%d segments(s) found", n);
            
            if (r != ORCHIDEA_NO_ERROR) {
                if (r == ORCHIDEA_NO_SOUNDS)
                    object_warn((t_object *)x, "error: %s (%s)", orchidea_decode_error(r), orchidea_get_error_details(x->orc_hand));
                else
                    object_error((t_object *)x, "error: %s (%s)", orchidea_decode_error(r), orchidea_get_error_details(x->orc_hand));
            }
            
            int num_seg = 0;
            orchidea_num_segments(x->orc_hand, &num_seg);
            
            long ac = num_seg + 2;
            t_atom *av = (t_atom *)sysmem_newptr(ac * sizeof(t_atom));
            atom_setsym(av, gensym(outprefix));
            atom_setlong(av + 1, num_seg);
            for (int i = 0; i < num_seg; i++) {
                int sols = 0;
                orchidea_solutions_per_segment(x->orc_hand, i, &sols);
                atom_setlong(av + 2 + i, sols);
            }
            outlet_anything(x->out_1, gensym("list"), ac, av);
            sysmem_freeptr(av);
        }
    }
    atom_setlong(&busy, 0);
    
    // TODO: are we sure that we should output stuff from this custom thread?
    outlet_anything(x->out_2, gensym("busy"), 1, &busy);
    
    if (x->parallel) {
        x->running_threads--;
    }
    
    if (data->av)
        sysmem_freeptr(data->av);
    sysmem_freeptr(data);
    
    return NULL;
}

void ext_main(void *r) {
    t_class *c;

    c = class_new("orchidea.solve", (method)orchmax_solve_new, (method)orchmax_solve_free, (long)sizeof(t_solver),
                  0L /* leave NULL!! */, A_GIMME, 0);

    // @method bang @digest Orchestrate
    // @description A bang triggers the orchestration.
    class_addmethod(c, (method)orchmax_solve_bang,            "bang",            0);
    class_addmethod(c, (method)orchmax_solve_anything,        "anything",    A_GIMME, 0);

    class_addmethod(c, (method)orchmax_solve_anything,        "resetfilters",    A_GIMME, 0);
    
    
//    class_addmethod(c, (method)orchmax_solve_notify, "notify", A_CANT, 0);
    CLASS_ATTR_SYM(c, "segmentation", 0, t_solver, segmentation);
    CLASS_ATTR_STYLE(c, "segmentation", 0, "enum");
    CLASS_ATTR_ENUM(c,"segmentation", 0, "flux frames");
    CLASS_ATTR_LABEL(c, "segmentation", 0, "Segmentation Type");
    CLASS_ATTR_BASIC(c, "segmentation", 0);
    CLASS_ATTR_CATEGORY(c, "segmentation", 0, "Dynamic Orchestration");
    // @description Sets the segmentation type: either "flux" or "frames". <br />
    // This is a static attribute which can only be set by typing it in the object box.

    CLASS_ATTR_SYM(c, "connection", 0, t_solver, connection);
    CLASS_ATTR_STYLE(c, "connection", 0, "enum");
    CLASS_ATTR_ENUM(c,"connection", 0, "closest best");
    CLASS_ATTR_LABEL(c, "connection", 0, "Connection Type");
    CLASS_ATTR_BASIC(c, "connection", 0);
    CLASS_ATTR_CATEGORY(c, "connection", 0, "Dynamic Orchestration");
    // @description Sets the connection type: either "closest" or "best". <br />
    // This is a static attribute which can only be set by typing it in the object box.

    
    CLASS_ATTR_SYM(c, "search", 0, t_solver, search);
    CLASS_ATTR_STYLE(c, "search", 0, "enum");
    CLASS_ATTR_ENUM(c,"search", 0, "genetic");
    CLASS_ATTR_LABEL(c, "search", 0, "Search Type");
    CLASS_ATTR_ACCESSORS(c, "search", (method)NULL, (method)orchmax_solve_setattr_search);
    CLASS_ATTR_CATEGORY(c, "search", 0, "Search");
    // @description Sets the search type.

    
    
    CLASS_ATTR_SYM_VARSIZE(c, "soundpaths", 0, t_solver, soundpaths, soundpaths_size, ORCHIDEA_SOLVE_MAX_SOUND_PATHS);
    CLASS_ATTR_STYLE(c, "soundpaths", 0, "text");
    CLASS_ATTR_LABEL(c, "soundpaths", 0, "Paths to Sound Files");
    CLASS_ATTR_ACCESSORS(c, "soundpaths", (method)NULL, (method)orchmax_solve_setattr_soundpaths);
    CLASS_ATTR_CATEGORY(c, "soundpaths", 0, "Paths");
    // @description If needed, sets the paths to the root folders containing the audio files, one path for each database file.
    // The default value is the <m>default</m> symbol, maning that the program expects the sound folder to be at the same level
    // of the database file, and with the same name.
    // In this case, there's no need to define any soundpath.

    
    CLASS_ATTR_SYM(c, "prefix", 0, t_solver, prefix);
    CLASS_ATTR_STYLE(c, "prefix", 0, "text");
    CLASS_ATTR_LABEL(c, "prefix", 0, "Output Prefix");
    CLASS_ATTR_CATEGORY(c, "prefix", 0, "Paths");
    // @description Sets the prefix path to be added to the output files.
    // By default output files will be put in the same folder of the target file.

    CLASS_ATTR_LONG(c, "popsize", 0, t_solver, popsize);
    CLASS_ATTR_STYLE(c, "popsize", 0, "text");
    CLASS_ATTR_LABEL(c, "popsize", 0, "Population Size");
    CLASS_ATTR_ACCESSORS(c, "popsize", (method)NULL, (method)orchmax_solve_setattr_popsize);
    CLASS_ATTR_CATEGORY(c, "popsize", 0, "Search");
    // @description Sets the population size.

    CLASS_ATTR_LONG(c, "maxepochs", 0, t_solver, maxepochs);
    CLASS_ATTR_STYLE(c, "maxepochs", 0, "text");
    CLASS_ATTR_LABEL(c, "maxepochs", 0, "Maximum Number of Epochs");
    CLASS_ATTR_ACCESSORS(c, "maxepochs", (method)NULL, (method)orchmax_solve_setattr_maxepochs);
    CLASS_ATTR_CATEGORY(c, "maxepochs", 0, "Search");
    // @description Sets the maximum number of epochs.

    
    CLASS_ATTR_LONG(c, "pursuit", 0, t_solver, pursuit);
    CLASS_ATTR_STYLE(c, "pursuit", 0, "text");
    CLASS_ATTR_LABEL(c, "pursuit", 0, "Pursuit");
    CLASS_ATTR_ACCESSORS(c, "pursuit", (method)NULL, (method)orchmax_solve_setattr_pursuit);
    CLASS_ATTR_CATEGORY(c, "pursuit", 0, "Search");
    // @description Sets the pursuit.

    
    CLASS_ATTR_DOUBLE(c, "xoverrate", 0, t_solver, xoverrate);
    CLASS_ATTR_STYLE(c, "xoverrate", 0, "text");
    CLASS_ATTR_LABEL(c, "xoverrate", 0, "Cross-Over Rate");
    CLASS_ATTR_ACCESSORS(c, "xoverrate", (method)NULL, (method)orchmax_solve_setattr_xoverrate);
    CLASS_ATTR_CATEGORY(c, "xoverrate", 0, "Search");
    // @description Sets the cross-over rate.

    CLASS_ATTR_DOUBLE(c, "mutationrate", 0, t_solver, mutationrate);
    CLASS_ATTR_STYLE(c, "mutationrate", 0, "text");
    CLASS_ATTR_LABEL(c, "mutationrate", 0, "Mutation Rate");
    CLASS_ATTR_ACCESSORS(c, "mutationrate", (method)NULL, (method)orchmax_solve_setattr_mutationrate);
    CLASS_ATTR_CATEGORY(c, "mutationrate", 0, "Search");
    // @description Sets the mutation rate.

    CLASS_ATTR_DOUBLE(c, "sparsity", 0, t_solver, sparsity);
    CLASS_ATTR_STYLE(c, "sparsity", 0, "text");
    CLASS_ATTR_LABEL(c, "sparsity", 0, "Sparsity");
    CLASS_ATTR_ACCESSORS(c, "sparsity", (method)NULL, (method)orchmax_solve_setattr_sparsity);
    CLASS_ATTR_CATEGORY(c, "sparsity", 0, "Search");
    // @description Sets the sparsity.

    CLASS_ATTR_DOUBLE(c, "negativepenalization", 0, t_solver, negativepenalization);
    CLASS_ATTR_STYLE(c, "negativepenalization", 0, "text");
    CLASS_ATTR_LABEL(c, "negativepenalization", 0, "Negative Penalization");
    CLASS_ATTR_ACCESSORS(c, "negativepenalization", (method)NULL, (method)orchmax_solve_setattr_negativepenalization);
    CLASS_ATTR_CATEGORY(c, "negativepenalization", 0, "Search");
    // @description Sets the negative penalization.

    CLASS_ATTR_DOUBLE(c, "positivepenalization", 0, t_solver, positivepenalization);
    CLASS_ATTR_STYLE(c, "positivepenalization", 0, "text");
    CLASS_ATTR_LABEL(c, "positivepenalization", 0, "Positive Penalization");
    CLASS_ATTR_ACCESSORS(c, "positivepenalization", (method)NULL, (method)orchmax_solve_setattr_positivepenalization);
    CLASS_ATTR_CATEGORY(c, "positivepenalization", 0, "Search");
    // @description Sets the positive penalization.

    CLASS_ATTR_DOUBLE(c, "onsetthreshold", 0, t_solver, onsetthreshold);
    CLASS_ATTR_STYLE(c, "onsetthreshold", 0, "text");
    CLASS_ATTR_LABEL(c, "onsetthreshold", 0, "Onset Threshold");
    CLASS_ATTR_ACCESSORS(c, "onsetthreshold", (method)NULL, (method)orchmax_solve_setattr_onsetthreshold);
    CLASS_ATTR_CATEGORY(c, "onsetthreshold", 0, "Dynamic Orchestration");
    // @description Sets the onset threshold

    CLASS_ATTR_DOUBLE(c, "onsettimegate", 0, t_solver, onsettimegate);
    CLASS_ATTR_STYLE(c, "onsettimegate", 0, "text");
    CLASS_ATTR_LABEL(c, "onsettimegate", 0, "Onset Time Gate");
    CLASS_ATTR_ACCESSORS(c, "onsettimegate", (method)NULL, (method)orchmax_solve_setattr_onsettimegate);
    CLASS_ATTR_CATEGORY(c, "onsettimegate", 0, "Dynamic Orchestration");
    // @description Sets the onset time gate in milliseconds.

    CLASS_ATTR_LONG(c, "partialswindow", 0, t_solver, partialswindow);
    CLASS_ATTR_STYLE(c, "partialswindow", 0, "text");
    CLASS_ATTR_LABEL(c, "partialswindow", 0, "Partials Window Size");
    CLASS_ATTR_ACCESSORS(c, "partialswindow", (method)NULL, (method)orchmax_solve_setattr_partialswindow);
    CLASS_ATTR_CATEGORY(c, "partialswindow", 0, "Target");
    // @description Sets the size of the analysis window for partials

    CLASS_ATTR_DOUBLE(c, "partialsfilter", 0, t_solver, partialsfilter);
    CLASS_ATTR_STYLE(c, "partialsfilter", 0, "text");
    CLASS_ATTR_LABEL(c, "partialsfilter", 0, "Partials Filter");
    CLASS_ATTR_ACCESSORS(c, "partialsfilter", (method)NULL, (method)orchmax_solve_setattr_partialsfilter);
    CLASS_ATTR_CATEGORY(c, "partialsfilter", 0, "Target");
    // @description Sets the partials filter

    
    CLASS_ATTR_SYM_VARSIZE(c, "orchestra", 0, t_solver, orchestra, orchestra_size, ORCHIDEA_SOLVE_MAX_ORCHESTRA);
    CLASS_ATTR_STYLE(c, "orchestra", 0, "text");
    CLASS_ATTR_LABEL(c, "orchestra", 0, "Orchestra");
    CLASS_ATTR_ACCESSORS(c, "orchestra", (method)NULL, (method)orchmax_solve_setattr_orchestra);
    CLASS_ATTR_BASIC(c, "orchestra", 0);
    CLASS_ATTR_CATEGORY(c, "orchestra", 0, "Orchestra");
    // @description Sets the orchestra.

    CLASS_ATTR_SYM_VARSIZE(c, "styles", 0, t_solver, styles, styles_size, ORCHIDEA_SOLVE_MAX_STYLES);
    CLASS_ATTR_STYLE(c, "styles", 0, "text");
    CLASS_ATTR_LABEL(c, "styles", 0, "Styles");
    CLASS_ATTR_ACCESSORS(c, "styles", (method)NULL, (method)orchmax_solve_setattr_styles);
    CLASS_ATTR_CATEGORY(c, "styles", 0, "Filters");
    // @description Sets the allowed styles.

    CLASS_ATTR_SYM_VARSIZE(c, "others", 0, t_solver, others, others_size, ORCHIDEA_SOLVE_MAX_OTHERS);
    CLASS_ATTR_STYLE(c, "others", 0, "text");
    CLASS_ATTR_LABEL(c, "others", 0, "Others");
    CLASS_ATTR_ACCESSORS(c, "others", (method)NULL, (method)orchmax_solve_setattr_others);
    CLASS_ATTR_CATEGORY(c, "others", 0, "Filters");
    // @description Sets other filters.
    
    CLASS_ATTR_SYM_VARSIZE(c, "extrapitches", 0, t_solver, extrapitches, extrapitches_size, ORCHIDEA_SOLVE_MAX_EXTRAPITCHES);
    CLASS_ATTR_STYLE(c, "extrapitches", 0, "text");
    CLASS_ATTR_LABEL(c, "extrapitches", 0, "Extra Pitches");
    CLASS_ATTR_ACCESSORS(c, "extrapitches", (method)NULL, (method)orchmax_solve_setattr_extrapitches);
    CLASS_ATTR_CATEGORY(c, "extrapitches", 0, "Target");
    // @description Sets extra pitches.
    
    CLASS_ATTR_SYM_VARSIZE(c, "dynamics", 0, t_solver, dynamics, dynamics_size, ORCHIDEA_SOLVE_MAX_DYNAMICS);
    CLASS_ATTR_STYLE(c, "dynamics", 0, "text");
    CLASS_ATTR_LABEL(c, "dynamics", 0, "Dynamics");
    CLASS_ATTR_ACCESSORS(c, "dynamics", (method)NULL, (method)orchmax_solve_setattr_dynamics);
    CLASS_ATTR_CATEGORY(c, "dynamics", 0, "Filters");
    // @description Sets the allowed dynamics.

    CLASS_ATTR_CHAR(c, "verbose", 0, t_solver, verbose);
    CLASS_ATTR_STYLE(c, "verbose", 0, "onoff");
    CLASS_ATTR_LABEL(c, "verbose", 0, "Verbose");
    // @description Toggles the verbose mode

    CLASS_ATTR_CHAR(c, "parallel", 0, t_solver, parallel);
    CLASS_ATTR_STYLE(c, "parallel", 0, "onoff");
    CLASS_ATTR_LABEL(c, "parallel", 0, "Parallel");
    // @description When this attribute is 1, the computations are performed in a separate thread.

    class_register(CLASS_BOX, c);
    orchmax_solve_class = c;
}
void orchmax_solve_assist(t_solver *x, void *b, long m, long a, char *s)
{
    if (m == ASSIST_INLET) {
        if (a == 0) {
            sprintf(s, "symbol: Target Audio File"); // @in 0 @type symbol @digest Target audio file
        } else if (a == 1) {
            sprintf(s, "list: Orchestra"); // @in 1 @type list @digest List of orchestral instruments to be used
        } else {
            sprintf(s, "symbol/list: Database File(s)"); // @in 2 @type symbol/list @digest File or files containing the database (usually ending with .db)
        }
    } else {
        if (a == 0)
            sprintf(s, "list: Output Files Prefix, Number of Segments and Number of Solutions for each Segment");
            // @out 0 @type symbol/list @digest Output prefix, number of found segments and number of found solutions for each segment
        else
            sprintf(s, "list: Notifications"); // @out 1 @type list @digest Notifications
    }
}

void orchmax_solve_free(t_solver *x) {
    long i;
    for (i = 1; i < 3; i++)
        object_free(x->n_proxy[i]);

    orchidea_destroy(x->orc_hand);
}

void orchmax_solve_bang_do(t_solver *x, t_symbol *s, long ac, t_atom *av) {
    if (x->running_threads >= ORCHIDEA_SOLVE_MAX_THREADS) {
        object_warn((t_object*) x, "pending actions; please retry later...");
        return;
    }
    
    thread_data *d = (thread_data *)sysmem_newptr(sizeof(thread_data)); // delete after thread call - I think it works since thare are no modif during thread
    d->x = x;
    d->s = gensym("orchestrate");
    d->ac = 0;
    d->av = NULL;
    
    atom_setsym(d->av, gensym("orchestrate"));
    
    if (x->current_target) {
        if (x->parallel) {
            pthread_create(&x->thread_pool[x->running_threads], NULL, orchidea_solve_dispatcher, (void*) d);
        } else {
            orchidea_solve_dispatcher(d);
        }
    } else {
        object_error((t_object *)x, "target not defined: cannot orchestrate");
    }
}

void orchmax_solve_bang(t_solver *x) {
    defer(x, (method)orchmax_solve_bang_do, NULL, 0, NULL);
}

// suppose soundpath is allocated with
void dbpath_to_soundpath(char *dbpath, char *soundpath) {
    std::string src(dbpath);
    std::string out = removeExtension(removeExtension(src)); // intentional double call: the name should be XXXXXXX.featurename.db -> let's remove the last two parts
    snprintf(soundpath, MAX_PATH_CHARS, "%s", out.c_str());
}

void orchmax_solve_anything_do(t_solver *x, t_symbol *s, long ac, t_atom *av) {
    if (s == gensym("resetfilters")) {
        if (x->verbose) object_post((t_object*) x, "resetting all filters");

        orchidea_reset_filters(x->orc_hand);
        
    } else {
        long inlet = proxy_getinlet((t_object *) x);

        thread_data *d = (thread_data *)sysmem_newptr(sizeof(thread_data)); // delete after thread call - I think it works since thare are no modif during thread
        d->x = x;
        
        if (inlet == 0) {
            // heavy actions are executed in a separated thread (or pool)
            if (x->running_threads >= ORCHIDEA_SOLVE_MAX_THREADS) {
                object_warn((t_object*) x, "pending actions; please retry later...");
                return;
            }
            
            // set target and orchestrate
            d->s = gensym("target");
            d->ac = 1;
            d->av = (t_atom *)sysmem_newptr(sizeof(t_atom));
            atom_setsym(d->av, s ? s : (ac ? atom_getsym(av) : gensym("none") /*should never happen*/));
            
        } else if (inlet == 1) {
            // set orchestra
            long j = 0;
            d->s = gensym("orchestra");
            d->ac = (s && s != gensym("list") ? ac + 1 : ac);
            d->av = (t_atom *)sysmem_newptr(d->ac * sizeof(t_atom));
            if (s && s != gensym("list")) {
                atom_setsym(d->av, s);
                j++;
            }
            for (long i = 0; i < ac; i++)
                d->av[j++] = av[i];
            
            object_attr_setvalueof((t_object *)x, gensym("orchestra"), d->ac, d->av);
            sysmem_freeptr(d->av);
            return;
        } else {
            // heavy actions are executed in a separated thread (or pool)
            if (x->running_threads >= ORCHIDEA_SOLVE_MAX_THREADS) {
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
            for (long i = 0; i < ac; i++)
                d->av[j++] = av[i];
            
            // setting sound paths properly, if soundpaths is default
            char** sl  = (char**)sysmem_newptr((d->ac + 1) * sizeof (char*));
            sl[0] = (char*) "sound_paths";
            for (long i = 1; i < d->ac + 1; i++) {
                sl[i] = (char *)sysmem_newptr(MAX_PATH_CHARS * sizeof(char));
            }
            for (long i = 0; i < d->ac; i++) { // cycle on each of the db file names
                if (i >= x->soundpaths_size || x->soundpaths[i] == gensym("default")) { // if the soundpath attribute is "default"
                    t_symbol *this_path = conform_path(atom_getsym(d->av+i)); // take the current db filename
                    if (this_path) {
                        dbpath_to_soundpath(this_path->s_name, sl[i+1]); // if it exists (should ALWAYS be the case), strip it
                    } else {
                        snprintf_zero(sl[i+1], MAX_PATH_CHARS, "%s", x->soundpaths[i]->s_name);
                    }
                } else {
                    snprintf_zero(sl[i+1], MAX_PATH_CHARS, "%s", x->soundpaths[i]->s_name);
                }
            }
            orchidea_set_param(x->orc_hand, (const char**) sl, (int) d->ac + 1);
            if (x->verbose) object_post((t_object *)x, "sounds have been set correctly");
            for (long i = 1; i < d->ac + 1; i++) {
                sysmem_freeptr(sl[i]);
            }
            sysmem_freeptr(sl);
        }
        if (x->parallel) {
            pthread_create(&x->thread_pool[x->running_threads], NULL, orchidea_solve_dispatcher, (void*) d);
        } else {
            orchidea_solve_dispatcher(d);
        }
    }
}

void orchmax_solve_anything(t_solver *x, t_symbol *s, long ac, t_atom *av) {
    defer(x, (method)orchmax_solve_anything_do, s, ac, av);
}

void notifier (const char* action, void* user_data) {
    t_atom a;
    atom_setsym(&a, gensym(action));
    t_solver* instance = (t_solver*) user_data;
    outlet_anything(instance->out_2, gensym("status"), 1, &a);
}



void *orchmax_solve_new(t_symbol *s, long argc, t_atom *argv) {
    t_solver *x = NULL;
    
    if ((x = (t_solver *)object_alloc((t_class*)orchmax_solve_class))) {
        // flux and closest are only hard-codable in the max object. Initializing hard-coded attributes:
        x->segmentation = gensym("flux");
        x->connection = gensym("closest");
        
        // initializing attributes to default values
        x->soundpaths[0] = gensym("default");
        x->soundpaths_size = 1;
        x->prefix = gensym("");
        x->search = gensym("genetic");
        x->popsize = 300;
        x->maxepochs = 300;
        x->pursuit = 0;
        x->xoverrate = .8;
        x->mutationrate = .01;
        x->sparsity = 0.001;
        x->positivepenalization = 1.;
        x->negativepenalization = 10.;
        x->onsetthreshold = 2;
        x->onsettimegate = 100;
        x->partialswindow = 32768;
        x->partialsfilter = .2;
        x->verbose = true; // just for now?

        x->n_proxy[2] = proxy_new((t_object *) x, 2, &x->n_in);
        x->n_proxy[1] = proxy_new((t_object *) x, 1, &x->n_in);

        x->running_threads = 0;
        x->orc_hand = orchidea_create(x->segmentation->s_name, x->connection->s_name);
        x->parallel = 1; // DG: I'm not so sure this should be the default. I see the point, of course, but custom threading in Max is prone to crashes...
        
        if (!x->orc_hand) {
            // should never happen!
            error("Cannot create orchidea.solve with these parameters.");
            return NULL;
        }
        
        attr_args_process(x, argc, argv);
        
        object_attr_setdisabled((t_object *)x, gensym("connection"), true);
        object_attr_setdisabled((t_object *)x, gensym("segmentation"), true);
        
        x->callback = new Callback ();
        x->callback->notifier = notifier;
        x->callback->user_data = x;
        
        orchidea_set_callback(x->orc_hand, x->callback);
        x->out_2 = outlet_new(x, NULL);
        x->out_1 = outlet_new(x, NULL);
        
    }

    return (x);
}
