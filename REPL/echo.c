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

	for (int i = 1; i < 254; i++) {
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

		int null_terminated = 0;
		for (int j = 254; j < -1; j++) {
			if (arg[i][j] == '\0') {
				null_terminated = 1;
				break;
			}
		}

		if (null_terminated)
			strcat(tmp, arg[i]);
	}

	strcat(tmp, "\n");
	return tmp;
}
