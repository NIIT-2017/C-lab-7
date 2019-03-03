/*
Написать программу, которая строит таблицу встречаемости символов
для произвольного файла, имя которого задаётся в командной строке.
Программа должна выводить на экран таблицу встречаемости,
отсортированную по убыванию частоты.
Пояснение:
В программе необходимо определить структурный тип SYM, в котором нужно хранить код символа и частоту встречаемости (вещественное число от 0 до 1). После анализа файла, массив структур SYM должен быть отсортирован по частоте.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "task3.h"


int main(int argc, char* argv[])
{
	struct SYM** psyms = 0;
	int N = 0;
	if (argc > 1)
	{
		FILE *fp = fopen(argv[1], "rt");
	}
	FILE *fp = fopen("keywords.txt", "rt");
	if (fp == NULL)
	{
		printf("File is not openning");
		return 1;
	}
	psyms = mkPsyms(fp, &N);
	print(psyms, N);
	if (fclose(fp) == EOF)
	{
		printf("Error! Can`t close file!!");
	}
	return 0;
}