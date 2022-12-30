#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>
#include <errno.h>
#include <error.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

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
#include "pipeProcess.h"
#include "pipeRunner.h"

#define PATHL 1000
#define MAXINPUT 1000
#define MAXARGS 300

char cPath[PATHL];
char userAndHost[PATHL];
int flag = 1;

sigjmp_buf ctrlc_buf;



void ctrlc(int signo) {
  if (signo == SIGINT) {
    printf("\n");
    siglongjmp(ctrlc_buf, 1);
  }
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
	char *parsedInput[MAXARGS], *pipe1[MAXARGS], *pipe2[MAXARGS];
	int initFlag = 1;
	commandType type;
	signal(SIGINT, ctrlc);
	FILE* ptr;
	
	
	while(1)
	{
		flag = 1;
		if(initFlag){
			init();
			initFlag = 0;
		}
		
		currentPath(userAndHost, cPath);
		
		while ( sigsetjmp( ctrlc_buf, 1 ) != 0 );
		if(inputReader(input, userAndHost, cPath))
			continue;
			
		if(flag)
		{
			type = inputProcessing(input, parsedInput, &initFlag, pipe1, pipe2);
		
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
			else if(type == EXIT)
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
							mainLines(ptr, parsedInput[1], parsedInput[2]);
					
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
			else if(type == PIPE)
			{
				//printf("***************");
				pipeRunner(pipe1, pipe2);
			}
		}
	}
	
	
	return 0;
}



