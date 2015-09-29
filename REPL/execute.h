#ifndef _EXECUTE
#define _EXECUTE

int _execute(char args[][ACOLS]);
int chgdir(char args[][ACOLS]);
int etime(char args[][ACOLS]);
int compute_limits(char args[][ACOLS]);

int expenv(char args[][ACOLS]);
int findexec(char args[][ACOLS],  char** pathops);
int otroexec(char args[][ACOLS],  char** pathops);

#endif
