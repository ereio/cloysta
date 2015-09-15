#ifndef _PARSE
#define _PARSE

char **_parse(char *input);
char  *parse_whitespace(char *input);
char **parse_arguments(char *input);
char **resolve_paths(char **args);
char **expand_variables(char **args);

#endif
