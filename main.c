#include <stdio.h>
#include "helpers/vector.h"
#include "helpers/buffer.h"
#include "compiler.h"
int main()
{
    int res = compile_file("test.c", "./test", 0);

    if(res == COMPILER_FILE_COMPILED_OK)
    {
        printf("everything compiled fine\n");
    }
    else if(res == COMMPILER_FAILED_WITH_ERRORS)
    {
        printf("compile failed\n");
    }
    else
    {
        printf("unknown response for file compiler\n");
    }

    return 0;
}