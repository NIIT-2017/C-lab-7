#include<stdio.h>
#include<stdlib.h>
#include"task3.h"

void initialize(SYM* psimbol_fp)
{
	for (int i = 0; i < SIZE; i++)
	{
		(psimbol_fp + i)->code = i;
		(psimbol_fp + i)->occurrence = 0;
	}
}

int analysis_fp(SYM* psimbol_fp, FILE* fp)
{
	int count = 0;
	int count_n = 0; //for sum '\n' 
	char ch;

	while ((ch = getc(fp)) != EOF)
	{
		if (ch == '\n') //not to take '\n' into account
			count_n++;

		for (int i = 0; i < SIZE; i++)
		if (ch == (psimbol_fp + i)->code && ch != '\n')
		{
			(psimbol_fp + i)->occurrence++;
			continue;
		}
		count++;
	}

	return count-count_n;
}

void calculation_occurrence(SYM* psimbol_fp, int count_simbol)
{
	for (int i = 0; i < SIZE; i++)
		(psimbol_fp + i)->occurrence = (float)((psimbol_fp + i)->occurrence / count_simbol);
}

void sort(SYM* psimbol_fp)
{
	SYM buf;
	for (int i = 0; i < SIZE - 1; i++)
	for (int j = i + 1; j < SIZE; j++)
	if ((psimbol_fp + i)->occurrence < (psimbol_fp + j)->occurrence)
	{
		buf.occurrence = (psimbol_fp + i)->occurrence;
		buf.code = (psimbol_fp + i)->code;

		(psimbol_fp + i)->occurrence = (psimbol_fp + j)->occurrence;
		(psimbol_fp + i)->code = (psimbol_fp + j)->code;

		(psimbol_fp + j)->occurrence = buf.occurrence;
		(psimbol_fp + j)->code = buf.code;
	}
}
void print_simbols(SYM* psimbol_fp)
{
	for (int i = 0; i < SIZE; i++)
	{
		if ((psimbol_fp + i)->occurrence != 0)
			printf("\"%c\" - %.5f\n", (psimbol_fp + i)->code, (psimbol_fp + i)->occurrence);
	}
}