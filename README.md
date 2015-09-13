/**    Cloysta - A Simple Shell for Linux        **/

This shell is intended for submittion for Florida State's Operating Systems course Fall 2015


Working References:

Globals: http://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files-in-c


Old Ideas on memory management:

void* set_memmy(int size, size_t type){

	int index = set_heap();
	if(index == NULL) return NULL;

	ADDRS[index]->loc = calloc(size, type);
	return *CHAR_ADDRS[index];
}

Instead of handling the heap internally, barring the heap from everyone, we could let each other have more direct control. However, choosing to hide the heap locations and manage internally allows for more control over garbage control. Memory leaks can at least be purged if we store an address to every allocation made. Thus, the struct of "address" allows for a total control.

/* Set Heap Based on specific size
 * Allocates memory based on a specified size passed in
 * */
void* set_array(char* name, int rows, int cols, size_t type){

	int i = 0;
	for(i = 0; i < MAX_HEAP_SIZE; i++){
		if(ADDRS[i]->loc == NULL){
			strcpy(ADDRS[i]->name, name);
			ADDRS[i]->type = type;
			ADDRS[i]->loc = malloc(rows * cols * type);
			return ADDRS[i]->loc;
		}
	}
	return NULL;
}

Just the first iteration before implmenting an _next_addr()

/* Set Heap Based on specific size
 * Allocates memory based on a specified size passed in
 * */
void* set_heap(size_t size, size_t type){

	struct address * addr = _next_addr();

	if(addr == NULL) return NULL;

	strcpy(addr->name, "Default");
	addr->type = type;
	addr->loc = malloc(size * type);

	return addr->loc;
}

Just the first iteration before implmenting an _init
