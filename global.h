/* Global References for Command Strings, Deliminators, etc. */
#ifndef _SIZE_T
#include <stddef.h>
#include <stdio.h>
#endif

#include <sys/types.h>
/* Defines  */
#define MAX_HEAP_SIZE 255
#define MAX_ADDR_NAME 16
#define DEFAULT_ALLOC 255

/* Structures  */
struct address{
	int* loc;
	size_t type;
	char name[16];
};
extern pid_t bgproc;

/* Constants  */
extern const char* EXIT;
extern const char* ECHO;
extern const char* ETIME;
extern const char* LIMITS;
extern const char* CD;
extern const char* _DELIMS;
extern const char* PREV_DIR_I;
extern const char* PREV_DIR_II;
extern const char* _PIPES;
extern const char* EXPORT;

extern const char* ARGS;
extern const int ACOLS;
extern char* cuser;

/* Globals  */
extern struct address * ADDRS;

extern int margc;
extern int run;
extern int exec;
extern int runbg;
