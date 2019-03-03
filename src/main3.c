/*
Написать программу, которая строит таблицу встречаемости символов
для произвольного файла, имя которого задаётся в командной строке.
Программа должна выводить на экран таблицу встречаемости,
отсортированную по убыванию частоты

В программе необходимо определить структурный тип SYM, 
в котором нужно хранить код символа и частоту встречаемости (вещественное число от 0 до 1). 
После анализа файла, массив структур SYM должен быть отсортирован по частоте.
*/
#include "task3.h"
#include <stdio.h>
int compare(const void* p1, const void* p2)
{
		return (((struct SYM*)p2)->freq - ((struct SYM*)p1)->freq);
}
int main(int argc,char *argv[])
{
	struct SYM table[128] = { NULL };
	FILE *fp;
	if (argc > 1)
		fp = fopen(argv[1], "r");
	else
		fp = fopen("text.txt", "r");
	if (fp == NULL)
	{
		puts("File not found");
		return 1;
	}
	char buf[255];
	/*if (fread(buf, sizeof(char), 255, fp) != 255) 
	{
		if (feof(fp)) printf("Premature end of file.\n");
		else printf("File read error.");
	}*/
	char symbol;
	int i = 0, count = 0;
	while (fgets(buf, 255, fp) != NULL)
	{
		i = 0;
		while (buf[i] != '\0')
		{
			symbol = buf[i];
			table[(int)symbol].freq += 1;
			i++;
			count++;
		}
	}
	fclose(fp);
	while (i < 128)
	{
		table[i].ch = (char)i;
		i++;
	}
	qsort(table, 128, sizeof(struct SYM), compare);
	i = 0;
	printf("ASCII\tSYMBOL\tfrequncy\n");
	while (i < 128)
	{
		if (table[i].freq != 0)
			if(table[i].ch==10)
				printf("%d\t[!n]\t%f\n", table[i].ch, table[i].freq / count);
			else
			printf("%d\t[%c]\t%f\n", table[i].ch, table[i].ch, table[i].freq / count);
		i++;
	}
	return 0;
}