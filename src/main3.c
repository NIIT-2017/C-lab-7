//#include <stdio.h>
//#include <stdlib.h>
//#include "task3.h"
//
//int main(int argc, char* argv[])
//{
//	if (argc < 2)
//	{
//		printf("wrong format\n");
//		return 1;
//	}
//	FILE *book = fopen(argv[1], "r");
//	if (!book)
//	{
//		printf("cannot open %s\n", argv[1]);
//		return 2;
//	}
//
//	float frequenciesArray[MAX_SYM_COUNT] = { 0 };
//	int SYMcount = MakeFreqsArray(book, frequenciesArray);
//
//	SYM* SYMarray = (SYM*)malloc(SYMcount * sizeof(SYM*));
//
//	FillingSYMarray(SYMarray, frequenciesArray);
//
//	PrintSYMarray(SYMarray);
//
//	fclose(book);
//	free(SYMarray);
//	return 0;
//}