#ifndef INIT_H
#define INIT_H

#include <stdio.h>


void init()
{

	char *programmers[] = {"Zeynab Teymoori", "Seyed Mohammad Mahdi Niknam Bagheri", NULL};
	
	
	printf("**************************************\nprogrammers:\n\n");
	int i = 0;
	while(programmers[i])
	{
		printf("%d. %s\n", i+1, programmers[i]);
		i++;
	}
	
	printf("**************************************\n\n");
}

#endif
