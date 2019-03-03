/*
Написать программу, создающую связанный список с записями о регионах и их
кодах в соответствии с содержанием файла данных.


Файл скачивается по адресу: http://introcs.cs.princeton.edu/java/data/fips10_4.csv 

Программа должна поддерживать следующие функции:

	Формирование списка на основе данных файла.
	Поиск и вывод всех данных по буквенному обозначению страны.
	Поиск конкретного региона по названию.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"

int main()
{
	FILE* file;
	int count = 0;
	char buf[SIZE] = { '\0' };
	struct ITEM* new_item = nullptr;
	struct ITEM* our_item = nullptr;
	struct ITEM* item = nullptr;
	file = fopen("fips10_4.csv", "rt");
	if (file == NULL)
	{
		perror("File error");
		return 1;
	}

	struct REGION* tmp;
	while (fgets(buf, SIZE, file))
	{
		tmp = createRegionData(buf);
		if (checkStr(tmp))
			continue;
		if (count == 0)
		{
			new_item = createList(tmp);
			our_item = new_item;
		}
		else
		{
			our_item = addToTail(our_item, tmp);
		}
		count++;
	}

	//------------------------------
	fclose(file);
	printf("Total items: %d\n\n", countList(new_item));
	//-------------------------------

	const char* abbr = "WS";
	item = findByAbbr(new_item, (char*)abbr); // (in the file "fips10_4.csv -> numbers of WS is 10)
	PrintByAbbr(item, (char*)abbr);
	putchar('\n');
	//-------------------------------

	item = findByName(new_item, (char*)"Lara"); // (VE,13,"Lara")
	printRegionData(item);

	return 0;
}