#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "currentpath.h"

#define PATHL 1000

void yourFunction(/*params*/)
{
	pid_t id = fork();
	
	//child process
	if(id == 0)
	{
		//your program goes here
		//sample code
		printf("file processing\n");
	}
	
	//parent process
	else
	{	printf("%d", getpid());
		printf("%d", wait(NULL));
		return;
	}

}


int main()
{	
	char cPath[PATHL];
	
	//while(1){
		currentPath(cPath);		
		printf("%s", cPath);
	//}
	return 0;
}
