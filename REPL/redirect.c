#include "../global.h"
#include "redirect.h"
#include "execute.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int output_file(char args[][ACOLS]) {
	exec = 0; // Set the exec boolean so that execution doesn't occur twice
	char cmd[ACOLS][ACOLS];
	char file[255];

	for (int i = 0; i < margc && strcmp(args[i], ">") != 0; i++) {
		strcpy(cmd[i], args[i]);

		if (strcmp(args[i+1], ">") == 0)
			strcpy(file, args[i+2]);
	}

	FILE * fp = freopen(file, "a", stdout);

	if (fp != NULL)
		_execute(cmd);
	else
		printf("Error: invalid redirect\n");

	fclose(fp);

	freopen("/dev/tty", "a", stdout);

	return 0;
}

int input_file(char args[][ACOLS]) {
	exec = 0;
	char cmd[ACOLS][ACOLS];
	char file[255];

	for (int i = 0; i < margc && strcmp(args[i], "<") != 0; i++) {
		strcpy(cmd[i], args[i]);

		if (strcmp(args[i+1], "<") == 0)
			strcpy(file, args[i+2]);
	}

	FILE * fp = fopen(file, "r");

	if (fp != NULL) {
		char word[100];
		char c;

		do {
			c = fscanf(fp, "%s", word);

			if (c != EOF) {
				strcpy(cmd[margc - 2], word);
				margc++;
			}
		} while (c != EOF);

		_execute(cmd);
	}
	else {
		printf("Error: invalid redirect\n");
	}

	fclose(fp);

	return 0;
}

int mpipe(){
		pid_t pid;

		int fds[2];

		if(pipe(fds) == -1){
			perror("Piping failed - exiting");
			run = 0;
			return EXIT_FAILURE;
		}

		if((pid = fork()) == -1){
			perror("Forking failed - exiting");
			run = 0;
			return EXIT_FAILURE;
		}

		/* Successful pipe and forking */

		if((pid = fork()) == 0){
			//cmd1 (Writer)
			close(STDOUT_FILENO);
			dup(fds[1]);
			close(fds[0]);
			close(fds[1]);
			// Execute Command

		} else {
			//cmd2 (Reader)
			close(STDIN_FILENO);
			dup(fds[0]);
			close(fds[0]);
			close(fds[1]);

		}

		return EXIT_SUCCESS;
}

