#define _CRT_SECURE_NO_WARNINGS
#include "task1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE* fp;
    int count = 0;
    char buf[512];
    PITEM head = 0, tail = 0, item = 0;
    fp = fopen("fips10_4.csv", "rt");
    if (!fp) {
        perror("File fips10_4.csv:");
        exit(1);
    }
    fgets(buf, 512, fp); //первая строка-заголовок не формирует список
    printf("%s", buf);
    while (fgets(buf, 512, fp))
    {
        if (count == 0)
        {
            head = createList(createRegion(buf));
            tail = head;
        }
        else
        {
            tail = addToTail(tail, createRegion(buf));
        }
        count++;
    }
    fclose(fp);
    printf("Total items: %d\n", countList(head));
    
    item = findByCountry(head, (char*)"DE");
    if (item == NULL)
        printf("Not found!\n");
    else
    {
        findAllCountries(head, (char*)"DE");
    }
    item = findByName(head, (char*)"Bretagne");
    if (item == NULL)
        printf("Not found!\n");
    else
        printRegion(item);
    return 0;
}
