#ifndef _PARSE
#define _PARSE

void _parse(char *input, char arguments[][ACOLS]);

void parse_whitespace(char *input);
void parse_arguments(char *input, char args[][ACOLS]);
void resolve_paths(char args[][ACOLS]);
void expand_variables(char args[][ACOLS], int n);

void fillBack(char args[][ACOLS], int n);
void fillCurr(char args[][ACOLS], int n);
void fillTild(char args[][ACOLS], int n);
void exebg(char args[][ACOLS], int n);
void fillPwd(char args[][ACOLS]);


void sinsert(char* main, char* ins, int s, int flamt);
void sremove(char* main, int s, int size);
void cutpwd(char* pwd);


#endif
