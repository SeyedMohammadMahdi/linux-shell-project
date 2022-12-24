#ifndef READLINE_H
#define READLINE_H

#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>


int inputReader(char* str, char* userAndHost, char* cPath)
{
    char* buf;
    char out[1000];
    strcpy(out, "\033[0;32m");
    strcat(out, userAndHost); 
    strcat(out, "\033[0;37m");
    strcat(out, ":\033[0;34m~");
    //strcat(out, "\033[0;34m");
    strcat(out, cPath);
    strcat(out, "\033[0;37m");
    strcat(out, "$ ");
    buf = readline(out);
    add_history(buf);
    strcpy(str, buf);
    if(strlen(buf) != 0)
    	return 0;
    else
    	return 1;
}




#endif



