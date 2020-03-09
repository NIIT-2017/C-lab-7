#include "task3.h";
#include <stdio.h>;
#include <stdlib.h>;
#include <string.h>;


int cmp(const void* a, const void* b) // функция компаратора
{
	return int(((struct SYM*)a)->freq*100) - int(((struct SYM*)b)->freq*100);
}
void print(struct SYM* syms)
{
	for (int i = 0; i < 256; i++)
	{
		if (syms[i].ch!=0)
			printf("%c - %f\n", syms[i].ch, syms[i].freq);
	}
}