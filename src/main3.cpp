#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "task3.h"

int main(int argc, char* argv[])
{
	unsigned char ch;
	int  count = 0;
	TSYM buf[256] = { 0 };
	PSYM root = NULL;
	
	FILE *fp;
	if (argc != 2)
	{
		printf("Using: %s file name\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		puts("File not found!");
		exit(EXIT_FAILURE);
	}

	while (fgetc(fp) != EOF)
		count++;
	rewind(fp);
		
	for (int i = 0; i < count; i++)
	{
		ch = fgetc(fp);
		create(buf, ch, count);
	}
	fclose(fp);
	Sort(buf);
	print(buf);
	return 0;
}
