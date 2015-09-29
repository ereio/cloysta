#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "REPL/setup.h"
#include "REPL/prompt.h"
#include "REPL/parse.h"
#include "REPL/read.h"
#include "REPL/execute.h"
#include "UTILS/memmy.h"

/* Global const defines */
const char* EXIT = "exit";
const char* ECHO = "echo";
const char* ETIME = "etime";
const char* LIMITS = "limits";
const char* EXPORT = "export";
const char* CD = "cd";
const char* _DELIMS = " \n";
const char* _PIPES = "|<>";
const char* PREV_DIR_I = "..";
const char* PREV_DIR_II = "./";
const char* ARGS = "ARGS";
const int ACOLS = 255;

/* Globals */
char* cuser;
int margc = 1;
int run = 1;
int exec = 1;
int runbg = 0;

/* ALL EXITING TASKS DONE HERE */
int exit_shell(){

	return purge_memmy();
}


int main(int argc, char* args[])
{
	char *line;
	char cmd[255][255];


 	if(!init_memmy()) return 1;	/* Address Mem intialization*/

 	cuser = set_string(255);	/* User handle */
 	cuser = getenv("USER");

	line = set_string(255);		/* current command line init */

	while(run)
	{
		exec = 1;
		 _setup();
		 _prompt();
		 if(_read(line)){
			 /* Transform input
				 Match against patterns */
			_parse(line, cmd);
			if (exec) _execute(cmd);
			  /* cleanup */
		 } else {
			 run = 0;
		 }
	}
	
	return exit_shell();
}



