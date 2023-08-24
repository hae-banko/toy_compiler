#include "compiler.h"

/* Compile file will pass any .c file into the function and creating the object file.
 * This will return a 0.
 */

int compile_file(const char* filename, const char * out_filename, int flags)
{
    struct compile_process* process = compile_process_create(filename, out_filename, flags);
    if(!process) return COMMPILER_FAILED_WITH_ERRORS;

    // perform lexical analysis

    // perform parsing

    // perform code generation

    // usw...

    return COMPILER_FILE_COMPILED_OK;
}