#include "read.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _read(char* line)
{
	char* str = malloc(255 * sizeof(char*));

	if(scanf("%s", str)){
		strcpy(line, str);
		free(str);
		return 1;
	}
	free(str);
	return 0;
}
