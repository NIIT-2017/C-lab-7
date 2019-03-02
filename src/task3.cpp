#include "task3.h"
#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


SYM * MakingTableOfFrequencies(SYM * syms, const char * fileName, int * pcountUniqSymb)
{
	FILE * fp = fopen(fileName, "rb");				//checking file for reading
	if (!fp)
	{
		puts("Cannot read original file");
		exit(-1);
	}

	int freq[256] = { 0 };							//creating array for frequencies of symbols
	int totalNumberOfSymb = 0;						//total number of symbols in the document for counting frequencies
	int chTemp = 0;
	while ((chTemp = fgetc(fp)) != EOF)//forming array with frequencies, where index is a ASCII code of the element
	{
		for (int i = 0; i < SIZE1; i++)
			if (chTemp == i)
			{
				freq[i] += 1;
				totalNumberOfSymb++;
				break;
			}
	}

	for (int i = 0; i < SIZE1; i++)//counting unique symbols
	{
		if (0 != freq[i])
			*pcountUniqSymb += 1;
	}

	for (int i = 0, j = 0; i < SIZE1; i++, j++)//counting frequencies and forming array of structures
	{
		if (freq[i])
		{
			syms[j].freq = (float)freq[i]; // totalNumberOfSymb;
			syms[j].ch = i;
		}
		else
			j--;
	}
	fclose(fp);//closing initial file
	return syms;
}

SYM * SortingArrByFrequencies(SYM * syms, int countUniqSymb)
{
	SYM tempSym;									//sorting the array from more to less
	for (int i = 0; i < countUniqSymb; i++)
	{
		for (int j = 0; j < countUniqSymb - 1; j++)
		{
			if (syms[j].freq < syms[j + 1].freq)
			{
				tempSym = syms[j];
				syms[j] = syms[j + 1];
				syms[j + 1] = tempSym;
			}
		}
	}
	return syms;
}

void PrintSym(SYM a)
{
	printf("%c - symbol, %d - by ASCII, %f - frequency\n", a.ch, a.ch, a.freq);
}

void PrintTableWithFrequencies(SYM * syms, int countUniqSymb)
{
	for (int i = 0; i < countUniqSymb; i++)//printing the table
	{
		PrintSym(syms[i]);
	}
}