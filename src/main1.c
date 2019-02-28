#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"
#define N 256
int main()
{

    PREGCODE head = NULL, prev = NULL, current = NULL;
    char buf[N];
    char tempCh = 0;                                      // временная переменная для хранения ответа пользователя

    FILE *fp = fopen("fips10_4.csv", "r");
    if(fp == NULL)
    {
        puts("File fp not found!");
        return 1;
    }

    while (fgets(buf, N, fp) != NULL)
    {
        current = (PREGCODE) malloc(sizeof(TREGCODE));
        if (head == NULL)
            head = current;
        else
            prev->next = current;
        current->next = NULL;
        createList(current, buf);
        prev = current;
    }

    printf("Введите 1 для поиска по коду, или 2 для поиска по названию региона\n");
    scanf("%d", &tempCh);
    if (tempCh == 2)
    {
        printf("Введите название региона, например Tula\n");
        scanf("%s", &buf);
        findByName(head, current, buf);
    }
    if (tempCh == 1)
    {
        printf("Введите код, например RU\n");
        scanf("%s", &buf);
        findByIso(head, current, buf);
    }

    fclose(fp);

    return 0;
}
