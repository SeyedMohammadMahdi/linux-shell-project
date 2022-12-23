#ifndef INIT_H
#define INIT_H

#include <stdio.h>

/*
30 black
31 red
32 green
33 yellow
34 blue
35 purple
36 cyne
37 white
*/


void init()
{
	
	printf("\033[0;36m");
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
