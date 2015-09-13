#ifndef _MEMMY
#define _MEMMY


struct address* ADDRS = NULL;

int init_memmy();
int purge_memmy();

void* fetch_heap(const char* name);
int free_heap(const char* name);
int resize_heap(struct address * addr, size_t size);

char* set_string(int size);
char** set_array(int rows, int cols);

void* set_array(char* name,  size_t type);
void* set_array(char* name, int rows, size_t type);
void* set_array(char* name, int rows, int cols, size_t type);

void* set_heap(size_t type);
void* set_heap(size_t size, size_t type);
void* set_heap(int rows, int cols, size_t type);

void* set_file(char* name, size_t size, size_t type);

#endif
