#include <stdio.h>
#include <string.h>
#include "task1.h"

void str(struct regions *current, char buf[])
{
	int i = 0, l = 0;
	while (buf[i])
	{
		if (buf[i] == ',')
		{
			current->country[l] = '\0';
			break;
		}
		current->country[l] = buf[i];

		l++, i++;
	}
	l = 0, i++;
	while (buf[i])
	{
		if (buf[i] == ',')
		{
			current->code[l] = '\0';
			break;
		}
		current->code[l] = buf[i];
		l++, i++;
	}
	l = 0, i++;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			current->reg[l] = '\0';
			break;
		}
		current->reg[l] = buf[i];
		l++, i++;
	}
}

void region(struct regions * head, struct regions * current, char *qwerty)
{
	
	current = head;
	while (current != NULL)
	{
		if (strcmp(current->reg, qwerty) == 0)
			printf("%s,%s,%s\n", current->country, current->code, current->reg);
		current = current->next;
	}
	getchar();
}

void country(struct regions * head, struct regions * current, char *qwerty)
{

	current = head;
	while (current != NULL)
	{
		if (strcmp(current->country, qwerty) == 0)
			printf("%s,%s,%s\n", current->country, current->code, current->reg);
		current = current->next;
	}
	getchar();
}