#ifndef REPL_REDIRECT_H_
#define REPL_REDIRECT_H_

int output_file(char args[][ACOLS]);
int input_file(char args[][ACOLS]);

int findPipe(char args[][ACOLS], int n);
int mpipe(char args[][ACOLS]);

#endif
