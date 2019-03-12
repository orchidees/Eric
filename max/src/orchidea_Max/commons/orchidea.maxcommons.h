// tokenizer.h
//

#ifndef ORCHIDEA_MAXCOMMONS_H
#define ORCHIDEA_MAXCOMMONS_H

#include "ext.h"                            // standard Max include, always required
#include "ext_obex.h"                        // required for new style Max object


#define ORCHIDEA_MAX_MAX_LIST_SIZE 32766      // this is 2^15-2 (1 is due to the message selector, 1 is just out of precaution, that's on us :-)
                                              // The double MAX is intentional: it is the Maximum list size in Max

typedef struct _thread_data {
    t_object* x;
    t_symbol* s;
    long ac;
    t_atom* av;
} thread_data;


t_symbol *orchidea_locate_file(t_symbol *file_name, t_fourcc *file_type);
t_symbol *orchidea_ezlocate_file(t_symbol *file_name);
t_symbol *orchidea_conform_path(t_symbol *path);


t_symbol *orchidea_locate_file(t_symbol *file_name, t_fourcc *file_type)
{
    char filename[MAX_FILENAME_CHARS];
    short path = 0;
    
    if (!file_name)
        return NULL;
    
    if (file_type) *file_type = 0;
    
    if (path_frompathname(file_name->s_name, &path, filename)) {
        t_fourcc type;
        char file_path_str[MAX_FILENAME_CHARS];
        strncpy_zero(file_path_str, file_name->s_name, MAX_FILENAME_CHARS);
        if (!locatefile_extended(file_path_str, &path, &type, &type, -1))  {
            char filenameok2[MAX_FILENAME_CHARS];
            path_topathname(path, file_path_str, filename);
            path_nameconform(filename, filenameok2, PATH_STYLE_MAX, PATH_TYPE_BOOT);
            if (file_type) *file_type = type;
            return gensym(filenameok2);
        }
    } else {
        char filenameok[MAX_FILENAME_CHARS];
        char filenameok2[MAX_FILENAME_CHARS];
        path_topathname(path, filename, filenameok);
        path_nameconform(filenameok, filenameok2, PATH_STYLE_MAX, PATH_TYPE_BOOT);
        return gensym(filenameok2);
    }
    
    return NULL;
}

t_symbol *orchidea_ezlocate_file(t_symbol *file_name)
{
    return orchidea_locate_file(file_name, NULL);
}

t_symbol *orchidea_conform_path(t_symbol *path)
{
    if (!path) {
        return NULL;
    }
    
    char outpath[MAX_PATH_CHARS];
    path_nameconform(path->s_name, outpath, PATH_STYLE_MAX, PATH_TYPE_BOOT);
    return gensym(outpath);
}

#endif	// ORCHIDEA_MAXCOMMONS_H

// EOF
