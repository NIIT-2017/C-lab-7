#include "task3.h"
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int countUniqSymb = 0;//total number of unique symbols in the document 

SYM * MakingTableOfFrequencies(SYM * syms, const char * fileName)
{
	FILE * fp = fopen(fileName, "r");
	if (!fp)
	{
		puts("Error reading file");
		exit(-1);
	}
	int freq[256] = { 0 };		//creating array for frequencies of symbols
	int totalNumberOfSymb = 0;	//total number of symbols in the document for counting frequencies
	char chTemp = 0;
	while ((chTemp = (char)fgetc(fp)) != -1)
	{
		for (int i = 0; i < 256; i++)
		{
			if (chTemp == syms[i].ch)// if this symbol is in our array
			{
				freq[i]++;//increasing it's frequency
				totalNumberOfSymb++;//increasing total amount of symbols
				break;//exit because each symbol is in one exemplar int the array
			}
			if (syms[i].ch == 0)//finding structure with free symbol field
			{
				syms[i].ch = chTemp;//giving the meaning of symbol to this symbol field
				freq[i] = 1;//increasing it's freaquency by one
				totalNumberOfSymb++;//increasing total amount of symbols
				countUniqSymb++;//increasing total amount of uniq symbols
				break;//exit because each symbol is in one exemplar int the array
			}
		}//from for
	}//from while

	for (int i = 0; i < countUniqSymb; i++)//counting frequencies
		syms[i].freq = (float)freq[i]/ totalNumberOfSymb;
	fclose(fp);
	return syms;
}

SYM * SortingArrByFrequencies (SYM * syms)
{
	SYM tempSym;//sorting an array from less to more
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

void PrintTableWithFrequencies(SYM * syms)
{
	for (int i = 0; i < countUniqSymb; i++)//printing the table
	{
		PrintSym(syms[i]);
	}
}