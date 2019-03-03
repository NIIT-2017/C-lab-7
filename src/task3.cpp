#include "task3.h"
#include <stdlib.h>


struct SYM** mkPsyms(FILE *fp, int *N)
{
	struct SYM* syms;
	struct SYM** psyms;
	int count = 0, i = 0, j = 0;
	int ch = 0;
	syms = (struct SYM*)calloc(SIZE, sizeof(struct SYM));
	for (i = 0; i < SIZE; i++)
	{
		syms[i].ch = i;
		syms[i].freq = 0;
		syms[i].code[0] = 0;
		syms[i].left = NULL;
		syms[i].right = NULL;
	}
	while ((ch = fgetc(fp)) != EOF)
	{
		count++;
		syms[ch].freq++;
	}
	for (i = 0; i < SIZE; i++)
	{
		if (syms[i].freq != 0)
		{
			(*N)++;
			syms[i].freq = syms[i].freq / count;
		}
	}
	psyms = (struct SYM**)calloc(sizeof(struct SYM*), *N);
	for (i = 0; i < SIZE; i++)
	{
		if (syms[i].freq != 0)
			psyms[j++] = syms + i;
	}

	sort(psyms, *N);
	return psyms;
}

void print(struct SYM** arr, int N)
{
	for (int i = 0; i < N; i++)
	{
		printf("%c - %f\n", arr[i]->ch, arr[i]->freq);
	}
}

void sort(struct SYM** arr, int N)
{
	struct SYM* temp;
	int i = 0, j = 0;
	for (i = 0; i < N; i++)
		for (j = N - 1; j > i; j--)
		{
			if (arr[i]->freq < arr[j]->freq)
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
}