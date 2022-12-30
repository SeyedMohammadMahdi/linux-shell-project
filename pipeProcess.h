#ifndef PIPEPROCESS_H
#define PIPEPROCESS_H
#include <string.h>

int pipeProcess(char* str, char **pipes)
{
    	pipes[0] = strsep(&str, "|");
   	pipes[1] = strsep(&str, "|");    		
  	if(pipes[1] != NULL)
  		return 1;
	return 0;
}



#endif
