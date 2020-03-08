#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"
void clearList(RegionInfo* begin)
{
	RegionInfo* beginCopy;
	while (begin != NULL)
	{
		beginCopy = begin->next;
		free(begin);
		begin = beginCopy;
	}
}
void writeInfo(RegionInfo* pr, char* buf)
{
	char* pc = pr->regionName;
	sscanf(buf, "%2s,%2s", pr->regionISO, pr->regionCode);
	while (*buf++ != '"'); //first
	while ((*pc++ = *buf++) != '"'); //last
	*(--pc) = '\0';
}
RegionInfo* loadingList(RegionInfo* begin)
{
	begin = (RegionInfo*)malloc(sizeof(RegionInfo));
	begin->next = NULL;
	RegionInfo* beginCopy = begin;
	FILE* fp = NULL;
	char buf[100];
	fp = fopen("C:\\labsss\\fips.csv", "rt");
	if (!fp)
	{
		printf("Lost file\n");
	}
	fgets(buf, 100, fp);					
	while (fgets(buf, 100, fp) != NULL)
	{
		if (feof(fp))
		{
			printf("end of file");
			break;
		}
		writeInfo(begin, buf);
		begin->next = (RegionInfo*)malloc(sizeof(RegionInfo));
		begin = begin->next;
		begin->next = NULL;
	}
	fclose(fp);
	return beginCopy;
}
void searchNameResult(RegionInfo* begin, char* nameRegion)
{
	int flag = 1;
	printf("Result for \"%s\":", nameRegion);
	while (begin != NULL)
	{
		if (!strcmp(begin->regionName, nameRegion))
		{
			printf("%s\,%s,\"%s\"\n\n", begin->regionISO, begin->regionCode, begin->regionName);
			flag = 0;
			break;
		}
		begin = begin->next;
	}
	if (flag)
		printf("\"%s\" isn't found\n", nameRegion);
}
void searchISOResult(RegionInfo* begin, char* countryISO)
{
	int flag = 1;
	printf("Result for \"%s\":", countryISO);
	while (begin != NULL)
	{
		if (!strcmp(begin->regionISO, countryISO))
		{
			flag = 0;
			printf("%s\,%s,\"%s\"\n", begin->regionISO, begin->regionCode, begin->regionName);
		}
		else if (!flag)
			break;
		begin = begin->next;
	}
	if (flag)
		printf("\"%s\" is not found\n", countryISO);
	printf("\n");
}