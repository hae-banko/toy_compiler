#ifndef TOYCOMPILER_H
#define TOYCOMPILER_H

#include <stdio.h>

enum
{
    COMPILER_FILE_COMPILED_OK,
    COMMPILER_FAILED_WITH_ERRORS
};

struct compile_process
{
    // the flags in regards to how this file should be compiled
    int flags;

    struct compile_process_input_file
    {
        FILE * fp;
        const char* abs_path;
    } cfile;

    FILE * ofile;
};

int compile_file(const char* filename, const char * out_filename, int flags);

#endif