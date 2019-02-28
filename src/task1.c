#include <stdio.h>
#include <string.h>
#include "task1.h"

void createList(PREGCODE current, char *buf)
{
    int i = 0, j;
    for(j = 0; buf[i] != ','; i++)
    {
        if(buf[i] != '\"')
        {
            current->iso[j] = buf[i];
            j++;
        }
    }
    current->iso[j] = '\0';
    i++;

    for(j = 0; buf[i] != ','; i++)
     {
         if(buf[i] != '\"')
         {
             current->code[j] = buf[i];
             j++;
         }
     }
     current->code[j] = '\0';
     i++;

     for(j = 0; buf[i] != '\0';i++)
     {
         if (buf[i] != '\"')
         {
             current->name[j] = buf[i];
             j++;
         }
     }
     current->name[j] = '\0';
}

void findByName(PREGCODE head, PREGCODE current, char *name)
{

    current = head;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
            printf("%s,%s,%s\n", current->name, current->iso, current->code);
        current = current->next;
    }
}

void findByIso(PREGCODE head, PREGCODE current, char *iso)
{
    current = head;
    while (current != NULL)
    {
        if (strcmp(current->iso, iso) == 0)
            printf("%s,%s,%s\n", current->iso, current->code, current->name);
        current = current->next;
    }
}
