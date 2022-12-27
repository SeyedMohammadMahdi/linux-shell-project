#ifndef SPLITTINGLINE_H
#define SPLITTINGLINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILE_NAME 100

// part a
int splittingLine(FILE* ptr, char filename[MAX_FILE_NAME]){
	
	ptr = fopen(filename, "r");
	if (NULL == ptr) {
		printf("file can't be opened \n");
		return 0;
	}
	
	
	char str[50];
	printf("content of this file are: \n");
	char * pch;
	while (fgets(str, 50, ptr) != NULL) {
		pch = strtok (str," \n");
		if(strcmp ("EOF", pch) != 0){
			printf("%s\n", pch);
		}
	}
	printf("\n");
	fclose(ptr);
	return 0;
}


#endif
