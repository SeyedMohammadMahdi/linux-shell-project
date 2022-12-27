#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

#include "init.h"
#include "currentpath.h"
#include "readline.h"
#include "parser.h"
#include "inputprocessing.h"
#include "clear.h"
#include "common.h"
#include "mainLines.h"
#include "mostfrequent.h"
#include "rmvEmpty.h"
#include "tenFirstLine.h"
#include "numberOfLines.h"
#include "splittingLine.h"

#define PATHL 1000
#define MAXINPUT 1000
#define MAXARGS 300

char cPath[PATHL];
char userAndHost[PATHL];
int flag = 1;




void intruptHandler(int s){
	printf("\npress enter again");
	flag = 0;
	return;
}


int myCD(char **args);

int myCD(char **args){
	if(args[1] == NULL){ // no directory provided
		write(STDOUT_FILENO,"\nEXPECTED ARGUMENT TO 'cd'\n",strlen("\nEXPECTED ARGUMENT TO 'cd'\n"));
	} else{ 
		if(chdir(args[1]) != 0){
			write(STDOUT_FILENO,"No such directory as '",strlen("No such directory as '"));
			write(STDOUT_FILENO,args[1],strlen(args[1]));
			write(STDOUT_FILENO,"'\n",strlen("'\n"));
		}
	}
	//chdir(args[1]);
	//printf("hello");
	return 1;
}


int main()
{	
	
	char input[MAXINPUT];
	char *parsedInput[MAXARGS];
	int initFlag = 1;
	commandType type;
	signal(SIGINT, intruptHandler);
	FILE* ptr;
	
	
	while(1)
	{
		flag = 1;
		if(initFlag){
			init();
			initFlag = 0;
		}
		
		currentPath(userAndHost, cPath);
		
		
		if(inputReader(input, userAndHost, cPath))
			continue;
			
		if(flag)
		{
			type = inputProcessing(input, parsedInput, &initFlag);
		
			if(type == BUILTIN)
			{
				pid_t child = fork();
				if(child == 0)
				{
					if(execvp(parsedInput[0], parsedInput) < 0){
						printf("\033[0;31m");
						printf("\ncommand \"%s\" not found or argument needed\n\n", parsedInput[0]);
					}
					exit(0);
				}
				else
				{
					wait(NULL);
				}
			}
			else if(strcmp(parsedInput[0], "exit") == 0)
			{
				return 0;
			}
			else if(type == CUSTOM)
			{
				
				if(strcmp(parsedInput[0], "cd") == 0){
					myCD(parsedInput);
				}
				else
				{
					pid_t child = fork();
				if(child == 0)
				{
					
				if(strcmp(parsedInput[0], "mainl") == 0)
					mainLines(ptr, parsedInput[1]);
					
				else if(strcmp(parsedInput[0], "mstf") == 0)
					mostFrequent(parsedInput[1]);
					
				else if(strcmp(parsedInput[0], "remove") == 0)
					rmvEmpty(ptr, parsedInput[1]);
					
				else if(strcmp(parsedInput[0], "split") == 0)
					splittingLine(ptr, parsedInput[1]);
					
				else if(strcmp(parsedInput[0], "ten") == 0)
					tenFirstLine(ptr, parsedInput[1]);
				
				else if(strcmp(parsedInput[0], "count") == 0)
					numberOfLines(ptr, parsedInput[1]);
					exit(0);
				}
				else 
				{
					wait(NULL);
				}
				}
				
			}
		}
	}
	
	
	return 0;
}



