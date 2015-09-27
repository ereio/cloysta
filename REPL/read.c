#include "read.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _read(char* line)
{
	char* str = malloc(255 * sizeof(char*));

	fgets(str, 255, stdin);
	strcpy(line, str);

	if(str != NULL) free(str);

	return line == NULL ? 0 : 1;
}
