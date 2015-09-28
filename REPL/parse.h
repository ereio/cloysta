#ifndef _PARSE
#define _PARSE

void _parse(char *input, char arguments[][255]);

void parse_whitespace(char *input);
void parse_arguments(char *input, char args[][255]);
void resolve_paths(char args[][255]);
void expand_variables(char args[][255]);

void fillBack(char args[][ACOLS], int n);
void fillCurr(char args[][ACOLS], int n);
void fillTild(char args[][ACOLS], int n);
void fillPwd(char args[][ACOLS]);

void sinsert(char* main, char* ins, int s, int flamt);
void cutpwd(char* pwd);

#endif
