#include "task3.h"
#include <stdio.h>

void initData(TSYM data[SIZE])
{
    FILE * fp = fopen("text.txt", "rt");
    if (fp == NULL)
    {
        printf("File open error!\n");
        return;
    }
    char sym;
    long total = 0;
    while ((sym = fgetc(fp)) != EOF)
    {
        data[sym].count++;
        total++;
    }
    for (int i = 0; i < SIZE; i++)
    {
        data[i].frequency = (float)(data[i].count) / total;
        data[i].ch = i;
    }
    fclose(fp);
}

void sortData(TSYM data[SIZE])
{
    TSYM tmp;
    for (int i = 0; i < SIZE; i++)
    {
        int j = i;
        while (j > 0 && data[j - 1].frequency < data[j].frequency)
        {
            tmp = data[j - 1];
            data[j - 1] = data[j];
            data[j] = tmp;
            j--;
        }
    }
}

void printData(TSYM data[SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        if (data[i].ch && data[i].frequency)
            printf("%c - %.0f%%\n", data[i].ch, (data[i].frequency) * 100);
    }
}