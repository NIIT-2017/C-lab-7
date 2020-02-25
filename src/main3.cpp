#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"task3.h"

int main(int agrc, char** argv)
{
	SYM simbol_fp[SIZE];
	FILE* fp;
	int count_simbol = 0;

	fp = fopen(argv[1], "r");
	if (!fp)
	{
		perror("File :");
		exit(1);
	}

	initialize(&simbol_fp[0]);
	calculation_occurrence(&simbol_fp[0], analysis_fp(&simbol_fp[0], fp));
	sort(&simbol_fp[0]);
	print_simbols(&simbol_fp[0]);

	if (fclose(fp) != 0)
		puts("Error closing the file!");

	return 0;
}
