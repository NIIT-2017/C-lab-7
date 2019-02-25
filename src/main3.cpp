#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task3.h"

/*
struct SYM // ������������� �������
{
	unsigned char ch; // ASCII-���
	float freq; // ������� �������������
	char code[256]; // ������ ��� ������ ����
	struct SYM *left; // ����� ������� � ������
	struct SYM *right; // ������ ������� � ������
};
*/

int main(int argc, char* argv[])
{
	if (argc < 2)		// check arguments
	{
		puts("Error! Not enough arguments! Please filename!");
		return 1;
	}
	
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL)								// check file opening
	{
		puts("ERROR! Cannot read file!");
		return 1;
	}

	struct SYM buf[256];			// structure array for letters
	initializeArray(buf);			// fill each structure in array

	char letter;					// one letter from file
	long long count = 0;			// how much letters in the file

	while (!feof(fp))
	{
		count++;
		letter = fgetc(fp);
		makeSymArray(buf, letter);
	}
	fclose(fp);

	qsort(buf, 256, sizeof(struct SYM), comp);

	calculateFreq(buf, count);		// redefine count of letters to part of 1 (calculate frequency)

	printArray(buf);

	return 0;
}