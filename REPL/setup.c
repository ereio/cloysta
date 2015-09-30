#include "../global.h"
#include "setup.h"
#include <string.h>

int _setup(char cmd[ACOLS][ACOLS])
{
	for(int i=0; i < ACOLS; i++)
		strcpy(cmd[i], "\0");

	margc = 0;
	runbg = 0;
	exec = 1;
	return 0;
}
