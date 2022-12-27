#ifndef INPUTPROCESSING_H
#define INPUTPROCESSING_H

#include "parser.h"
#include "common.h"
#include <string.h>

commandType inputProcessing(char *str, char **parsedStr, int *initFlag)
{
	parser(str, parsedStr);
	
	if(strcmp(parsedStr[0], "clear") == 0)
		*initFlag = 1;
	
	if(strcmp("mstf", parsedStr[0]) == 0 ||
		strcmp("cd", parsedStr[0]) == 0 ||
		strcmp("exit", parsedStr[0]) == 0 ||
		strcmp("mainl", parsedStr[0]) == 0 ||
		strcmp("remove", parsedStr[0]) == 0 ||
		strcmp("split", parsedStr[0]) == 0 ||
		strcmp("ten", parsedStr[0]) == 0 ||
		strcmp("count", parsedStr[0]) == 0
		)
		
		return CUSTOM;
	else
		return BUILTIN;
		
	

}

#endif
