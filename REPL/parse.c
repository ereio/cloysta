/*
 * References:
 * www.cplusplus.com/reference/cstring/strtok/
 *
 * */
#include "../global.h"
#include "parse.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

	margc = i;
	memcpy(args, new_args, sizeof(new_args));
	free(cur_arg);
}

void resolve_paths(char args[][ACOLS]) {

	char* BACK = "..";
	char* CURR = "./";
	char* tild = "~";

	int i;
	int hit;
	for(i = 0; i < margc; i++){
		if(strstr(args[i],BACK) != NULL){
			fillBack(args, i); hit++;
		}
		if(strstr(args[i],CURR) != NULL){
			fillCurr(args, i); hit++;
		}
		if(strstr(args[i], tild) != NULL){
			fillTild(args, i); hit++;
		}
		if(i == 0 && hit == 0){
			fillPwd(args);
		}
	}
}

void expand_variables(char args[][ACOLS]) {

}

void fillCurr(char args[][ACOLS], int n){
	char* totarg = malloc(255 * sizeof(char));
	char* cursec = malloc(255 * sizeof(char));

	cursec = strstr(args[n], "..");
}

void fillBack(char args[][ACOLS], int n){

	char* cursec = malloc(255 * sizeof(char));
	char* pwd = getenv("PWD");
	int pos = 0;

	cursec = strstr(args[n], "..");

	while(cursec != NULL){
		pos = cursec - args[n];
		cutpwd(pwd);
		sinsert(args[n],pwd,pos,2);
	}
}

void fillTild(char args[][ACOLS], int n){
	char* home = getenv("HOME");
	char* totarg = malloc(255 * sizeof(char));

	if(args[n][0] == '~'){
		strcat(totarg, home);
		strcat(totarg, args[n]+1);
	}

	strcpy(args[n], totarg);
}

void sinsert(char* main, char* ins, int s, int flamt){
	char* fullstr = malloc(510 * sizeof(char));
	int mlen = strlen(main);
	int ilen = strlen(ins);

	int i = 0;
	int prv = s;

	for(i=0; i < s; i++)
		fullstr[i] = main[i];

	for(int j=0; j < ilen; j++, i++)
		fullstr[i] = ins[j];

	if(fullstr[i] == '/' && ins[0] == '/') prv++;

	for(prv = s+flamt; i < mlen+ilen; i++, prv++)
		fullstr[i] = main[prv];

	strcpy(main, fullstr);
}

void cutpwd(char* pwd){
	char* last = strrchr(pwd, '/');
	int pos = last - pwd;

	pwd[pos+1] = '\0';
}

void fillPwd(char args[][ACOLS]){
	char* pwd = getenv("PWD");
	char* totcmd = malloc(255 * sizeof(char));

	strcat(totcmd, pwd);
	strcat(totcmd, args[0]);

	strcpy(args[0], totcmd);
}

