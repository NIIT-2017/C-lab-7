#include "task3.h"

void sortSYM(SSYM sym[LEN]) {
    SSYM tmp;
    int i = 0;
    for (int i = 0; i < LEN - 1; i++) {
        for (int j = i; j < LEN; j++) {
            if (sym[i].freq < sym[j].freq) {
                tmp = sym[i];
                sym[i] = sym[j];
                sym[j] = tmp;
            }
        }
        
    }
}
 
void printSYM(SSYM sym[LEN]) {
    for (int i = 0; i < LEN; i++) {
        if (sym[i].ch && sym[i].freq) {
            printf("%c - %d - %.5f%%\n", sym[i].ch, sym[i].ch, (sym[i].freq * 100));
        }
     }
}