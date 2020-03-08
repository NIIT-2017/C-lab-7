#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task2.h"

int main(int argc, char** argv)
{
    FILE* fp;
    char buf[256];
    char word[70];
    PNODE root = NULL;
    fp = fopen("words.txt", "rb");
    if (!fp) {
        perror("File words.txt:");
        exit(1);
    }
    while (fscanf(fp, "%s", buf) == 1)
        root = makeTree(root, buf);
    fclose(fp);
    root = balanceTree(root);
    printf(" root is %s*\n", root);
    printf(" height of the Tree is %d*\n", height(root));
    fp = fopen(argv[1], "rt");
    if (!fp) {
        perror("File: ");
        return 1;
    }
    while (fgets(buf, 255, fp))
    {
        chomp(buf);
        read(root, buf);
    }
    printTree(root);
    return 0;
}