#include <stdio.h>
#include <string.h>
#include "task3.h"

int counter = 0;

void SortingByFreqs(SYM *SYMarray)
{
	unsigned char tempCh;
	float tempFreq;
	for (int i = 0; i < counter; i++)
	{
		for (int j = 0; j < counter; j++)
		{
			if (SYMarray[j].freq < SYMarray[i].freq)
			{
				tempCh = SYMarray[j].ch;
				tempFreq = SYMarray[j].freq;
				SYMarray[j].ch = SYMarray[i].ch;
				SYMarray[j].freq = SYMarray[i].freq;
				SYMarray[i].ch = tempCh;
				SYMarray[i].freq = tempFreq;
			}
		}
	}
}

void FillingSYMarray(SYM *SYMarray, float *frequenciesArray)
{
	char code[256] = { 0 };
	for (int i = 0; i < MAX_SYM_COUNT; i++)
	{
		if (frequenciesArray[i] > 0)
		{
			SYMarray[counter].ch = i;
			SYMarray[counter].freq = frequenciesArray[i];
			SYMarray[counter].left = 0;
			SYMarray[counter].right = 0;
			strcpy(SYMarray[counter].code, code);			//"временное" решение
			counter++;
		}
	}
	SortingByFreqs(SYMarray);
}

void PrintSYMarray(SYM *SYMarray)
{
	for (int i = 0; i < counter; i++)
		printf("char: %c\tfreq: %.4f\n", SYMarray[i].ch, SYMarray[i].freq);
}

int getSymbolsCount(FILE *book)		//подсчет кол-ва символов в файле
{
	fseek(book, 0, SEEK_END);
	int counter = ftell(book);
	fseek(book, 0, SEEK_SET);
	return counter + 1;
}

int MakeFreqsArray(FILE *book, float *freqs)		//заполнение массива частот встречаемости
{
	int SymbolsCount = getSymbolsCount(book), SYMcount = 0;
	while (!feof(book))
		freqs[(unsigned char)fgetc(book)]++;
	float sum = 0;
	for (int i = 0; i < MAX_SYM_COUNT; i++)
	{
		freqs[i] /= SymbolsCount;
		sum += freqs[i];
		if (freqs[i] != 0)
			SYMcount++;
	}
	return SYMcount;
}