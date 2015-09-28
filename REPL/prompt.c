#include "prompt.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../global.h"

int _prompt(char** settings)
{
	char* machine = getenv("MACHINE");
	char* pwd = getenv("PWD");

	if(machine == NULL) {
		machine = malloc(128 * sizeof(char));
		strcpy(machine, "local\0");
	}

	printf("%s@%s: %s => ", cuser, machine, pwd);

	return 0;
}
