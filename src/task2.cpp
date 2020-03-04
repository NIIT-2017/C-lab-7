#include "task2.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void chomp(char * str)
{
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
}

PNODE makeTree(PNODE root, char * word)
{
    if (root == NULL)
    {
        root = (PNODE)malloc(sizeof(TNODE));
        strcpy(root->word, word);
        root->count = 0;
        root->left = root->right = NULL;
    }
    else if (strcmp(root->word, word) > 0)
        root->left = makeTree(root->left, word);
    else if (strcmp(root->word, word) < 0)
        root->right = makeTree(root->right, word);
    else
        root->count++;
    return root;
}

PNODE searchTree(PNODE root, char * word)
{
    while (root)
    {
        if (root == NULL)
            return root;
        if (strcmp(root->word, word) == 0)
        {
            root->count++;
            break;
        }
        else if (strcmp(root->word, word) > 0)
            return searchTree(root->left, word);
        else if (strcmp(root->word, word) < 0)
            return searchTree(root->right, word);
    }
    return root;
}

void printTree(PNODE root)
{
    if (root->left)
        printTree(root->left);
    printf("%s - %d\n", root->word, root->count);
    if (root->right)
        printTree(root->right);
}