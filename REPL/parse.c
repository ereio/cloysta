/*
 * References:
 * www.cplusplus.com/reference/cstring/strtok/
 *
 * */
#include "parse.h"
#include "shared.h"
#include <stdio.h>
#include <string.h>

char** _Parse(char* input){

	char** args;

	input = parse_whitespace(input);
	args = parse_arguments(input);
	args = expand_variables(args);
	args = resolve_paths(args);

	return args;
}

char *parse_whitespace(char *input) {


	return input;
}

char **parse_arguments(char *input) {

	char* new_args[256];
	char* cur_arg;
	int i = 0;

	cur_arg = strtok(input, _DELIMS);
	while(cur_arg != NULL){
		new_args[i]= cur_arg;
		cur_arg = strtok(input, _DELIMS);
	}

	/* memcpy(new_args) */
	return new_args;
}

char **resolve_paths(char **args) {

	return args;
}

char **expand_variables(char **args) {

	return args;
}
