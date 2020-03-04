#include "task1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE * fp;
    int count = 0;
    char buf[512];

    PITEM head = NULL, tail = NULL, item = NULL;
    fp = fopen("fips10_4.csv", "rt");
    if (fp == NULL)
    {
        printf("File open error!\n");
        return 1;
    }

    fgets(buf, 512, fp);

    while (fgets(buf, 512, fp))
    {
        if (count == 0)
        {
            head = createList(createName(buf));
            tail = head;
        }
        else
        {
            tail = addToTail(tail, createName(buf));
        }
        count++;
    }
    fclose(fp);
    
    char userCCode[3];
    char userRName[50];
    int choice;
    while (1)
    {
        printf("Search by country code - 1.\n");
        printf("Search by region - 2.\n");
        printf("Exit - 0.\n");

        scanf("%d", &choice);

        int c;
        do{
            c = getchar();
        } while (c != EOF && c != '\n');
        
        if (choice == 0)
            break;
        else if (choice < 0 || choice > 2)
            printf("Incorrect command!\n");
        else if (choice == 1)
        {
            printf("Enter two-letter country code:\n");
            fgets(userCCode, 3, stdin);
            findByCCode(head, userCCode);
        }
        else if (choice == 2)
        {
            printf("Enter region:\n");
            fgets(userRName, 50, stdin);
            if (userRName[strlen(userRName) - 1] = '\n')
                userRName[strlen(userRName) - 1] = '\0';
            item = findByRName(head, userRName);
            if (item == NULL)
                printf("Not found!\n");
            else
                printItem(item);
        }
    }
    return 0;
}