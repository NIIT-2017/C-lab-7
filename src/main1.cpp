#include "task1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE* fp;
    int count = 0;
    char buf[512];
    PITEM head, tail, item;
    fp = fopen("File1.csv", "rt");
    if (!fp) {
        perror("File file1.csv");
        exit(1);
    }


    fgets(buf, 512, fp);
    while (fgets(buf, 512, fp))
    {
        chomp(buf);
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
    printf("Total items: %d\n", countList(head));
    item = showSuitableCountries(head, (char*)"AR");
    if (item == NULL)
        printf("Not found!\n");
    item = findByCountryName(head, (char*)"\"Castilla-La Mancha\"");
    if (item == NULL)
        printf("Not found!\n");
    else
        printLetterDesignation(item);
    return 0;
}