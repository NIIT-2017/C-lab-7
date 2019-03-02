#include "task3.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(int argc, const char * argv[]) {
	if (argc < 2)
	{
		puts("Wrong format");
		return -7;
	}

	SYM syms[SIZE1] = { 0 };		//creating array of structures
	int countUniqSymb = 0;			//total number of unique symbols in the document 

	MakingTableOfFrequencies(syms, argv[1], &countUniqSymb);
	SortingArrByFrequencies(syms, countUniqSymb);
	PrintTableWithFrequencies(syms, countUniqSymb);
	return 0;
}