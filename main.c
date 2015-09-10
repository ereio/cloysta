#include <stdio.h>
#include "REPL/setup.h"
#include "REPL/prompt.h"
#include "REPL/parse.h"
#include "REPL/read.h"
#include "REPL/execute.h"
#include "REPL/shared.h"

/*  run/dumm... is an extern, it's a global and is not redefined but declared here */
const char* EXIT = "exit";
const char* ECHO = "echo";
const char* ETIME = "etime";
const char* LIMITS = "limits";
const char* CD = "cd";
const char* _DELIMS = " ";
const char* _PIPES = "|<>";

int run = 1;
int dummy_test = -5;

int main(int argc, char* args[])
{
	char *line;
	char **cmd;

	while(run)
	{
		 _Setup();
		 _Prompt();
		 line = _Read();
	  /* Transform input
		 Match against patterns */
		 cmd = _Parse(line);
		 _Execute(cmd);
	  /* cleanup */
	}
	
	return 0;
}


