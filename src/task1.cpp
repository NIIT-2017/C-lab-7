#include "task1.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

static void printItem(PItem item); //local function

PItem createList(PRegion region)
{
	PItem item = (PItem)malloc(sizeof(TItem));
	item->region = region;
	item->prev = NULL;
	item->next = NULL;

	return item;
}

PRegion createRegion(char*line)
{
	char buf[256] = { 0 };
	int i = 0;
	PRegion rec = (PRegion)malloc(sizeof(TRegion));

	while (*line && *line != ',')
	{
		if (*line == '\"')
			*line++;
		else
			rec->cod_country[i++] = *line++;
	}
	rec->cod_country[i] = '\0';
	puts(rec->cod_country);
	line++; //becouse I meet ','
	i = 0;

	while (*line && *line != ',')
		rec->index[i++] = *line++;
	rec->index[i] = '\0';
	puts(rec->index);
	line++; //becouse I meet ','
	i = 0;

	while (*line && *line!='\n')
	{
		if (*line == '\"')
			*line++;
		else //if this is a letter
			rec->town[i++] = *line++;
	}
	rec->town[i] = '\0';
	puts(rec->town);
	i = 0;

	return rec;
}

PItem addToTail(PItem tail, PRegion region)
{
	PItem item = createList(region);
	if (tail != NULL)
	{
		tail->next = item;
		item->prev = tail;
	}

	return item;
}

int countList(PItem head)
{
	int count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return count;
}

void findOllData(PItem head, char* country)
{
	int count = 0;

	while (head)
	{
		if (_strcmpi(head->region->cod_country, country) == 0) //if countrys match
		{
			printItem(head);
			count++;
		}
		head = head->next;
	}
	if (head==NULL && count==0)
		printf("Not found!\n");
}

void printItem(PItem item)
{
		puts(item->region->cod_country);
		puts(item->region->index);
		puts(item->region->town);
}

PItem findDesiredRegion(PItem head, char* town)
{
	while (head)
	{
		if (_strcmpi(head->region->town, town) == 0) //if towns match
			return head;

		head = head->next;
	}
	return NULL;
}

void printDesiredRegion(PItem item)
{
	if (item != NULL)
		printf("The region \"%s\" is in country \"%s\" (his index=%s)\n", item->region->town, item->region->cod_country, item->region->index);
}