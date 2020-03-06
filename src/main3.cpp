#include <stdio.h>
#include <stdlib.h>
#include "task3.h"

int main(int argc, char* argv[])
{
	FILE* fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("File not found\n");
		exit(1);
	}
	symST charOccurrence[NUMBERCHAR];
	fillTable(fp, charOccurrence);
	fclose(fp);
	qsort(charOccurrence, NUMBERCHAR, sizeof(sym), compar);
	for (int i = 0; i < NUMBERCHAR; i++)
		if (charOccurrence[i].repeatability != 0)
			printf("%c : %lf\n", charOccurrence[i].ch, charOccurrence[i].repeatability);
	return 0;
}