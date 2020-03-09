#include "task2.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char keyWords[30];
    char keyWordsInProg[256];
    PNODE root = NULL;
    FILE *fp = fopen("keywords.txt", "rt");
    if (!fp) {
        printf("Error!\n");
        return 1;
    }

    FILE* fp1 = fopen("kwinprog.txt", "rt");
        if (!fp1) {
            printf("Error!\n");
            return 1;
        }

    while (fgets(keyWords, 30, fp)) {
        chomp(keyWords);
        root = makeTree(root, keyWords);
    } 
    printTree(root);
    fclose(fp);

    while (fgets(keyWordsInProg, 256, fp1)) { 
      searchWords(keyWordsInProg, root);
    }
    printTree(root);
    fclose(fp1);

    return 0;
}
   