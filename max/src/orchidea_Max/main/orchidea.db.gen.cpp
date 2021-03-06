/**
 @file
 orchidea.db.gen.cpp
 
 @name
 orchidea.db.gen
 
 @realname
 orchidea.db.gen
 
 @type
 object
 
 @module
 orchidea
 
 @author
 Carmine Emanuele Cella
 
 @digest
 Generate database from a source folder
 
 @description
 Analyzes a set of audio samples contained in a source foler to generate a database that can be used by orchidea.solve.
 
 @discussion
 
 @category
 orchidea database
 
 @keywords
 orchestration, instrumentation, dataset, sample, generate, database
 
 @seealso
 orchidea.db.gen, orchidea.db.browse, orchidea.solve
 
 @owner
 Carmine Emanuele Cella
*/

#include "orchidea.h"
#include "tokenizer.h"
#include "orchidea.maxcommons.h"

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
    t_symbol*   db_name;
    long        win_size;
    long        hop_size;
    long        num_dimensions;
    t_symbol*   feature_name;
    
    char        parallel;
    char        verbose;

    void        *out_1;
    void        *out_2;

    OrchideaHandle* orc_hand;
    pthread_t thread_pool[ORCHIDEA_DBGEN_MAX_THREADS];
    int running_threads;
    std::vector<std::string> sounds;

    Callback*  callback;
    
} t_dbgen;


///////////////////////// function prototypes
//// standard set
void *orchmax_dbgen_new(t_symbol *s, long argc, t_atom *argv);
void orchmax_dbgen_free(t_dbgen *x);
void orchmax_dbgen_assist(t_dbgen *x, void *b, long m, long a, char *s);
void orchmax_dbgen_inletinfo(t_dbgen *x, void *b, long a, char *t);

void orchmax_dbgen_anything(t_dbgen *x, t_symbol *s, long ac, t_atom *av);
void orchmax_dbgen_bang(t_dbgen *x);


//////////////////////// global class pointer variable
void *orchmax_dbgen_class;


void notifier (const char* action, void* user_data) {
    t_atom a;
    atom_setsym(&a, gensym(action));
    t_dbgen* instance = (t_dbgen*) user_data;
    outlet_anything(instance->out_2, gensym("status"), 1, &a);
}

