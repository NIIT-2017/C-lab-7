#include "task1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void chomp(char* string) {                       //delating symbol of end of string
    if (string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}


PITEM createList(PTERRITORY_REC letterDesignation_rec)
{
    PITEM item = (PITEM)malloc(sizeof(TITEM));
    item->letterDesignation_rec = letterDesignation_rec;
    item->prev = NULL;
    item->next = NULL;
    return item;
}

 PTERRITORY_REC createName(char* line)
{
     //for example AD,02,"Canillo"
    int i = 0;
    PTERRITORY_REC rec = (PTERRITORY_REC)malloc(sizeof(TTERRITORY_REC));
    while (*line && *line != ',')
        rec->letterDesignation[i++] = *line++;
    rec->letterDesignation[i] = 0;
    line++;
    i = 0;
    while (*line && *line != ',')
        rec->code[i++] = *line++;
        rec->code[i] = 0;
    line++;
    i = 0;
    while (*line)
        rec->countryName[i++] = *line++;
        rec->countryName[i] = 0;
    return rec;
}

PITEM addToTail(PITEM tail, PTERRITORY_REC letterDesignation_rec)
{
    PITEM item = createList(letterDesignation_rec);
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

PITEM findByLetterDesignation(PITEM head, char* letterDesignation)
{
    while (head)
    {
        if (strcmpi(head->letterDesignation_rec->letterDesignation, letterDesignation) == 0)
            return head;
        head = head->next;
    }
    return NULL;
}

PITEM findByCountryName(PITEM head, char* countryName)       // findByName(PITEM head, char* name)
{
    while (head)
    {
        if (strcmpi(head->letterDesignation_rec->countryName, countryName) == 0)
            return head;
        head = head->next;
    }
    return NULL;
}

void printLetterDesignation(PITEM item)
{
    if (item != NULL)
    {
       printf("iso 3166: %s, region code: %s, name: %s \n", item->letterDesignation_rec->letterDesignation, item->letterDesignation_rec->code, item->letterDesignation_rec->countryName);
    }
}

PITEM showSuitableCountries(PITEM head, char* letterDesignation) {
    PITEM item;
    while (head) {
        item = findByLetterDesignation(head, letterDesignation);
        if (item == NULL) {
            break;
        }
    printLetterDesignation(item);
    head = item->next;
    }
    return head;
}