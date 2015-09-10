#include "prompt.h"
#include <stdlib.h>
#include <stdio.h>

int _Prompt(char** settings)
{
	char* prompt = getenv("USER");

	printf("%s > ", prompt);

	return 0;
}
