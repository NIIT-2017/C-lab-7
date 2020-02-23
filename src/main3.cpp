#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "task3.h"


int main() {
    char text[256];
    struct SYM table[256];
    FILE* fp = fopen("toRead.txt", "rt");
    if (!fp) {
        printf("Error!\n");
        return 1;
    }
    long len = 0;
    fseek(fp, 0L, SEEK_END);
    len = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    initializeTable(table, text, len);
    
    while (fgets(text, 256, fp)) {
        chomp(text);
        makeTable(table, text, len);
    }
    qsort(table, 256, sizeof(SYM), cmp);
    printTable(table);
  
    return 0;
}