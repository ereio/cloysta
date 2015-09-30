/*
 * http://unix.stackexchange.com/questions/139222/why-is-the-pgid-of-my-child-processes-not-the-pid-of-the-parent
 * http://linux.die.net/man/2/waitpid
 *
 * */
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/wait.h>
#include "../global.h"
#include "echo.h"
#include "execute.h"

int _execute(char args[][ACOLS])
{
	char* cfgpath = NULL;

	if(!strcmp(EXIT, args[0]))
		run = 0;
	else if(!strcmp(EXPORT, args[0]))
		expenv(args);
	else if(!strcmp(ECHO, args[0]))
		echo_text(args);
	else if(!strcmp(ETIME, args[0]))
		etime(args);
	else if(!strcmp(LIMITS, args[0]))
		compute_limits(args);
	else if(!strcmp(CD, args[0]))
		chgdir(args);
	else if(!findexec(args, &cfgpath))
		otroexec(args, &cfgpath);

	if(cfgpath != NULL) free(cfgpath);

	return 0;
}
int expenv(char args[][ACOLS]){
	// TODO - ERROR CHECKING
	putenv(args[1]);
	return 0;
}

int chgdir(char args[][ACOLS]){

	char path[510];

	if (margc > 2) {
		printf("Error: too many arguments\n");
	}
	else if (margc == 0) {
		chdir(getenv("HOME"));

		strcat(path, "PWD=");
		strcat(path, getenv("HOME"));
		putenv(path);
	}
	else {
		struct stat statbuf;
		stat(args[1], &statbuf);

		if (S_ISDIR(statbuf.st_mode)) {
			chdir(args[1]);

			strcat(path, "PWD=");
			strcat(path, args[1]);
			putenv(path);
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
	char nested_args[255][ACOLS];
	margc--;

	for (int i = 0; i < margc; i++) {
		strcpy(nested_args[i], args[i+1]);
	}

	pid_t childpid = fork();
	char print_buf[400];

	if (childpid == 0) {
		pid_t pid = getpid();

		char proc[50];
		sprintf(proc, "/proc/%ld/limits", (long)pid);

		FILE * limits = fopen(proc, "r");

		if (limits != NULL) {
			char line[255];
			while (fgets(line, 255, limits) != NULL) {
				if (strstr(line, "Max file size"))
					sprintf(print_buf, "%s", line);
				else if (strstr(line, "Max open files"))
					sprintf(print_buf + strlen(print_buf), "%s", line);
				else if (strstr(line, "Max processes"))
					sprintf(print_buf + strlen(print_buf), "%s", line);
				else if (strstr(line, "Max pending signals"))
					sprintf(print_buf + strlen(print_buf), "%s", line);
			}
		}

		fclose(limits);
		_execute(nested_args);
		printf("%s", print_buf);
		exit(0);
	}

	return 0;
}

int findexec(char args[][ACOLS], char** pathops){
	char* pathenv = getenv("PATH");
	char* path = malloc(sizeof(char) * strlen(pathenv) + 1);
	char *token;

	int i = 0;
	int test = sizeof(char) * strlen(pathenv) * 255;
	*pathops = malloc(test);
	strcpy(*pathops, "\0");
	strcpy(path, pathenv);
	token = strtok(path, ":");

	while(token != NULL){
		char temp[255] = "\0";
		strcpy(temp, token);
		strcat(temp, "/");
		strcat(temp, args[0]);
		strcat(temp, "\0");
		strcat(temp, ":");
		strcat(*pathops, temp);
		token = strtok(NULL, ":");
		i++;
	}

	free(path);
	return 0;
}

int otroexec(char args[][ACOLS], char** pathops){
		pid_t pid;
		pid_t fpid; // finished pid
		int status = NULL;
		int i =0;
		char* cnfpath = malloc(sizeof(char) * strlen(*pathops) + 1);
		char* eargs[margc];
		char* token;
		char path[255];

		strcpy(cnfpath, *pathops);

		for(i=0; i < margc; i++){
			eargs[i] = malloc(sizeof(char) * ACOLS);
			strcpy(eargs[i], args[i]);
			if(i == margc-1) eargs[i+1] = (char*)0;
		}

		token = strtok(cnfpath, ":");

		while(token != NULL){
			if(!access(token, X_OK)) strcpy(path, token);
			token = strtok(NULL, ":");
		}

		if ((bgproc = fork()) == -1){
			perror("warning: Fork Error");
		} else if (bgproc == 0) {
			if (runbg) {
				setpgid(0, 0);
				execv(path, eargs);
			} else {
				execv(path, eargs);
				exit(1);
			}
		} else if(!runbg){
			fpid = waitpid(bgproc, &status, 0);
		} else {
			printf("[%d]\t\t[%d]\n", 1, bgproc);
		}

		/* Check to see if process is finished running
		 * Collects all that may be exitting */
		fpid = waitpid(-1, &status, WNOHANG);

		while(fpid != 0 && fpid != -1){
			if(fpid > 0){
				printf("Process %d finished \n", fpid);
			}
			if(fpid < 0){
				printf("Process %d finished with error \n", fpid);
			}
			fpid = waitpid(-1, &status, WNOHANG);
		}

		free(cnfpath);
		return 0;
}

