#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"

int main()
{
    FILE *fp;
    char userChoice;
    char str[20] = { '\0' };
    int count = 0;
    char buf[128];
    PITEM item, head = nullptr, tail = nullptr;
    fp = fopen("fips10_4.csv","rt");
    if(!fp)
    {
        perror("Error file");
        exit(1);
    }
    fgets(buf, 128, fp);
    while (fgets(buf, 128, fp))
    {
        if(count == 0)
        {
            head = creatList(creatCountries(buf));
            tail = head;
        }
        else
        {
            tail = addToTail(tail, creatCountries(buf));
        }
        count++;
    }
    fclose(fp);
    printf("Total items: %d\n", countList(head));
    printf("Press N to find name\n");
    printf("Press C to find code\n");
    scanf("%c", &userChoice);
    if(userChoice == 'N'){
        scanf("%s", str);
        item = findByCountry(head, str);
        if(item == NULL)
            printf("Not found!\n");
        else
            printCountry(item);
        for(int i = 0; i<20; i++)
            str[i] = '\0';
    }
    if(userChoice == 'C')
    {
        scanf("%s", str);
        findByCode(head, str);
    }
    return 0;
}
