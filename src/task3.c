#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "task3.h"

int buildbuf(unsigned char *symbol, float *number, const char * fileName)
{
	int n = 0;
	int arr[256] = { 0 };
	int x = 0, i = 0;

	FILE *fp;//вывод текста из файла
	fp = fopen(fileName, "r");
	if (fp == NULL)
		puts("not found");
	while ((n = fgetc(fp)) != -1)
	{
		for (x = 0; x <= i; )
		{
			if (x == i)
			{
				symbol[i] = (unsigned char) n;
				arr[i]++;
				i++;
				break;
			}
			else if ((unsigned char) n == symbol[x])
			{
				arr[x]++;
				break;
			}
			x++;
		}
	}
	
	float y = 0;//перевод счетчика во встречаемость
	for (x = 0; x < i; x++)
		y = y + arr[x];
	for (x = 0; x < i; x++)
		number[x] = arr[x] / y;

	float *pnum = &number[x];//сортировка обоих массивов
	unsigned char *psym = &symbol[x];
	float maxnum = 0;
	unsigned char maxsym = '0';
	for (x = 0; x < i; x++)
	{
		for (pnum = &number[x], psym = &symbol[x], maxnum = *pnum, maxsym = *psym; *pnum != number[i]; pnum++, psym++)
		{
			if (*pnum >= maxnum)
			{
				number[x] = *pnum, *pnum = maxnum, maxnum = number[x];
				symbol[x] = *psym, *psym = maxsym, maxsym = symbol[x];
			}
		}
	}
	return i;
}

void buildStruct(int i, struct sym library[], unsigned char *symbol, float *number)//заполнение массива структур
{
	int x = 0;
	while (x < i)
	{
		library[x].symb = symbol[x];
		library[x].num = number[x];
		x++;
	}
}
