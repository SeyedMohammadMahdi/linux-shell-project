#ifndef PARSER_H
#define PARSER_H
#include <string.h>


int parser(char *str, char **param)
{	
	int i = 0;
	param[i++] = strsep(&str, " ");
	while(param[i - 1] != NULL){
		param[i++] = strsep(&str, " ");
	}
	return i - 1;
}



#endif
