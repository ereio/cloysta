#include "prompt.h"
#include <stdlib.h>
#include <stdio.h>

int _prompt(char** settings)
{
	char* user = getenv("USER");
	char* machine = getenv("MACHINE");
	char* pwd = getenv("PWD");

	printf("%s@%s: %s => ", user, machine, pwd);

	return 0;
}
