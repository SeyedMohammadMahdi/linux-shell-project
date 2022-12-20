#include "readline.h"
#include <stdio.h>

int main()
{
	char str[1000];
	inputReader(str);
	printf("%s\n", str);
	return 0;
}
