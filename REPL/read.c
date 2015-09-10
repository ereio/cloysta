#include "read.h"
#include <stdio.h>

char* _Read()
{
	char str[256];

	if(scanf("%s"), str){
		return str;
	}

	return 0;
}