void* orchidea_dbgen_dispatcher (void* d) {
    
    thread_data* data = (thread_data*) d;
    t_dbgen* x = (t_dbgen *)data->x;
    
    t_atom busy;
    atom_setlong(&busy, 1);
    outlet_anything(x->out_2, gensym("busy"), 1, &busy);
    
    x->running_threads++;
    if (x->verbose) object_post((t_object*) x, "current thread n. %d", x->running_threads);

    if (strlen(x->db_folder->s_name) == 0 || strlen (x->feature_name->s_name) == 0) {
        object_error((t_object*) x, "error: feature name or db folder not set");
    }
    else {
        std::stringstream outname;
        if (x->db_name== gensym("default")) { // if the db_name attribute is "default"
            std::string tmp (x->db_folder->s_name);
            if (tmp.size () < 2) error ("invalid name for sound folder");
            if (tmp[tmp.size () - 1] == '/' || tmp[tmp.size () - 1] == '\\') {
                tmp = tmp.substr(0, tmp.size () - 1);
            }
            outname << tmp.c_str () << "." << x->feature_name->s_name << ".db";
        } else {
            outname << x->db_name->s_name;
        }
    
        post ("%s", outname.str ().c_str ());
        int r = 0;
        
        r = orchidea_analyse_sounds (x->orc_hand, x->db_folder->s_name, outname.str().c_str(),
                                         (int) x->win_size, (int) x->hop_size,
                                         (int) x->num_dimensions,
                                         x->feature_name->s_name);
        if (r != ORCHIDEA_NO_ERROR) {
            object_error((t_object *)x, "error: %s (%s)", orchidea_decode_error(r),
                        orchidea_get_error_details(x->orc_hand));
        } else {
            t_atom out;
            atom_setsym(&out, gensym(outname.str ().c_str ()));
            outlet_anything(x->out_1, gensym("dbname"), 1, &out);
            if (x->verbose) object_post((t_object *)x, "analysis has been done correctly");
        }

    }

    atom_setlong(&busy, 0);
    outlet_anything(x->out_2, gensym("busy"), 1, &busy);
    x->running_threads--;
    
    return NULL;
}
void ext_main(void *r) {
    t_class *c;
    
    c = class_new("orchidea.db.gen", (method)  orchmax_dbgen_new, (method)orchmax_dbgen_free, (long)sizeof(t_dbgen),
                  0L /* leave NULL!! */, A_GIMME, 0);


    // @method symbol @digest Analyze folder and produce database file
    // @description A symbol the left inlet sets the path of the folder that should be analyzed to produce an orchidea database; then triggers
    // the analysis and outputs the database filename.
    class_addmethod(c, (method)orchmax_dbgen_anything,        "anything",    A_GIMME, 0);

    // @method bang @digest Produce database file
    // @description When a <m>bang</m> is received, the database file is produced by analyzing the last input folder.
    class_addmethod(c, (method)orchmax_dbgen_bang,            "bang",            0);

    class_addmethod(c, (method)orchmax_dbgen_assist,    "assist",        A_CANT,        0);
    class_addmethod(c, (method)orchmax_dbgen_inletinfo,    "inletinfo",    A_CANT,        0);

    CLASS_ATTR_LONG(c, "windowsize", 0, t_dbgen, win_size);
    CLASS_ATTR_STYLE(c, "windowsize", 0, "text");
    CLASS_ATTR_LABEL(c, "windowsize", 0, "Analysis Window Size");
    CLASS_ATTR_CATEGORY(c, "windowsize", 0, "Analysis");
    // @description Sets the size of the analysis window

    CLASS_ATTR_LONG(c, "hopsize", 0, t_dbgen, hop_size);
    CLASS_ATTR_STYLE(c, "hopsize", 0, "text");
    CLASS_ATTR_LABEL(c, "hopsize", 0, "Analysis Hop Size");
    CLASS_ATTR_CATEGORY(c, "hopsize", 0, "Analysis");
    // @description Sets the hop size of the analysis

    CLASS_ATTR_LONG(c, "numdimensions", 0, t_dbgen, num_dimensions);
    CLASS_ATTR_STYLE(c, "numdimensions", 0, "text");
    CLASS_ATTR_LABEL(c, "numdimensions", 0, "Number Of Dimensions To Store");
    CLASS_ATTR_CATEGORY(c, "numdimensions", 0, "Analysis");
    // @description Sets the number of dimensions to store.
    // For instance, on a spectrum analysis 
    
    
    CLASS_ATTR_SYM(c, "feature", 0, t_dbgen, feature_name);
    CLASS_ATTR_ENUM(c,"feature",0,"spectrum logspec specpeaks specenv mfcc moments");
    CLASS_ATTR_LABEL(c, "feature", 0, "Feature");
    CLASS_ATTR_CATEGORY(c, "feature", 0, "Analysis");
    // @description Sets the analysis feature.
    
    CLASS_ATTR_SYM(c, "dbname", 0, t_dbgen, db_name);
    CLASS_ATTR_STYLE(c, "dbname", 0, "text");
    CLASS_ATTR_LABEL(c, "dbname", 0, "Output Name for Database");
    CLASS_ATTR_BASIC(c, "dbname", 0);
    // @description Sets the name of the database.
    // By default output files will be put in the same folder of the sounds.
    
    CLASS_ATTR_CHAR(c, "verbose", 0, t_dbgen, verbose);
    CLASS_ATTR_STYLE(c, "verbose", 0, "onoff");
    CLASS_ATTR_LABEL(c, "verbose", 0, "Verbose");
    // @description Toggles the verbose mode.
    
    CLASS_ATTR_CHAR(c, "parallel", 0, t_dbgen, parallel);
    CLASS_ATTR_STYLE(c, "parallel", 0, "onoff");
    CLASS_ATTR_LABEL(c, "parallel", 0, "Parallel");
    // @description When this attribute is 1, the computations are performed in a separate thread. <br />
    // This is beyond the edge of legality in Max, so use this at your own risk: for instance, don't modify the object or close the patch while running,
    // because this will more than likely cause crashes.

    
    class_register(CLASS_BOX, c);
    orchmax_dbgen_class = c;
}

