#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "task3.h"

int main(int argc, const char * argv[])
{
	setlocale(LC_ALL, "Rus");
	if (argc < 2)
		printf("Arguments not found");
	struct sym library[256];
	
	unsigned char symbol[256];
	float number[256];
	int x = 0, i = 0;
	
	i = buildbuf(symbol, number, argv[1]);
	buildStruct(i, library, symbol, number);

	while (x < i)
	{
		printf("%c %f\n", library[x].symb, library[x].num);
		x++;
	}

	getchar();
	return 0;
}

