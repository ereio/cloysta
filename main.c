#include <stdio.h>
#include "REPL/setup.h"
#include "REPL/prompt.h"
#include "REPL/parse.h"
#include "REPL/read.h"
#include "REPL/execute.h"
#include "UTILS/memmy.h"
#include "global.h"

/*  run/dumm... is an extern, it's a global and is not redefined but declared here */
const char* EXIT = "exit";
const char* ECHO = "echo";
const char* ETIME = "etime";
const char* LIMITS = "limits";
const char* CD = "cd";
const char* _DELIMS = " \n";
const char* _PIPES = "|<>";
const char* ARGS = "ARGS";

int run = 1;
int dummy_test = -5;

/* ALL EXITING TASKS DONE HERE */
int exit_shell(){

	return purge_memmy();
}


int main(int argc, char* args[])
{
	char *line;
	char cmd[255][255];

 	if(!init_memmy()) return 1;

	line = set_string(255);

	while(run)
	{
		 _setup();
		 _prompt();
		 if(_read(line)){
			 /* Transform input
				 Match against patterns */
			 _parse(line, &cmd);
			 _execute(cmd);
			  /* cleanup */
		 } else {
			 run = 0;
		 }
	}
	
	return exit_shell();
}



