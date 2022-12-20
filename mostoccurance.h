#ifndef MOSTOCCURANCE_H 
#define	MOSTOCCURANCE_H

#include <readline/readline.h>
#include <stdio.h>


void update(char **strings, char *string, int *count, int lastIndex)
{
	int i;
	for(i = 0; i < lastIndex; i++){
		if(strcmp(strings[i], string) == 0){
			count[i]++;
			return;
		}
	}
}


int search(char **strings, char *string, int lastIndex)
{
	int i;
	for(i = 0; i < lastIndex; i++){
		if(strcmp(string, strings[i]) == 0)
			return 1;
	} 
	return 0;
}


void mostOccurance()
{
	int maxIndex = 0, max = 0, lastIndex = 0;
	char input[1000],  *strings[1000];
	int count[1000];
	int j;
	for(j = 0; j < 1000; j++)
	{
		count[j] = 0;
	}
	
	scanf("%s", input);
	while(strcmp("e", input) != 0){
		if(search(strings, input, lastIndex)){
			update(strings, input, count, lastIndex);
		}
		else {
			strings[lastIndex] = input;
			lastIndex++;
		}
		scanf("%s", input);
		//printf("**%s\n", input);
	}
	
	int i;
	for(i = 0; i < lastIndex; i++){
		if(count[i] > max){
			max = count[i];
			maxIndex = i;
			//printf("%d\n", maxIndex);
		}
	}
	
	printf("%s", strings[maxIndex]);	
}





#endif 
