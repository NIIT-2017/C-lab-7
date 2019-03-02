#include "task1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


PITEM createList(PREGION region_rec) //create a list
{
	PITEM item = (PITEM)malloc(sizeof(ITEM));
	
	item->region_rec=region_rec;
	item->next=NULL;
	item->prev = NULL;
	return item;
}

PREGION createRegion(char *line)
{
	int i = 0;
	PREGION reg = (PREGION)malloc(sizeof(REGION));
	while (*line && *line != ',')
		reg->country[i++] = *line++;
	reg->country[i] = 0;
	line++;
	
	i = 0;
	while (*line && *line != ',')
		reg->code[i++] = *line++;
	reg->code[i] = 0;
	line++;
	line++;

	i = 0;
	while (*line)
		reg->name[i++] = *line++;
	reg->name[i-2] = 0;
	return reg;
}

PITEM addToTail(PITEM tail, PREGION region_rec)
{
	PITEM item = createList(region_rec);
	if (tail != NULL)
	{
		tail->next = item;
		item->prev = tail;
	}
	return item;
}

void printRegion(PITEM item)
{
	if (item != NULL)
	{
		puts(item->region_rec->country);
		puts(item->region_rec->code);
		puts(item->region_rec->name);
	}
}

int countList(PITEM head)
{
	int count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return count;
}

void findByCountry(PITEM head, char * country)
{
	int count1 = 0;
	while (head)
	{
		if (strcmpi(head->region_rec->country, country) == 0)
		{
			printf("%s %s %s\n", head->region_rec->country, head->region_rec->code, head->region_rec->name);
			count1++;
		}
		head = head->next;
	}
	if (count1 == 0)
		printf("Not found!\n");
}

void findByCode(PITEM head, char * code)
{
	int count1 = 0;
	while (head)
	{
		if (strcmpi(head->region_rec->code, code) == 0)
		{
			printf("%s %s %s\n", head->region_rec->country, head->region_rec->code, head->region_rec->name);
			count1++;
		}
		head = head->next;
	}
	if (count1 == 0)
		printf("Not found!\n");
}

void findByName(PITEM head, char * name)
{
	int count1 = 0;
	while (head)
	{
		if (strcmpi(head->region_rec->name, name) == 0)
		{
			printf("%s %s %s\n", head->region_rec->country, head->region_rec->code, head->region_rec->name);
			count1++;
		}
		head = head->next;
	}
	if (count1 == 0)
		printf("Not found!\n");
}
