#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "task3.h"

int read(FILE* fp, SYM* syms)
{
    int ch = 0;
    int sum = 0;
    while (((ch = fgetc(fp)) != EOF))
    {
        syms[ch].ch = ch;
        syms[ch].freq += 1;
        sum += 1;
        //       printf("%c-%2.0f\n", syms[ch].ch, syms[ch].freq);
    }
    return sum;
}
void countFreq(int sum, SYM* syms)
{
    for (int i = 0; i < 256; i++)
    {
        syms[i].freq = syms[i].freq / sum;
    }

}
int cmp(const void* a, const void* b)
{
    if (((struct SYM*)a)->freq > ((struct SYM*)b)->freq)
        return -1;
    else
        return 1;
}