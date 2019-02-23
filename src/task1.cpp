#include "task1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ITEM * createList(struct REC *P_REC)
{
	struct ITEM * item = (struct ITEM*)malloc(sizeof(struct ITEM));
	item->P_REC = P_REC;
	item->next = NULL;
	item->prev = NULL;
	return item;

}

struct REC * createRec(char*line)
{
	int i = 0;
	struct REC * rec = (struct REC *)malloc(sizeof(struct REC));
	while (*line && *line != ',')
		rec->country[i++] = *line++;	
	rec->country[i] = 0;
	line++;
	i = 0;
	while (*line&&*line!=',')
		rec->code[i++] = *line++;
	rec->code[i] = 0;
	line++;
	i = 0;
	while (*line)
		rec->region[i++] = *line++;
	rec->region[i] = 0;
	line++;
	i = 0;
	return rec;
}

struct ITEM * addToTail(struct ITEM *tail, struct REC *P_REC)
{
	struct ITEM * item = createList(P_REC);
	if (tail != NULL)
	{
		tail->next = item;
		item->prev = tail;
		
	}
	return item;
}

int countList(struct ITEM *head)
{
	int count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return count;
}

struct ITEM * findByCountry(struct ITEM * head, char *country)
{
	while (head)
	{
		if (strcmpi(head->P_REC->country, country) == 0)
			return head;
		head = head->next;
	}
	return NULL;
}

struct ITEM * findByCode(struct ITEM *head, char*code)
{
	while (head)
	{
		if (strcmpi(head->P_REC->code, code) == 0)
			return head;
		head = head->next;
	}
	return NULL;
}

struct ITEM * findByRegion(struct ITEM * head, char *region)
{
	while (head)
	{
		if (strcmpi(head->P_REC->region, region))
			return head;
		head = head->next;

	}
	return NULL;
}

void printCountry(struct ITEM* item)
{
	if (item != NULL)
	{
		puts(item->P_REC->country);
		puts(item->P_REC->code);
		puts(item->P_REC->region);
	}
}