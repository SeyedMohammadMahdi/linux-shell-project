#ifndef PARSER_H
#define PARSER_H
#include <string.h>
#include <stdio.h>

int parser(char *str, char **param)
{	
	int i = 0;
	char *qoute = strchr(str, '\"');
	if(qoute != NULL){
		char *str2;
		str2 = strsep(&str, "\"");
		param[i++] = strsep(&str2, " ");
		while(param[i - 1] != NULL){
			param[i++] = strsep(&str2, " ");
		}
		param[i - 2] = strsep(&str, "\"");
		param[i-1] = NULL;
//		printf("%s", param[i - 3]);
		return i;
		
	}
	param[i++] = strsep(&str, " ");
	while(param[i - 1] != NULL){
		param[i++] = strsep(&str, " ");
	}
	return i - 1;
}



#endif
