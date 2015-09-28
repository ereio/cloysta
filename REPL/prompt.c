#include "prompt.h"
#include <stdlib.h>
#include <stdio.h>

int _prompt(char** settings)
{
	char* user = getenv("USERNAME");
	char* machine = getenv("COMPUTERNAME");
	char* pwd = getenv("CD");
	if (pwd == NULL)
		pwd = "Local";

	printf("%s@%s: %s => ", user, machine, pwd);

	return 0;
}
