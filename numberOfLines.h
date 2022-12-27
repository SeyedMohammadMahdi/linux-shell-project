#ifndef NUMBEROFLINES_H
#define NUMBEROFLINES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILE_NAME 100

// part f
int numberOfLines(FILE* fp, char filename[MAX_FILE_NAME]){
	
	int count = 0;
	char c; // To store a character read from file

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Could not open file %s", filename);
		return 0;
	}
	
	for (c = getc(fp); c != EOF; c = getc(fp))
		if (c == '\n') 
			count = count + 1;

	fclose(fp);
	printf("The file %s has %d lines \n", filename, count);
	printf("\n");

	return 0;
}

#endif