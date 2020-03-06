#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "task1.h"

PITEM creatList(PCOUNTRIES countries)
{

    PITEM item=(PITEM)malloc(sizeof(TITEM));

    item->countries = countries;
    item->next = NULL;
    item->prev = NULL;
    return item;
}

PCOUNTRIES creatCountries(char *line)
{
    int i = 0;
    PCOUNTRIES rec = (PCOUNTRIES)malloc(sizeof(TCOUNTRIES));

    while(*line && *line != ',')
        rec->country[i++] = *line++;
    rec->country[i] = 0;
    line++;
    i=0;
    while(*line && *line != ',')
        rec->region_code[i++] = *line++;
    rec->region_code[i] = 0;
    line++;
    line++;
    i=0;
    while (*line && *line != '\n' && *line != '\"')
        rec->name[i++] = *line++;
    rec->name[i] = 0;
    return rec;
}

PITEM addToTail(PITEM tail, PCOUNTRIES countries)
{
    PITEM item = creatList(countries);
    if (tail!=NULL)
    {
        tail->next = item;
        item->prev = tail;
    }
    return item;
}

int countList(PITEM head)
{
    int count = 0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}
PITEM findByCode(PITEM head, char * country)
{
    while(head){
            if(strcasecmp(head->countries->country, country)==0)
                printf("Country - %s / Code - %s / region - %s\n",
                       head->countries->name,
                       head->countries->country,
                       head->countries->region_code);
        head=head->next;
    }
    return NULL;
}

PITEM findByCountry(PITEM head, char * name)
{
    while(head)
    {
            if(strncasecmp(head->countries->name, name, 5)==0)
                return head;
        head=head->next;
    }
    return NULL;
}

void printCountry(PITEM item)
{
    if(item!=NULL)
    {
        puts(item->countries->country);
        puts(item->countries->region_code);
        puts(item->countries->name);
    }
}

