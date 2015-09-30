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
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

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

	int saved_stdout = dup(STDOUT_FILENO);
	int saved_stderr = dup(STDERR_FILENO);
	int out = open(file, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
	
	dup2(out, STDOUT_FILENO);
	dup2(out, STDERR_FILENO);
	close(out);

	_execute(cmd);

	dup2(saved_stdout, STDOUT_FILENO);
	dup2(saved_stderr, STDERR_FILENO);
	close(saved_stdout);
	close(saved_stderr);

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

	int saved_stdin = dup(STDIN_FILENO);
	int in = open(file, O_RDONLY);

	dup2(in, STDIN_FILENO);
	close(in);

	_execute(cmd);

	dup2(saved_stdin, STDIN_FILENO);
	close(saved_stdin);

	return 0;
}

int findPipe(char args[][ACOLS], int n){

	if(margc < 3){
		perror("Piping: Not enough arguments to pipe");
		exec = 0;
		return 1;
	}

	printf("\nWarning: Piping does not work correctly.\n");
	mpipe(args);
	exec = 0;
	return 0;
}

int mpipe(char args[][ACOLS]){
		pid_t ipid =0;
		pid_t jpid =0;
		int fds[2];
		int* statusptr = NULL;
//		char* c1args[1];
//		char* c2args[1];
//		char* tokI = NULL;
//		char* tokII = NULL;
//		char** potential = NULL;
//		char** potential2 = NULL;
		char* cmd1[2] = { "/bin/ls", NULL};
		char* cmd2[2] = { "/bin/more", NULL};

//		findexec(args, &potential);
//		strcpy(args[0], args[2]);
//		findexec(args, &potential2);
//
//		cmd1 = malloc(sizeof(char) * strlen(*potential) + 1);
//		cmd2 = malloc(sizeof(char) * strlen(*potential2) + 1);
//
//		tokI = strtok(potential, ":");
//
//		while(tokI != NULL){
//				if(!access(tokI, X_OK)) strcpy(cmd1, tokI);
//				tokI = strtok(NULL, ":");
//			}
//
//		tokII = strtok(potential2, ":");
//
//		while(tokII != NULL){
//				if(!access(tokII, X_OK)) strcpy(cmd2, tokII);
//				tokII = strtok(NULL, ":");
//			}
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

				execv("/bin/ls", cmd1);
			} else {
				//cmd2 (Reader) PARENT
				close(STDIN_FILENO);
				dup(fds[0]);
				close(fds[0]);
				close(fds[1]);

				execv("/bin/more", cmd2);
			}

			exit(0);
		} else {
			close(fds[0]);
			close(fds[1]);
			waitpid(-1, statusptr, 0);
		}
//
//		free(potential);
//		free(potential2);

		if(ipid == -1 || jpid == -1){
			perror("Forking failed - exiting");
			run = 0;
			return EXIT_FAILURE;
		}

		return EXIT_SUCCESS;
}


