#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "task3.h"
#define SIZE 256

int main(int argc, char* argv[])
{
    FILE* fp = fopen(argv[1], "rb");
    if (!fp)
    {
        perror("File:");
        exit(1);
    }
    int sum = 0; // общее количество символов в файле
    struct SYM syms[SIZE] = { 0 };
    struct SYM* psyms[SIZE] = { NULL };
    sum = read(fp, syms);
    fclose(fp);
    countFreq(sum, syms);
    qsort(syms, SIZE, sizeof(struct SYM), cmp);
    for (int i = 0; syms[i].freq > 0; i++)
        printf("%c - %1.2f%%\n", syms[i].ch, syms[i].freq);
    return 0;
}