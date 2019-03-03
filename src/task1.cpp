#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"

struct ITEM* createList(struct REGION* region_data)
{
	struct ITEM* item = (struct ITEM*)malloc(sizeof(struct ITEM));
	item->region = region_data;
	item->prev = nullptr;
	item->next = nullptr;
	return item;
}


//------------------------------------------------------------------------


struct REGION* createRegionData(char *line)
{
	struct REGION* region = (struct REGION*)malloc(sizeof(REGION));
	int i = 0;
	while (*line && *line != ',')
	{
		region->abbr[i++] = *line;
		line++;
	}
	region->abbr[i] = '\0';

	line++;
	i = 0;
	while(*line && *line != ',')
	{
		region->number[i++] = *line;
		line++;
	}
	region->number[i] = '\0';

	line += 2;
	i = 0;
	while(*line && *line != '"')
	{
		region->name[i++] = *line;
		line++;
	}
	region->name[i] = '\0';


	return region;
}


//------------------------------------------------------------------------


struct ITEM* addToTail(struct ITEM* our_item, struct REGION* region)
{
	struct ITEM* new_item = createList(region);
	if (our_item != nullptr)
	{
		our_item->next = new_item;
		new_item->prev = our_item;
	}

	return new_item;
}


//-----------------------------------------------------


int countList(struct ITEM* item)
{
	int count = 0;
	while (item)
	{
		count++;
		item = item->next;
	}
	return count;
}


//---------------------------------------------------------------


struct ITEM* findByAbbr(struct ITEM* item, char *abbr)
{
	int count = 0;
	while (item)
	{
		if (strcmp(item->region->abbr, abbr) == 0)
		{
			return item;
		}
		else
			item = item->next;
	}
	return nullptr;
}


//-----------------------------------------------------


void PrintByAbbr(struct ITEM* item, char *abbr)
{
	while ((strcmp(item->region->abbr, abbr) == 0))
	{
		printRegionData(item);
		item = item->next;
	}
}


//---------------------------------------------------------------------------


struct ITEM* findByName(struct ITEM* item, char *name)
{
	while (item)
	{
		if (strcmp(item->region->name, name) == 0)
			return item;
		item = item->next;
	}
	return nullptr;
}


//-------------------------------------------------------------------


void printRegionData(struct ITEM* item)
{
	if (item != nullptr)
	{
		printf("%s ",item->region->abbr);
		printf("%s ",item->region->number);
		puts(item->region->name);
	}
}


//----------------------------------------------------------------


int checkStr(struct REGION* region)
{
	if (strlen(region->abbr) != 2)
		return 1;
	if (strlen(region->number) != 2)
		return 1;
	return 0;
}