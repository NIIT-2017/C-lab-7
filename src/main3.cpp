#include "task3.h"
#include <stdio.h>
#include <algorithm>
int main()
{
    printf("Enter file name");
    char fileName[20];
    scanf("%s", fileName);
    FILE* inputFile = fopen(fileName, "r");
    if (!inputFile)
        printf("File couldn't open");
    int symbolsAllCount=0,symbolsCount[128];
    for (int i = 0; i < 128;i++)
    {
        symbolsCount[i] = 0;
    }
    char buf;
    while (!feof(inputFile))
    {
        fscanf(inputFile, "%c", &buf);
        symbolsCount[buf]++;
        symbolsAllCount++;
    }
    SYM symbols[128];
    for (int i = 0; i < 128; i++)
    {
        symbols[i].symbol = i;
        symbols[i].frequency =((float)symbolsCount[i] / (float)symbolsAllCount);
    }
    qsort(symbols, 128, sizeof(SYM), comparetor);
    for (int i = 0; i < 128; i++)
    {
        printf("\n%c %f", symbols[i].symbol, symbols[i].frequency);
    }
}