#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "task1.h"

TREGION *create(char *buf)
{
	TREGION * head = (TREGION*)malloc(sizeof(TREGION));
	int j = 0, i = 0;
	while(buf[i] != ',') //for (i = 0; buf[i] == ','; i++)
	{
		head->iso[j] = buf[i];
		j++;
		i++;
	}
	head->iso[j] = '\0';
	j = 0;
	i++;
	while (buf[i] != ',')//for (i; buf[i] == ','; i++)
	{
		head->code[j] = buf[i];
		j++;
		i++;
	}
	head->code[j] = '\0';
	j = 0;
	i++;
	while (buf[i] != '\n')//for (i; buf[i] == '\0'; i++)
	{
		head->name[j] = buf[i];
		j++;
		i++;
	}
	head->name[j]= '\0';

	head->next = NULL;
	
	
		printf("%s  %s  %s\n", head->iso, head->code, head->name);
	
	
	return head;
}

void add(TREGION * head, char *buf)
{
	while (head->next)
		head = head->next;
	head->next = create(buf);
}

void SearchIso(TREGION *head, char *iso)
{
	while (head)
	{
		if (strcmp(head->iso, iso) == 0)
			printf("%s %s %s\n", head->iso, head->code, head->name);
		head = head->next;
	}
}
void SearchName(TREGION *head, char *name)
{
	while (head)
	{
		if (strcmp(head->name, name) == 0)
			printf("%s %s %s\n", head->iso, head->code, head->name);
		head = head->next;
	}
}