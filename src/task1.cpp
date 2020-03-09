//Clab 7 task1

#include "task1.h"

struct note* create(struct region* any)
{
	note* head = (note*)malloc(sizeof(note));
	head->country = *any;
	head->next = NULL;
	return head;
}

void add(struct note* head, struct region* any)
{
	while (head->next != NULL)
	{
		head = head->next;
	}

	note* wagon = (note*)malloc(sizeof(note));
	head->next = wagon;

	wagon->country = *any;
	wagon->next = NULL;
}

void CodeSearch(char* strCode, note* head)
{
	while (head->next != NULL)
	{
		int a = strcmp(strCode, head->country.code);
		if (a == 0)
		{
			printf("%s\t%s\t%s\n", head->country.code, head->country.number, head->country.name);
		}
		head = head->next;
	}
}

void NameSearch(char* strName, note* head)
{
	while (head->next != NULL)
	{
		int a = strcmp(strName, head->country.name);
		if (a == 0)
		{
			printf("%s\t%s\t%s\n", head->country.code, head->country.number, head->country.name);
		}
		head = head->next;
	}
}