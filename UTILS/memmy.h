#ifndef _MEMMY
#define _MEMMY

int init_memmy();
int purge_memmy();

void* fetch_heap(const char* name);
int free_heap(const char* name);
int resize_heap(struct address * addr, size_t size);

char* set_string(int size);
char* set_stringn(const char* name, int size);

char** set_array(int rows, int cols);
void* set_arrayn(char* name,  size_t type);
void* set_arraynr(char* name, int rows, size_t type);
void* set_arraynrc(char* name, int rows, int cols, size_t type);

void* set_heapt(size_t type);
void* set_heapst(size_t size, size_t type);
void* set_heaprct(int rows, int cols, size_t type);

void* set_file(char* name, size_t size, size_t type);

#endif
