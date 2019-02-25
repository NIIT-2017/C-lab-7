#include <stdio.h>
#include "task3.h"

/*
struct SYM // представление символа
{
	unsigned char ch; // ASCII-код
	float freq; // частота встречаемости
	char code[256]; // массив для нового кода
	struct SYM *left; // левый потомок в дереве
	struct SYM *right; // правый потомок в дереве
};
*/

void makeSymArray(struct SYM *buf, char letter)
{
	buf[letter].freq++;
}

void initializeArray(struct SYM* buf)
{
	for (int i = 0; i < 256; i++)
	{
		buf[i].ch = (unsigned char)i;
		buf[i].freq = 0;
		buf[i].code[0] = '\0';
		buf[i].left = 0;
		buf[i].right = 0;
	}
}

void calculateFreq(struct SYM*buf, int count)
{
	for (int i = 0; i < 256; i++)
	{
		buf[i].freq = buf[i].freq / (float)count;
	}
}

int comp(const void * x1, const void * x2)		
{
	return (((struct SYM*)(x2))->freq - ((struct SYM*)(x1))->freq);
}

void printArray(struct SYM* buf)
{
	float totalFreq = 0.0;
	for (int i = 0; i < 256; i++)
	{
		if (buf[i].freq == 0.0)
			break;
		else
		{
			printf("Symbol - %c\tFrequency - %f\n", buf[i].ch, buf[i].freq);
			totalFreq = totalFreq + buf[i].freq;
		}
		
	}
	printf("Total frequency = %f\n", totalFreq);
}