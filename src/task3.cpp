#include <stdio.h>
#include <stdlib.h>
#include "task3.h"
static int k = 0;

void create(PSYM buf, unsigned char ch, int count)
{
	int i = 0;
	if (buf[0].ch == '\0')
	{
		buf[0].ch = ch;
		buf[0].freq = ((float)1) / ((float)count);
		k++;
		return;
	}
	for (i; i < k; i++)
	{
		if (buf[i].ch == ch)
		{
			buf[i].freq = buf[i].freq + ((float)1) / ((float)count);
			return;
		}
	}
	buf[k].ch = ch;
	buf[k].freq = ((float)1) / ((float)count);
	k++;
}
	
void Sort(PSYM buf)
{
	qsort(buf, k, sizeof(TSYM), compar);
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

void print(PSYM buf)
{
	for (int i = 0; i < k; i++)
		printf("%c  %f\n", buf[i].ch, buf[i].freq);
}