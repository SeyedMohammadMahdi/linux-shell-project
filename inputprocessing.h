#ifndef INPUTPROCESSING_H
#define INPUTPROCESSING_H

#include "parser.h"
#include "common.h"
#include <string.h>

commandType inputProcessing(char *str, char **parsedStr)
{
	parser(str, parsedStr);
	
	if(strcmp("msto", parsedStr[0]) == 0 ||
	strcmp("cd", parsedStr[0]) == 0)
		return CUSTOM;
	else
		return BUILTIN;
		
	

}

#endif
