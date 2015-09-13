#ifndef _MEMMY
#define _MEMMY

int get_array_size(char *);

int set_array_size(char **);

char* set_memmy(int size);

char** set_demmy(int rows, int cols);

char* get_memmy(char* address);

char** get_demmy(char** address);

char* free_memmy(char* address);

char** free_demmy(char** address);

#endif
