#include "task1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

PITEM createList(PREGION_REC name_rec)
{
	PITEM item = (PITEM)malloc(sizeof(TITEM));
	item->region_rec = name_rec;
	item->prev = NULL;
	item->next = NULL;
	return item;
}

PREGION_REC createName(char* line)
{
	int i = 0;
	PREGION_REC rec = (PREGION_REC)malloc(sizeof(TREGION_REC));
	while (*line && *line != ',')
		rec->country[i++] = *line++;  //чтение до символа , цикл каждый раз пробегает по строчкам
	rec->country[i] = 0;
	line++;

	i = 0;
	while (*line && *line != ',')
		rec->region[i++] = *line++;  
	rec->region[i] = 0;
	line++;
	line++;
	
	i = 0;
	while (*line)
	//while (*line)
		rec->name[i++] = *line++;
	rec->name[i-2] = 0;
	return rec;
}

PITEM addToTail(PITEM tail, PREGION_REC name_rec)
{
	PITEM item = createList(name_rec);
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

PITEM findByName(PITEM head, char* name)
{
	while (head)
	{
		if (strcmpi(head->region_rec->name, name) == 0)
			return head;
		head = head->next;
	}
	return NULL;
}

PITEM findByCountryId(PITEM head, char* name)
{
	while (head)
	{
		if (strcmpi(head->region_rec->country, name) == 0)
			return head;	
		head = head->next;
	}
	return NULL;
}

void printItem(PITEM item)
{
	if (item != NULL)
		printf("%s %s %s\n", item->region_rec->country, item->region_rec->region, item->region_rec->name);
}
