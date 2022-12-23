#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

#include "init.h"
#include "currentpath.h"
#include "readline.h"
#include "parser.h"
#include "inputprocessing.h"
#include <stdlib.h>

#define PATHL 1000
#define MAXINPUT 1000
#define MAXARGS 300

//typedef enum {} COMMAND;






int main()
{	
	char cPath[PATHL];
	char input[MAXINPUT];
	char *parsedInput[MAXARGS];
	int initFlag = 1;
	commandType type;
	
	while(1)
	{
		
		if(initFlag){
			init();
			initFlag = 0;
		}
		
		currentPath(cPath);
		printf("\033[0;34m");
		printf("%s", cPath);
		printf("\033[0;37m");
		if(inputReader(input))
			continue;
		type = inputProcessing(input, parsedInput, &initFlag);
		
		if(type == BUILTIN)
		{
			pid_t child = fork();
			if(child == 0)
			{
				if(execvp(parsedInput[0], parsedInput) < 0)
					printf("\033[0;31m");
					printf("\ncommand \"%s\" not found or argument needed\n\n", parsedInput[0]);
				exit(0);
			}
			else
			{
				wait(NULL);
			}
		}
		else 
		{
			/*custom command handler*/
			//chdir(parsedInput[1]);
		}
	}
	
	
	return 0;
}




