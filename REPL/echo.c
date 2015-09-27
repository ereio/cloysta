#include "echo.h"

void echo_text(char* arg) {
	printf("%s", verify_text(arg));
}

char* verify_text(char* arg) {
	char * s = strtok(arg, _DELIMS);
	char * tmp[255];

	while (s != NULL) {
		if (s[0] == '$') {
			s++;
			char * path = getenv(s);

			if (path != NULL)
				s = path;
			else
				return "Error: environment variable not found\n";
		}

		strcat(tmp, s);
		s = strtok(NULL, _DELIMS);
	}

	return s;
}
