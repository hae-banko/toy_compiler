#ifndef TOYCOMPILER_H
#define TOYCOMPILER_H

#include <stdio.h>
#include <stdbool.h>

enum
{
    COMPILER_FILE_COMPILED_OK,
    COMMPILER_FAILED_WITH_ERRORS
};

// Token types that we are going to use.
// ref? https://dev.to/lefebvre/compilers-101---overview-and-lexer-3i0m
// ref? https://en.wikipedia.org/wiki/Lexical_analysis
enum
{
    TOKEN_TYPE_IDENTIFIER,
    TOKEN_TYPE_KEYWORD,
    TOKEN_TYPE_OPERATOR,
    TOKEN_TYPE_SYMBOL,
    TOKEN_TYPE_NUMBER,
    TOKEN_TYPE_STRING,
    TOKEN_TYPE_COMMENT,
    TOKEN_TYPE_NEWLINE
};

// position for each token, needed for its own identity!
struct pos
{
    int line;
    int col;
    const char * filename;
};

/*The question here: what does the token need to know???*/
struct token
{
    int type;
    int flags;

    // To prevent us from consuming more memory than what we need.
    // this also prevents string token to not be integer token,
    // and so on.
    union
    {
        char cval;          // lexer will select cval if it meets char
        const char* sval;   // lexer will select sval if it meets string
        unsigned int inum;  // and so on...
        unsigned long lnum;
        unsigned long long llnum;
        void * any;
    };

    // True if there is whitespace between the token and the next token
    // i.e. * a for operator token * would mean whitespace would be set
    // for token "a"
    bool whitespace;

    // Example the token (Hello world) every token inside this will have
    // pointer between the brackets.
    const char * between_brackets;
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