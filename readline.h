#ifndef READLINE_H
#define READLINE_H

#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>


void inputReader(char* str)
{
    char* buf;
    buf = readline("> ");
    add_history(buf);
    strcpy(str, buf);
}




#endif



