#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "task2.h"

char* chomp(char* buf)
{
    if (buf != NULL && (strlen(buf) - 1) >= 0 && buf[strlen(buf) - 1] == '\n')
        buf[strlen(buf) - 1] = 0;

    return buf;
}

char* giveWord(char** str, char* word)
{
    int i = 0;
    char* pc = *str;
    while (!isalpha(*pc) && *pc != 0)
        pc++;
    while (isalpha(*pc))
        word[i++] = *pc++;
    word[i] = 0;
    *str = pc;
    return word;
}

void searchTree(char* buf, keyWord* item)
{
    if (!strcmp(item->word, buf))
        item->count++;
    else if (strcmp(item->word, buf) < 0)
    {
        if (item->right != NULL)
            searchTree(buf, item->right);
    }
    else
        if (item->left != NULL)
            searchTree(buf, item->left);
}

keyWord* addTree(char* buf, keyWord* item)
{
    if (item == NULL)
    {
        item = (keyWord*)malloc(sizeof(keyWord));
        if (item == NULL)
        {
            printf("malloc error\n");
            return NULL;
        }
        strcpy(item->word, buf);
        item->count = 0;
        item->left = NULL;
        item->right = NULL;
        return item;
    }
    else if (strcmp(item->word, buf) < 0)
    {
        if (item->right == NULL)
            item->right = addTree(buf, item->right);
        else
            addTree(buf, item->right);
    }
    else
        if (item->left == NULL)
            item->left = addTree(buf, item->left);
        else
            addTree(buf, item->left);
    return item;
}

keyWord* makeTree(keyWord* root, FILE* fp)
{
    char buf[20];

    while (fgets(buf, 20, fp) != NULL)
    {
        chomp(buf);
        if (root == NULL)
            root = addTree(buf, root);
        else
            addTree(buf, root);
    }

    return root;
}

void cleanTree(keyWord* item)
{
    if (item->left != NULL)
        cleanTree(item->left);
    if (item->right != NULL)
        cleanTree(item->right);
    free(item);
}

void printTree(keyWord* item)
{
    if (item->left != NULL)
        printTree(item->left);
    printf("%10s: %i\n", item->word, item->count);
    if (item->right != NULL)
        printTree(item->right);
}

void analise(FILE* fp, keyWord* root)
{
    char str[500];
    char word[30] = {0};
    char* pc;
    while (fgets(str, 500, fp) != NULL)
    {
        pc = str;
        while (*giveWord(&pc, word))
            searchTree(word, root);
    }
}