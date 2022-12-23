#ifndef READLINE_H
#define READLINE_H

#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>


int inputReader(char* str)
{
    char* buf;
    buf = readline("$ ");
    add_history(buf);
    strcpy(str, buf);
    if(strlen(buf) != 0)
    	return 0;
    else
    	return 1;
}




#endif



