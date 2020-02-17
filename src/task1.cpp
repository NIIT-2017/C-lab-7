#include "task1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

PITEM createList(PREGION region)
{
	PITEM item = (PITEM)malloc(sizeof(TITEM));
	item->region = region;
	item->prev = NULL;
	item->next = NULL;
	return item;
}
PREGION createName(char* line)
{
	int i = 0;
	PREGION rec = (PREGION)malloc(sizeof(TREGION));
	if (line[strlen(line) - 1] == '\n')
		line[strlen(line) - 1] = '\0';
	while (*line && *line != ',')
	{
		if (*line != '\\' && *line != '"')
			rec->country[i++] = *line++;
		else
			*line++;
	}
	rec->country[i] = 0;
	line++;
	i = 0;
	while (*line && *line != ',')
	{
		if (*line != '\\' && *line != '"')
			rec->number[i++] = *line++;
		else
			*line++;
	}
	rec->number[i] = 0;
	line++;
	i = 0;
	while (*line)
	{
		if (*line != '\\' && *line != '"')
			rec->name[i++] = *line++;
		else
			*line++;
	}
	rec->name[i] = 0;
	return rec;
}
PITEM addToTail(PITEM tail,
	PREGION region)
{
	PITEM item = createList(region);
	if (tail != NULL)
	{
		tail->next = item;
		item->prev = tail;
	}
	return item;
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
PITEM findByCountry(PITEM head, char* country)
{
	while (head)
	{
		if (strcmpi(head->region->country, country) == 0)
			return head;
		head = head->next;
	}
	return NULL;
}
PITEM findByRegion(PITEM head, char* name)
{
	while (head)
	{
		if (strcmpi(head->region->name, name) == 0)
			return head;
		head = head->next;
	}
	return NULL;
}
void printName(PITEM item)
{
	if (item != NULL)
	{
		puts(item->region->country);
		puts(item->region->number);
		puts(item->region->name);
		putchar('\n');
	}
}