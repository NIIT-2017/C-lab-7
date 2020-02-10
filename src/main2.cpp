#include <stdio.h>
#include "task2.h"

int main()
{
    keyWord* root = NULL;
    FILE* fp = NULL;
    fp = fopen("KeyWords.txt", "rt");
    root = makeTree(root, fp);
    fclose(fp);

    fp = fopen("programm.txt", "rt");
    analise(fp, root);
    fclose(fp);
    printTree(root);

    cleanTree(root);

    return 0;
}