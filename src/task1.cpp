#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"

struct REGION *create(char *buf)
{
	int i = 0, j;
	if (buf[strlen(buf) - 1] == '\n')
		buf[strlen(buf) - 1] = '\0';
	struct REGION *event = NULL;
	if (event == NULL)
	{
		event = (struct REGION*)malloc(sizeof(struct REGION));
		if (event == NULL)
		{
			puts("Memory error!");
			exit(EXIT_FAILURE);
		}
		for ( j = 0; buf[i] != ','; i++)
		{
			if (buf[i] != '\"')
			{
				event->iso[j] = buf[i];
				j++;
			}
		}
		event->iso[j] = '\0';
		i++;

		for (j = 0; buf[i] != ','; i++)
		{
			if (buf[i] != '\"')
			{
				event->code[j] = buf[i];
				j++;
			}
		}
		event->code[j] = '\0';
		i++;

		for (j = 0; buf[i] != '\0';i++)
		{
			if (buf[i] != '\"')
			{
				event->name[j] = buf[i];
				j++;
			}
		}
		event->name[j] = '\0';

		event->next = NULL;
	}

	return event;
}

void print(REG *event)
{
	while (event)
	{
		printf("%s %s %s\n", event->iso, event->code, event->name);
		event = event->next;
	}
}

void add(REG *event, char *buf)
{
	while (event->next)
		event = event->next;
	event->next = create(buf);
}

void searchByIso(REG *event, char *iso)
{
	while (event)
	{
		if (strcmp(event->iso, iso) == 0)
			printf("%s %s %s\n", event->iso, event->code, event->name);
		event = event->next;
	}
}
void searchByName(REG *event, char *name)
{
	while (event)
	{
		if (strcmp(event->name, name) == 0)
			printf("%s %s %s\n", event->iso, event->code, event->name);
		event = event->next;
	}
}