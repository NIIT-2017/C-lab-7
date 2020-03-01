#include "task3.h"

int main() {
    setlocale(LC_ALL, "russian");

    SSYM sym[LEN];
    char ch;
    unsigned long total = 0;

    FILE* fp = fopen("Doyle Arthur. A Study in Scarlet.txt", "rt");
    if (fp == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        total++;
    }

    printf("Общее количество символов: %lu\n", total);

    rewind(fp);

    while ((ch = fgetc(fp)) != EOF)
        sym[ch].count++;

    for (int i = 0; i < LEN; i++) {
        sym[i].freq = (float)(sym[i].count) / (float)total;
        sym[i].ch = i;
    }
    fclose(fp);

    printSYM(sym);
    sortSYM(sym);
    printf("\n");
    printf("Отсортированные данные:\n");
    printSYM(sym);

    return 0;
}
