#include "task1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

PITEM createList(PREGION_REC region_rec)
{
    PITEM item = (PITEM)malloc(sizeof(TITEM));
    item->region_rec = region_rec;
    item->prev = NULL;
    item->next = NULL;
    return item;
}
PREGION_REC createRegion(char* line)
{
    int i = 0;
    PREGION_REC rec = (PREGION_REC)malloc(sizeof(TREGION_REC));
    while (*line && *line != ',')
        rec->country[i++] = *line++;
    rec->country[i] = 0;
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
    rec->name[i-1] = 0;
    return rec;
}
PITEM addToTail(PITEM tail, PREGION_REC region_rec)
{
    PITEM item = createList(region_rec);
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
        if (_strcmpi(head->region_rec->country, country) == 0)
            return head;
        head = head->next;
    }
    return NULL;
}

void findAllCountries(PITEM head, char* country)
{
    PITEM item = 0;
    item = findByCountry(head, (char*) country);
    if (item != NULL)
    {
        printRegion(item);
        findAllCountries(item->next, (char*) country);
    }
}

PITEM findByName(PITEM head, char* name)
{
    while (head)
    {
        if (_strcmpi(head->region_rec->name, name) == 0)
            return head;
        head = head->next;
    }
    return NULL;
}

void printRegion(PITEM item)
{
    if (item != NULL)
    {
        puts(item->region_rec->country);
        puts(item->region_rec->code);
        puts(item->region_rec->name);
        puts("***");
    }
}