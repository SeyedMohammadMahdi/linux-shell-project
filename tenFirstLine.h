#ifndef TENFIRSTLINE_H
#define TENFIRSTLINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILE_NAME 100

// part g
int tenFirstLine(FILE* ptr, char filename[MAX_FILE_NAME]){
	int count = 0;
	ptr = fopen(filename, "r");
	if (NULL == ptr) {
		printf("file can't be opened \n");
		return 0;
	}
	
	char str[50];
	printf("content of this file are: \n");
	char * pch;
	while (fgets(str, 50, ptr) != NULL && count<10) {
		if(strcmp ("EOF", str) != 0){
			printf("%s", str);
			count = count + 1;
		}
	}
	printf("\n");
	fclose(ptr);
	return 0;
}

#endif
