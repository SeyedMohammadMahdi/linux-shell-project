#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

#include "init.h"
#include "currentpath.h"
#include "readline.h"
#include "parser.h"


#define PATHL 1000
#define MAXINPUT 1000
#define MAXARGS 300

//typedef enum {} COMMAND;






int main()
{	
	char cPath[PATHL];
	char input[MAXINPUT];
	char *parsedInput[MAXARGS];
	
	init();
	while(1)
	{
		currentPath(cPath);
		printf("%s", cPath);
		inputReader(input);
		parser(input, parsedInput);
		
	}
	
	
	return 0;
}




