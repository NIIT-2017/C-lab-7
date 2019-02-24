#include "task3.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(int argc, const char * argv[]) {
	if (argc < 2)
	{
		puts("Wrong format");
		return -7;
	}

	SYM syms[256] = { 0 };		//creating array of structures

	MakingTableOfFrequencies(syms, argv[1]);

	//creating the table of frequencies
	SortingArrByFrequencies(syms);
	PrintTableWithFrequencies(syms);
	return 0;
}