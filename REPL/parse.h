#ifndef _PARSE
#define _PARSE

void _parse(char *input, char** arguments);

void parse_whitespace(char *input);
void parse_arguments(char *input, char** args);
void resolve_paths(char **args);
void expand_variables(char **args);

#endif
