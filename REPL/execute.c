#include "execute.h"
#include <string.h>
#include <stdio.h>
#include "../global.h"

int _execute(char** args)
{
	/* const char* command = args[0]; */

	if(!strcmp(EXIT, args[0]))
		run = 0;
	else if(!strcmp(ECHO, args[0]))
		dummy_test = 1;
	else if(!strcmp(ETIME, args[0]))
		dummy_test = 2;
	else if(!strcmp(LIMITS, args[0]))
		dummy_test = 3;
	else if(!strcmp(CD, args[0]))
		dummy_test = 4;

	/* External, parse for command in path */

	/* run_external(input); */

	printf(" %d\n", dummy_test);

	return 0;
}
