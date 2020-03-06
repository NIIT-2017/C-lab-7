#include "task3.h"
#include <stdio.h>

void fillTable(FILE* fp, sym* charOccurrence) // заполняем таблицу данными из файла
{
	for (int i = 0; i < NUMBERCHAR; i++)
	{
		charOccurrence[i].ch = i;
		charOccurrence[i].count = 0;
		charOccurrence[i].repeatability = 0;
	}
	char ch = 0;
	int generalCount = 0;
	while ((ch = fgetc(fp)) != EOF)
	{
		charOccurrence[ch].count++;
		generalCount++;
	}
	if (generalCount)
		for (int i = 0; i < NUMBERCHAR; i++)
			charOccurrence[i].repeatability = (float)charOccurrence[i].count / (float)generalCount;
}

int compar(const void* c1, const void* c2) //функция сравнения для стандартной qsort 
{
	if (((sym*)c1)->repeatability < ((sym*)c2)->repeatability)
		return 1;
	else if (((sym*)c1)->repeatability > ((sym*)c2)->repeatability)
		return -1;
	else
		return 0;
}