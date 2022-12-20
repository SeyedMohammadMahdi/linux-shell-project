#include "readline.h"
#include <stdio.h>
#include "parser.h"
#include "currentpath.h"
int main()
{
	char str[1000];
	/*inputReader(str);
	char *params[1000];
	int length = parser(str, params);
	printf("%s\n%d", params[0], length);*/
	currentPath(str);
	printf("%s", str);
	return 0;
}
