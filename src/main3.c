#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task3.h"

int main (int argc, char *argv[])
{
    FILE *fp;                                  // указател на файл
    fp = fopen(argv[1],"rb");                  // открываем исходный файл
    int tempCh = 0;                            // в эту переменную читается информация из файла
    int count = 0;                             // счётчик количества уникальных символов
    int globalCount = 0;                       // счётчтк количества всех символов в файле
    int quantity[256] = {0};                   // инициализируем массив количества уникальных символов
    struct SYM symbols[256] = {0};             // инициализируем массив структур типа SYM
    struct SYM *psym[256] = {0};               // инициализируем массив указателей на структуры типа SYM
    float sumFreq = 0;                         // сумма частот встречаемости


    if(argc != 2)
    {
        printf("Имя нужного файла: %s \n", argv[0]);
        return 1;
    }


    if((fp = fopen(argv[1],"rb")) == NULL)     // исключение ошибки чтения/нахождения файла
    {
        puts("File not found!");
        return 1;
    }

    while((tempCh=fgetc(fp))!=EOF)             // пока не достигнем конца файла, идём по нему и составляем таблицу встречаемости
    {
        for(int j = 0; j < 256; j++)
        {
            if (tempCh == symbols[j].ch)
            {
                quantity[j]++;
                globalCount++;
                break;
            }
            if (symbols[j].ch == 0)
            {
                symbols[j].ch=(unsigned char)tempCh;
                quantity[j]=1;
                count++; globalCount++;
                break;
            }
        }
    }


    for(int i = 0; i < count; i++)                          // определяем частоты встречаемости
        symbols[i].freq=(float)quantity[i]/globalCount;

    for(int i = 0; i<count; i++)                            // в массив указателей заносим адреса структур
        psym[i] = &symbols[i];


    struct SYM sort;                                        // сортировка по убыванию
    for(int i = 1; i < count; i++)
        for(int j = 0; j < count-1; j++)
            if(symbols[j].freq<symbols[j+1].freq)
            {
                sort=symbols[j];
                symbols[j]=symbols[j+1];
                symbols[j+1]=sort;
            }

    for(int i = 0; i < count; i++)                         // выводим таблицу встречаемости на печать
    {
        sumFreq += symbols[i].freq;
        printf("ASCII= %d\tSymbol= '%c'\t\tFreq= %f\n", symbols[i].ch, psym[i]->ch, symbols[i].freq);
    }
        printf("\nAll symbols= %d\tSumFreq=%f\n", globalCount, sumFreq);

        return 0;
}
