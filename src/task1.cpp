#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "task1.h"
#define MAXNAME 128
#define MAXPREFICS 3

void clean_stdin(void) // the option to clear the input  buffer
{
	int c;
	do
	{
		c = getchar();
	} while (c != '\n' && c != EOF);
}

void parsing(char buf[256], char prefics[MAXPREFICS], char code[MAXPREFICS], char name[MAXNAME]) //"AD,02,""Canillo""" 
{
	int i = 1, j = 0, k = 0, l = 0;
	for (; i < 3; i++)
		prefics[j++] = buf[i];
	for (i = 4; i < 6; i++)
		code[k++] = buf[i];
	for (i = 9; buf[i] && buf[i] != '"'; i++)
		name[l++] = buf[i];
	prefics[j] = 0;
	code[k] = 0;
	name[l] = 0;
}

void searchBYcountryCode(regionST* headOflist, char tempChar[])
{
	regionST* pointOflist = headOflist;
	int result = 0;

	printf("\n#########################################################\n# Resalt for FIPS country code \"%s\":", tempChar);
	printf("\n#########################################################\n");
	while (pointOflist != NULL)
	{
		if (!strcmp(pointOflist->countryCode, tempChar))
		{
			result++;
			printRegion(pointOflist);
		}
		pointOflist = pointOflist->next;
	}
	if (result)
	{
		printf("\n#########################################################\n#    Total entries: %d", result);
		printf("\n#########################################################\n");
	}
	else
	{
		printf("\n#########################################################\n#    Sorry, but we didn't find the specified region");
		printf("\t#\n#########################################################\n");
	}
}

void searchBYname(regionST* headOflist, char tempChar[])
{
	regionST* pointOflist = headOflist;
	int result = 0;

	printf("\n#########################################################\n# Resalt for region name \"%s\":", tempChar);
	printf("\n#########################################################\n");
	while (pointOflist != NULL)
	{
		if (!strcmp(pointOflist->name, tempChar))
		{
			result++;
			printRegion(pointOflist);
		}
		pointOflist = pointOflist->next;
	}
	if (result)
	{
		printf("\n#########################################################\n#    Total entries: %d", result);
		printf("\n#########################################################\n");
	}
	else
	{
		printf("\n#########################################################\n#    Sorry, but we didn't find the specified region");
		printf("\t#\n#########################################################\n");
	}
}

void searchBYregionCode(regionST* headOflist, char tempChar[])
{
	regionST* pointOflist = headOflist;
	int result = 0;

	printf("\n#########################################################\n# Resalt for region code \"%s\":", tempChar);
	printf("\n#########################################################\n");
	while (pointOflist != NULL)
	{
		if (!strcmp(pointOflist->regionCode, tempChar))
		{
			result++;
			printRegion(pointOflist);
		}
		pointOflist = pointOflist->next;
	}
	if (result)
	{
		printf("\n#########################################################\n#    Total entries: %d", result);
		printf("\n#########################################################\n");
	}
	else
	{
		printf("\n#########################################################\n#    Sorry, but we didn't find the specified region");
		printf("\t#\n#########################################################\n");
	}
}

void printRegion(const regionST* pointOflist)
{
	printf("\n#########################################################\n");
	printf("# FIPS country code \t- %s\n# Region code \t\t- %s\n# Region name \t\t- %s\n", pointOflist->countryCode, pointOflist->regionCode, pointOflist->name);
	printf("#########################################################\n\n");
}

regionST* createStruct(char bufer[])
{
	regionST* item = (regionST*)malloc(sizeof(regionST));
	parsing(bufer, item->countryCode, item->regionCode, item->name);
	item->next = NULL;
	return item;
}

regionST* createList(FILE* fp)
{
	char bufer[256] = { 0 };
	regionST* first = NULL;
	regionST* subsequent = NULL;
	
	fgets(bufer, 256, fp);
	first = createStruct(bufer);
	subsequent = first;

	while (fgets(bufer, 256, fp))
	{
		subsequent->next = createStruct(bufer);
		subsequent = subsequent->next;
	}
	
	return first;
}

void deleteList(regionST* pointOflist)
{
	if (pointOflist->next != NULL)
		free(pointOflist->next);
	free(pointOflist);
}