#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "../global.h"
#include "echo.h"
#include "execute.h"

int _execute(char args[][ACOLS])
{
	if(!strcmp(EXIT, args[0]))
		run = 0;
	else if(!strcmp(ECHO, args[0]))
		echo_text(args);
	else if(!strcmp(ETIME, args[0]))
		etime(args);
	else if(!strcmp(LIMITS, args[0]))
		compute_limits(args);
	else if(!strcmp(CD, args[0]))
		chgdir(args);

	/* External, parse for command in path */

	/* run_external(input); */

	return 0;
}

int chgdir(char args[][ACOLS]){
	if (margc > 2) {
		printf("Error: too many arguments\n");
	}
	else if (margc == 0) {
		chdir(getenv("HOME"));
	}
	else {
		struct stat statbuf;
		stat(args[1], &statbuf);

		if (S_ISDIR(statbuf.st_mode)) {
			chdir(args[1]);
		}
		else {
			printf("Error: invalid directory\n");
		}
	}

	return 0;
}

int etime(char args[][ACOLS]) {
	char nested_args[255][ACOLS];
	struct timeval start, end;
	margc--;

	for (int i = 0; i < ACOLS - 1; i++) {
		strcpy(nested_args[i], args[i+1]);
	}

	gettimeofday(&start, NULL);
	_execute(nested_args);
	gettimeofday(&end, NULL);

	float elapsed_time = ((end.tv_sec + (end.tv_usec / 1000000.0)) -
			(start.tv_sec + (start.tv_usec / 1000000.0)));

	printf("Elapsed Time: %.6fs\n", elapsed_time);
	return 0;
}

int compute_limits(char args[][ACOLS]) {
	pid_t pid = getpid();
	char nested_args[255][ACOLS];
	margc--;

	for (int i = 0; i < ACOLS - 1; i++) {
		strcpy(nested_args[i], args[i+1]);
	}

	_execute(nested_args);

	char proc[50];
	sprintf(proc, "/proc/%ld/limits/", (long)pid);

	printf("%s\n", proc);

	FILE * limits = fopen(proc, "r");

	if (limits != NULL) {
		char line[255];

		while (fgets(line, 255, limits) != NULL) {
			printf("%s", line);
			if (strstr(line, "Max file size"))
				printf("%s", line);
			else if (strstr(line, "Max open files"))
				printf("%s", line);
			else if (strstr(line, "Max processes"))
				printf("%s", line);
			else if (strstr(line, "Max pending signals"))
				printf("%s", line);
		}

		fclose(limits);
	}
	return 0;
}
