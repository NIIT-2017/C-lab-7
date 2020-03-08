#include "task3.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
	return int(((struct SYM*)b)->freq * 100) - int(((struct SYM*)a)->freq * 100);
}

char* chomp(char* str)
{
	if (str[strlen(str) - 1] == '\n')
		str[strlen(str) - 1] = '\0';
	return str;
}