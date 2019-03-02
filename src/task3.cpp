#include "task3.h"
#include <stdio.h>
#include <stdlib.h>

static int index = 0;

void createStruct(PSYM syms, unsigned char ch, int count, int * uniqueCount)
{
	int in = 0;
	if (index == 0)
	{
		syms[index].ch = ch;
		syms[index].freq = syms[index].freq + ((float)1) / ((float)count);
		(*uniqueCount)++;
		index++;
		return;
	}

	for (int i = 0;i < index;i++)
	{
		if (syms[i].ch == ch)
			in++;
	}

	for (int i = 0;i < index;i++)
	{
		if (syms[i].ch != ch && in != 1)
		{
			syms[index].ch = ch;
			syms[index].freq = syms[index].freq + ((float)1) / ((float)count);
			index++;
			(*uniqueCount)++;
			break;
		}
		else if (syms[i].ch == ch && in == 1)
		{
			syms[i].freq = syms[i].freq + ((float)1) / ((float)count);
		}
	}
}


static int compar(const void* p1, const void* p2)
{
	if (((PSYM)p2)->freq > ((PSYM)p1)->freq)
		return 1;
	if (((PSYM)p2)->freq < ((PSYM)p1)->freq)
		return -1;
	if (((PSYM)p2)->freq == ((PSYM)p1)->freq)
		return 0;
}

void sortStruct(PSYM syms, int size)
{
	qsort(syms, size, sizeof(SYM), compar);
}


void printStruct(PSYM syms, int uniqueCount)
{
	float maxFreq = 0.0;
	
	printf("Symbol\tfrequency\n");

	for (int i = 0;i < uniqueCount;i++)
	{
		printf("%c\t%f\n", syms[i].ch, syms[i].freq);
		maxFreq = maxFreq + syms[i].freq;
	}
	
	printf("Total frequency %f\n", maxFreq);
}