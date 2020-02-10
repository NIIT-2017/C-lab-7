#include "task3.h"
#include <ctype.h>

void fillChart(SYM* chart)
{
    for (int i = 0; i < 256; i++)
    {
        chart[i].symbol = i;
        chart[i].frequency = 0;
        chart[i].count = 0;
    }
}

void printChart(SYM* chart)
{
    printf("\"CS\" - control symbol\n\"WS\" - white-space symbol\n");

    for (int i = 0; i < 256; i++)
    {
        if (chart[i].symbol == 0)
            printf("symbol #%3i : \"\\0\", frequency = %f\n", chart[i].symbol, chart[i].frequency);
        else if (chart[i].symbol == 9)
            printf("symbol #%3i : \"\\t\", frequency = %f\n", chart[i].symbol, chart[i].frequency);
        else if (chart[i].symbol == 10)
            printf("symbol #%3i : \"\\n\", frequency = %f\n", chart[i].symbol, chart[i].frequency);
        else if (isspace(chart[i].symbol))
            printf("symbol #%3i : \"WS\", frequency = %f\n", chart[i].symbol, chart[i].frequency);
        else if (iscntrl(chart[i].symbol))
            printf("symbol #%3i : \"CS\", frequency = %f\n", chart[i].symbol, chart[i].frequency);
        else
            printf("symbol #%3i :  \"%c\", frequency = %f\n", chart[i].symbol, chart[i].symbol, chart[i].frequency);
    }
}

void findOut(SYM* chart, FILE* fp)
{
    unsigned char c;
    int ch;
    long int counter = 0;
    while ((ch = fgetc(fp)) != EOF)
    {
        c = (unsigned char)ch;
        chart[c].count++;
        counter++;
    }
    for (int i = 0; i < 256; i++)
        chart[i].frequency = (float)chart[i].count / counter;
}

int compar(const void* p1, const void* p2)
{
    SYM* f1 = (SYM*)p1;
    SYM* f2 = (SYM*)p2;
    
    if (f1->frequency > (f2->frequency)) return -1;
    if (f1->frequency == (f2->frequency)) return 0;
    if (f1->frequency < (f2->frequency)) return 1;
}