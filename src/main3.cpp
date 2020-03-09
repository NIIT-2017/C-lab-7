#include "task3.h";
#include <stdio.h>;
#include <stdlib.h>;

#define SIZE 256

int main(int argc, char** argv)
{
	FILE* fp;
	fp = fopen(argv[1], "rt");
	if (fp == NULL)
	{
		puts("File open erorr!");
		return 1;
	}
	struct SYM syms[SIZE] = {0};
	int ch;
	int count = 0;
	while ((ch = fgetc(fp)) != EOF)//по символьно 
	{
		if (ch == '\n')
			continue;
		count++;
		for (int i = 0; i < SIZE; i++)
		{
			if (ch == syms[i].ch)
			{
				syms[i].freq++;
				break;
			}
			else if (syms[i].ch == 0)
			{
				syms[i].ch = ch;
				syms[i].freq++;
				break;
			}
		}
	}
	for (int i = 0; i < SIZE; i++)
		syms[i].freq = syms[i].freq/count;
	fclose(fp);
	qsort(syms, SIZE, sizeof(syms[0]), cmp);// использую сортировку
	print(syms);
	return 0;
}