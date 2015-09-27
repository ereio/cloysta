#include "prompt.h"
#include <stdlib.h>
#include <stdio.h>
#include "../global.h"

int _prompt(char** settings)
{

	char* machine = getenv("MACHINE");
	char* pwd = getenv("PWD");

	printf("%s@%s: %s => ", cuser, machine, pwd);

	return 0;
}
