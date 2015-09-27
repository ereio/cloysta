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

void _parse(char* input, char args[][ACOLS]){

	parse_whitespace(input);
	parse_arguments(input, args);
	expand_variables(args);
	resolve_paths(args);
}

void parse_whitespace(char* input) {


}

void parse_arguments(char* input, char args[][ACOLS]) {

	char new_args[255][255];
	char* cur_arg = malloc(255 * sizeof(char*));
	int i = 0;

	memcpy(new_args, args, sizeof(new_args));

	cur_arg = strtok(input, _DELIMS);

	while(cur_arg != NULL && i < 255){
		strcpy(new_args[i], cur_arg);
		cur_arg = strtok(NULL, _DELIMS);
		i++;
	}

	memcpy(args, new_args, sizeof(new_args));
	free(cur_arg);
}

void resolve_paths(char args[][ACOLS]) {

}

void expand_variables(char args[][ACOLS]) {

}
