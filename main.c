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
	commandType type;
	init();
	while(1)
	{
		
		currentPath(cPath);
		printf("%s", cPath);
		inputReader(input);
		type = inputProcessing(input, parsedInput);
		
		if(type == BUILTIN)
		{
			pid_t child = fork();
			if(child == 0)
			{
				if(execvp(parsedInput[0], parsedInput) < 0)
					printf("\ncommand \" %s \" not found or argument needed\n\n", parsedInput[0]);
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




