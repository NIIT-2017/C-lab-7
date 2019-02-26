#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "task3.h"

int main(int argc, char* argv[])
{
	FILE *fp;
	TSYM buf[256] = {0};
	PSYM root = NULL;
	unsigned char ch;
	int  count = 0;     //total characters
	int word = 0;       //Number of unique characters
	
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

	int i = 0;
	while (i < count)
	{
		ch = fgetc(fp);
		createBuf(buf, ch, count, &word);
		i++;
	}

	fclose(fp);
	bufSort(buf, word);
	printBuf(buf, word);
	return 0;
}