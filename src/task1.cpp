#include "task1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

PITEM createList(PNAME_REC name_rec)
{
	PITEM item=(PITEM)malloc(sizeof(TITEM));
	item->name_rec=name_rec;
	item->prev=NULL;
	item->next=NULL;
	return item;
}
PNAME_REC createCountry(char *line)
{
	int i=0;
	PNAME_REC rec=(PNAME_REC)malloc(sizeof(TNAME_REC));
	while(*line && *line!=',')
		rec->country[i++]=*line++;
	rec->country[i]=0;
	line++;
	i = 0;
	while (*line && *line != ',')
		rec->code[i++] = *line++;
	rec->code[i] = 0;
	line++;
	i = 0;

	while (*line && *line != ',')
		if (*line == '"')
			*line++;
		else
			rec->name[i++] = *line++;
	rec->name[i - 1] = 0;
	return rec;
}
PITEM addToTail(PITEM tail,
			   PNAME_REC name_rec)
{
	PITEM item=createList(name_rec);
	if(tail!=NULL)
	{
		tail->next=item;
		item->prev=tail;	
	}
	return item;
}
int countList(PITEM head)
{
	int count=0;
	while(head)
	{
		count++;
		head=head->next;
	}
	return count;
}
PITEM findByCountry(PITEM head,char * country)
{
	while(head)
	{
		if(strcmpi(head->name_rec->country, country)==0)
			return head;
		head=head->next;
	}
	return NULL;
}
void findAllCountries(PITEM head, char* country)
{
	PITEM item = 0;
	item = findByCountry(head, (char*)country);
	if (item != NULL)
	{
		printCountry(item);
		findAllCountries(item->next, (char*)country);
	}
}
PITEM findByName(PITEM head, char* name)
{
	while (head)
	{
		if (strcmpi(head->name_rec->name, name) == 0)
			return head;
		head = head->next;
	}
	return NULL;
}
void printCountry(PITEM item)
{
	if(item!=NULL)
	{
		puts(item->name_rec->country);
		puts(item->name_rec->code); 
		puts(item->name_rec->name);
		puts("##########");
	}
}