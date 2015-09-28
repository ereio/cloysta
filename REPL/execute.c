#include "../global.h"
#include "execute.h"
#include "echo.h"
#include <string.h>
#include <stdio.h>


int _execute(char args[][ACOLS])
{
	/* const char* command = args[0]; */

	if(!strcmp(EXIT, args[0]))
		run = 0;
	else if(!strcmp(ECHO, args[0]))
		echo_text(args);
	else if(!strcmp(ETIME, args[0]))
		dummy_test = 2;
	else if(!strcmp(LIMITS, args[0]))
		dummy_test = 3;
	else if(!strcmp(CD, args[0]))
		chgdir(args);

	/* External, parse for command in path */

	/* run_external(input); */

	printf(" %d\n", dummy_test);

	return 0;
}

int chgdir(char args[][ACOLS]){



	return 0;
}
