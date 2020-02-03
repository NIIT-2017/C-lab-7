#include "task1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

PITEM createList(PREGIONS regions)
{
    PITEM item = (PITEM)malloc(sizeof(TITEM));
    item->regions = regions;
    item->prev = NULL;
    item->next = NULL;
    return item;
}

PREGIONS createName(char * line)
{
    int i = 0;
    PREGIONS r = (PREGIONS)malloc(sizeof(TREGIONS));
    while (*line && *line != ',')
        r->cCode[i++] = *line++;
    r->cCode[i] = 0;
    line++;

    i = 0;
    while (*line && *line != ',')
        r->rCode[i++] = *line++;
    r->rCode[i] = 0;
    line++;
    
    line++;

    i = 0;
    while (*line)
        r->rName[i++] = *line++;
    r->rName[i - 2] = 0;
    return r;
}

PITEM addToTail(PITEM tail, PREGIONS regions)
{
    PITEM item = createList(regions);
    if (tail != NULL)
    {
        tail->next = item;
        item->prev = tail;
    }
    return item;
}

void findByCCode(PITEM head, char * cCode)
{
    while (head)
    {
        if (strcmpi(head->regions->cCode, cCode) == 0)
            printItem(head);
        head = head->next;
    }
}

PITEM findByRName(PITEM head, char * rName)
{
    while (head)
    {
        if (strcmpi(head->regions->rName, rName) == 0)
            return head;
        head = head->next;
    }
    return NULL;
}

void printItem(PITEM item)
{
    if (item != NULL)
    {
        printf("%s, %s, %s\n",
            item->regions->cCode,
            item->regions->rCode,
            item->regions->rName);
    }
}