void orchmax_dbgen_bang_do(t_dbgen *x, t_symbol *s, long ac, t_atom *av) {
    if (x->running_threads >= ORCHIDEA_DBGEN_MAX_THREADS) {
        object_warn((t_object*) x, "pending actions; please retry later...");
        return;
    }
    

    thread_data *d = (thread_data *)sysmem_newptr(sizeof(thread_data)); // delete after thread call - I think it works since thare are no modif during thread
    d->x = (t_object *)x;
    
    if (x->parallel) {
        pthread_create(&x->thread_pool[x->running_threads], NULL, orchidea_dbgen_dispatcher, (void*) d);
    } else {
        orchidea_dbgen_dispatcher(d);
    }
}

void orchmax_dbgen_bang(t_dbgen *x) {
    defer(x, (method)orchmax_dbgen_bang_do, NULL, 0, NULL);
}

void orchmax_dbgen_free(t_dbgen *x) {
    orchidea_destroy(x->orc_hand);
}

void orchmax_dbgen_assist(t_dbgen *x, void *b, long m, long a, char *s)
{
    if (m == ASSIST_INLET) {
        sprintf(s, "symbol: Folder"); // @in 0 @type symbol @digest Folder to be analyzed
    } else {
        if (a == 0)
            sprintf(s, "list: Database Filename"); // @out 0 @type list @digest Database filename and path
        else
            sprintf(s, "anything: Notifications"); // @out 1 @type anything @digest Notifications
    }
}


void orchmax_dbgen_inletinfo(t_dbgen *x, void *b, long a, char *t)
{
    if (a)
        *t = 1;
}

void orchmax_dbgen_anything_do(t_dbgen *x, t_symbol *s, long ac, t_atom *av) {
    // heavy actions are executed in a separated thread (or pool)
    if (x->running_threads >= ORCHIDEA_DBGEN_MAX_THREADS) {
        object_warn((t_object*) x, "pending actions; please retry later...");
        return;
    }

    x->db_folder = orchidea_ezlocate_file(ac == 0 ? s : atom_getsym(av));

    thread_data *d = (thread_data *)sysmem_newptr(sizeof(thread_data)); // delete after thread call - I think it works since thare are no modif during thread
    d->x = (t_object *)x;
    
    if (x->parallel) {
        pthread_create(&x->thread_pool[x->running_threads], NULL, orchidea_dbgen_dispatcher, (void*) d);
    } else {
        orchidea_dbgen_dispatcher(d);
    }
}

void orchmax_dbgen_anything(t_dbgen *x, t_symbol *s, long ac, t_atom *av) {
    defer(x, (method)orchmax_dbgen_anything_do, s, ac, av);
}

void *orchmax_dbgen_new(t_symbol *s, long argc, t_atom *argv) {
    t_dbgen *x = NULL;
    
    if ((x = (t_dbgen *)object_alloc((t_class*)orchmax_dbgen_class))) {

        x->running_threads = 0;
        x->orc_hand = orchidea_create("flux", "closest");
        
        x->callback = new Callback ();
        x->callback->notifier = notifier;
        x->callback->user_data = x;
        
        orchidea_set_callback(x->orc_hand, x->callback);
        
        x->win_size = 4096;
        x->hop_size = 2048;
        x->num_dimensions = 1024;
        x->feature_name = gensym ("spectrum");
        x->db_folder = gensym ("");
        x->db_name = gensym ("default");
        
        x->verbose = true;
        x->parallel = true;
        
        attr_args_process(x, argc, argv);
        
        x->out_2 = outlet_new(x, NULL);
        x->out_1 = outlet_new(x, NULL);
    }

    return (x);
}

