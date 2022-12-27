#ifndef MOSTOCCURANCE_H 
#define	MOSTOCCURANCE_H

#include <readline/readline.h>
#include <stdio.h>


int count[1000];
char strings[1000][1000];
int lastIndex = 0;

int search(char *str)
{
	int i;
	for(i = 0; i < lastIndex; i++){
		if(strcmp(str, strings[i]) == 0)
			return 1;
	}
	return 0;
}

void update(char *str)
{
	int i;
	for(i = 0; i < lastIndex; i++){
		if(strcmp(str, strings[i]) == 0){
			count[i]++;
			return;
		}
	}
}

void mostFrequent(char *fileName)
{	
	FILE *file;
	file = fopen(fileName, "r");
	char buf[1000];
	int maxIndex = 0, max = 0;
	int i;
	while(fgets(buf, 1000, file) != NULL){
		//buf = readline("");
		//if(strcmp(buf, "e") == 0)
		//	break;
			
		if(search(buf)){
			//printf("1\n");
			update(buf);
		}
		else{
			//strings[lastIndex++] = buf;
			strcpy(strings[lastIndex++], buf);
		}
	}
	
	for(i = 0; i < lastIndex; i++){
		if(count[i] > max){
			max = count[i];
			maxIndex = i;
		}
	}
	
	printf("\nmost occurate: %s\n", strings[maxIndex]);
	fclose(file);
	
}


#endif 
