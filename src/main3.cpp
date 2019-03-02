#include <stdio.h>

#include <string.h>
#include "task3.h"


int main(int argc, char* argv[])
{
	int count = 0;  // total characters
	int uniqueCount = 0;  // unique characters
	unsigned char ch = 0;
	FILE *fp;
	SYM syms[N] = { 0 }; // array of structures for writing characters
	
	/*
	if (argc < 2)
	{
		printf("No file name");
		return -1;
	}
	
	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		puts("File not found!");
		return 1;
	}
	*/

	if ((fp = fopen("1.txt", "r")) == NULL)
	{
		puts("File not found!");
		return 1;
	}

	
	while (fgetc(fp)!=EOF)
		count++;
	
	rewind(fp);

	for (int i = 0;i < count;i++)
	{
		ch = fgetc(fp);
		createStruct(syms, ch, count, &uniqueCount);
	}

	fclose(fp);

	sortStruct(syms, uniqueCount);
	
	printStruct(syms, uniqueCount);

	return 0;
}