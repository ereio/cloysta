/* Global References for Command Strings, Deliminators, etc. */


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


/* Constants  */
extern const char* EXIT;
extern const char* ECHO;
extern const char* ETIME;
extern const char* LIMITS;
extern const char* CD;
extern const char* _DELIMS;
extern const char* _PIPES;

extern const char* ARGS;

/* Globals  */
extern struct address * ADDRS;

extern int dummy_test;
extern int run;

