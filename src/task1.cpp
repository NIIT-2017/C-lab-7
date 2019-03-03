#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"

PITEM createList(PREGION region)
{
	PITEM item = (PITEM)malloc(sizeof(TITEM));
	item->region = region;
	item->prev = NULL;
	item->next = NULL;
	return item;
}

PREGION createName(char *buf)
{
	int i = 0;
	PREGION reg = (PREGION)malloc(sizeof(TREGION));

	while (*buf&&*buf != ',')
		reg->iso[i++] = *buf++;

	reg->iso[i] = NULL;
	buf++;

	i = 0;
	while (*buf&&*buf!=',')
		reg->code[i++] = *buf++;

	reg->code[i] = NULL;
	buf++;

	i = 0;
	while (*buf)
		reg->region[i++] = *buf++;

	reg->region[i-1] = NULL;

	return reg;
}

PITEM addToTail(PITEM tail, PREGION region)
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

void findIso(PITEM head, char *region)
{
	while (head)
	{
		if (strcmp(head->region->iso, region) == 0)
			printf("%s %s %s\n", head->region->iso, head->region->code, head->region->region);
		head = head->next;
	}
}

void findName(PITEM head, char *city)
{
	while (head)
	{
		if (strcmp(head->region->region, city) == 0)
			printf("%s %s %s\n", head->region->iso, head->region->code, head->region->region);
		head = head->next;
	}
}