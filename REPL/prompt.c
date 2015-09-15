#include "prompt.h"
#include <stdlib.h>
#include <stdio.h>

int _prompt(char** settings)
{
	char* prompt = getenv("USER");

	printf("%s > ", prompt);

	return 0;
}
