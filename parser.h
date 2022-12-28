#ifndef PARSER_H
#define PARSER_H
#include <string.h>
#include <stdio.h>

int parser(char *str, char **param)
{	
	int i = 0;
	char *qoute = strchr(str, '\"');
	// if input string contains double qoutes this condition is true
	if(qoute != NULL){
		char *str2;
		str2 = strsep(&str, "\"");
		param[i++] = strsep(&str2, " ");
		while(param[i - 1] != NULL){
			param[i++] = strsep(&str2, " ");
		}
		param[i - 2] = strsep(&str, "\"");
		param[i-1] = NULL;
		return i;
		
	}
	// if the is no qoutes in input string the following codes are executed
	param[i++] = strsep(&str, " ");
	while(param[i - 1] != NULL){
		param[i++] = strsep(&str, " ");
	}
	return i - 1;
}



#endif
