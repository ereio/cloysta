/* References:
 * Creating Pipes http://www.tldp.org/LDP/lpg/node11.html
 *
 *
 * */

#include "../global.h"
#include "redirect.h"
#include "execute.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <sys/wait.h>

int output_file(char args[][ACOLS]) {
	exec = 0; // Set the exec boolean so that execution doesn't occur twice
	char cmd[ACOLS][ACOLS];
	char file[255];

	for (int i = 0; i < margc && strcmp(args[i], ">") != 0; i++) {
		strcpy(cmd[i], args[i]);

		if (strcmp(args[i+1], ">") == 0)
			strcpy(file, args[i+2]);
	}

	margc = margc - 2;

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

	margc = margc - 2;

	FILE * fp = fopen(file, "r");

	if (fp != NULL) {
		char word[100];
		char c;

		do {
			c = fscanf(fp, "%s", word);

			if (c != EOF) {
				strcpy(cmd[margc], word);
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

int mpipe(char args[][ACOLS]){
		pid_t ipid =0;
		pid_t jpid =0;
		int fds[2], wbytes, rbytes;
		int* statusptr = NULL;
		char cmds[255][255];

		char mes[] = "12930938201928";
		char* readbuffer = malloc(510 * sizeof(char));
		exec = 0;

		/* Successful pipe and forking */
		if((ipid = fork()) == 0){

			if(pipe(fds) == -1){
				perror("Piping failed - exiting");
				run = 0;
				return EXIT_FAILURE;
			}
			if((jpid = fork()) == 0){
				//cmd1 (Writer) CHILD
				close(STDOUT_FILENO);
				dup(fds[1]);
				close(fds[0]);
				close(fds[1]);

				wbytes = write(fds[1], mes, (strlen(mes)+1));
			} else {
				//cmd2 (Reader) PARENT
				close(STDIN_FILENO);
				dup(fds[0]);
				close(fds[0]);
				close(fds[1]);

				rbytes = read(fds[0], readbuffer, sizeof(readbuffer));
				printf("\nTesting: %s\n", readbuffer);
			}

			exit(0);
		} else {
			close(fds[0]);
			close(fds[1]);
			waitpid(-1, statusptr, 0);
		}

		if(ipid == -1 || jpid == -1){
			perror("Forking failed - exiting");
			run = 0;
			return EXIT_FAILURE;
		}

		return EXIT_SUCCESS;
}


