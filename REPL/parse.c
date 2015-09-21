/*
 * References:
 * www.cplusplus.com/reference/cstring/strtok/
 *
 * */
#include "parse.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../global.h"

void _parse(char* input, char** args){

	parse_whitespace(input);
	parse_arguments(input, args);
	expand_variables(args);
	resolve_paths(args);
}

void parse_whitespace(char* input) {


}

void parse_arguments(char* input, char** args) {

	char** new_args = calloc(255, 255 * sizeof(char*));
	char* cur_arg = malloc(255 * sizeof(char*));
	int i = 0;

	cur_arg = strtok(input, _DELIMS);

	while(cur_arg != NULL && i < 255){
		strcpy(new_args[i], cur_arg);
		cur_arg = strtok(input, _DELIMS);
		i++;
	}

	free(new_args);
	free(cur_arg);
}

void resolve_paths(char** args) {

}

void expand_variables(char** args) {

}
