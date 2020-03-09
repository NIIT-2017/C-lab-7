#define _CRT_SECURE_NO_WARNINGS
#include "task1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void freeList(RegionInfo* begin)
{
	RegionInfo* beginCopy;
	while (begin != NULL)
	{
		beginCopy = begin->next;
		free(begin);
		begin = beginCopy;
	}
}

void writeIn(RegionInfo* pr, char* buf)
{
	char* pc = pr->regionName;

	sscanf(buf, "%2s,%2s", pr->isoCountry, pr->regionCode); //Функция sscanf() идентична функции scanf(), но данные считываются из массива, указанного аргументом buf, а не из файла stdin.
	while (*buf++ != '"');
	while ((*pc++ = *buf++) != '"');
	*(--pc) = '\0'; //заодно " удалится
}

RegionInfo* fillList(RegionInfo* begin)
{
	begin = (RegionInfo*)malloc(sizeof(RegionInfo)); 
	begin->next = NULL;
	RegionInfo* beginCopy = begin;

	FILE* fp = NULL;
	char buf[100];
	fp = fopen("fips10_4.csv", "rt");
	fgets(buf, 100, fp);

	while (fgets(buf, 100, fp) != NULL)
	{
		if (feof(fp) || ferror(fp)) //Чтение файла закончено или Ошибка чтения из файла
		{
			printf("er or EOF");
			break;
		}
		writeIn(begin, buf);

		begin->next = (RegionInfo*)malloc(sizeof(RegionInfo)); 
		if (begin->next == NULL)
		{
			printf("error of malloc");
			break;
		}
		begin = begin->next;
		begin->next = NULL;
	}

	fclose(fp);

	return beginCopy;
}

void RegionNameSP(RegionInfo* begin, char* nameRegion)
{
	int flag = 1;

	printf("\nRESULT for \"%s\":\n\n", nameRegion);
	while (begin != NULL)
	{
		if (!strcmp(begin->regionName, nameRegion))
		{
			printf("%s\,%s,\"%s\"\n", begin->isoCountry, begin->regionCode, begin->regionName);
			flag = 0;
			break;
		}
		begin = begin->next;
	}
	if (flag)
		printf("\"%s\" isn't found\n", nameRegion);
	printf("\n");
}

void CountryISO_SP(RegionInfo* begin, char* countryISO)
{
	int flag = 1;

	printf("\nRESULT for \"%s\":\n\n", countryISO);
	while (begin != NULL)
	{
		if (!strcmp(begin->isoCountry, countryISO)) 				//0 – если сравниваемее строки идентичны.														
		{
			flag = 0;
			printf("%s\,%s,\"%s\"\n", begin->isoCountry, begin->regionCode, begin->regionName);
		}
		else if (!flag)
			break;
		begin = begin->next;
	}
	if (flag)
		printf("\"%s\" isn't found\n", countryISO);
	printf("\n");
}