#include "../global.h"
#include "echo.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void echo_text(char arg[][ACOLS]) {
	printf("%s", verify_text(arg));
	fflush(stdout);
}

char* verify_text(char arg[][ACOLS]) {
	char * tmp = malloc(sizeof(char) * 255);
	*tmp = '\0';

	for (int i = 1; i < margc - 1; i++) {
		if (arg[i][0] == '$') {
			char s[ACOLS];
			strcpy(s, arg[i]+1);

			char path[ACOLS];
			strcpy(path, getenv(s));

			if (path != NULL)
				strcpy(arg[i], path);
			else
				return "Error: environment variable not found\n";
		}

		strcat(tmp, arg[i]);
		strcat(tmp, " ");
	}

	strcat(tmp, "\n");
	return tmp;
}
