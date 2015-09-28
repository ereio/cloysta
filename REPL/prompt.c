#include "prompt.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/param.h>
#include "../global.h"

int _prompt(char** settings)
{
	char* machine = getenv("MACHINE");
	char buf[MAXPATHLEN];
	char* pwd = getcwd(buf, MAXPATHLEN);

	if(machine == NULL) {
		machine = malloc(128 * sizeof(char));
		strcpy(machine, "local\0");
	}

	printf("%s@%s: %s => ", cuser, machine, pwd);

	return 0;
}
