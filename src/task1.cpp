#include "task1.h"
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

PITEM createList(PREGION region_rec)//creating a list of containers
{
	PITEM item = (PITEM)malloc(sizeof(ITEM));//memory for one new element
	item->region_rec = region_rec;
	item->prev = NULL;
	item->next = NULL;
	return item;
}

PREGION createRegion(char *line)//getting string from the file in argument
{
	int i = 0;
	PREGION rec = (PREGION)malloc(sizeof(REGION));//memory for one new element
	while (*line && *line != ',')//getting symbols till the first comma 
		rec->symbols[i++] = *line++;//filling symbols box with symbols one by one
	rec->symbols[i] = 0;//closing a string by entering \0
	line++;//moving right for a comma
	
	i = 0;
	while (*line && *line != ',')//getting symbols till the second comma 
		rec->number[i++] = *line++;//filling number box with symbols one by one
	rec->symbols[i] = 0;//closing a string by entering \0
	line++;//moving right for a comma
	line++;//moving right for a "

	i = 0;
	while (*line)//getting symbols till the end of the line
		rec->region[i++] = *line++;//filling region box with symbols one by one
	rec->region[i-2] = 0;//closing a string by entering \0
	return rec;
}

PITEM addToTail(PITEM tail, PREGION region_rec)//adding one container to the tail
{
	PITEM item = createList(region_rec);//create one container
	if (tail != NULL)//if tail is not NULL - if it is not a first line
	{
		tail->next = item;//linking next of the existing tail with new (just created) container 
		item->prev = tail;//for a prev of the just created container add pointer to the old tail
	}
	return item;
}

void findBySymbols(PITEM head, char *symbols)//printing all regions with the same symbols
{
	while (head)
	{
		if (strcmpi(head->region_rec->symbols, symbols) == 0)
			printRegion(head);
		head = head->next;
	}
	return;
}

void printRegion(PITEM item)//printing one region
{
	if (item != NULL)
	{
		puts(item->region_rec->symbols);
		printf("%c%c\t", item->region_rec->number[0], item->region_rec->number[1]);
		puts(item->region_rec->region);
		printf("\n\n");
	}
}

PITEM findByRegion(PITEM head, char *region)//finding a region by the name
{
	while (head)
	{
		if (strcmpi(head->region_rec->region, region) == 0)
			return head;//if found returning the address
		head = head->next;
	}
	return NULL;
}