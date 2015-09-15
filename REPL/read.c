#include "read.h"
#include <stdio.h>

char* _read()
{
	char str[256];

	if(scanf("%s"), str){
		return str;
	}

	return 0;
}
