#include "prompt.h"
#include <stdlib.h>
#include <stdio.h>
#include "../global.h"

int _prompt(char** settings)
{
	char* dir = getenv("PWD");

	printf("\n%s %s > ", cuser, dir);

	return 0;
}
