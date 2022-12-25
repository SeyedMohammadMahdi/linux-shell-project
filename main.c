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

int main()
{	
	
	char input[MAXINPUT];
	char *parsedInput[MAXARGS];
	int initFlag = 1;
	commandType type;
	signal(SIGINT, intruptHandler);
	
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
			else 
			{
				if(strcmp(parsedInput[0], "exit") == 0)
					return 0;
				/*custom command handler*/
				//chdir(parsedInput[1]);
				
				/****************************************************/
				/*  file processing commands should be writen here  */
				/****************************************************/
			}
		}
	}
	
	
	return 0;
}




