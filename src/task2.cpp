#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task2.h"

void  chomp(char* str)
{
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
}

void read(PNODE root, char* buf)
{
    char word[64];
    int len = strlen(buf);
    for (int i = 0, j = 0; i < len; i++)
    {
        if (buf[i] != ' ' && buf[i] >= 'a' && buf[i] <= 'z')
        {
            word[j] = buf[i];
            j++;
        }
        else
        {
            word[j] = '\0';
            searchTree(root, word);
            j = 0;
        }
    }
    return;
}

PNODE makeTree(PNODE root, char* word)
{
    if (root == NULL)
    {
        root = (PNODE)malloc(sizeof(TNODE));

        strcpy(root->word, word);
        root->count = 0;
        root->left = root->right = NULL;
    }
    else if (_strcmpi(root->word, word) > 0)
        root->left = makeTree(
            root->left, word);
    else if (_strcmpi(root->word, word) < 0)
        root->right = makeTree(
            root->right, word);
    return root;
}
PNODE searchTree(PNODE root, char* word)
{
    if (root == NULL)
    {
        printf("not found");
        return NULL;
    }
    if (_strcmpi(root->word, word) == 0)
    {
        root->count++;
        return root;
    }
    if (_strcmpi(root->word, word) > 0)
    {
        if (root->left != NULL)
            return searchTree(root->left, word);
        else
            return NULL;
    }
    if (_strcmpi(root->word, word) < 0)
    {
        if (root->right != NULL)
            return searchTree(root->right, word);
        else
            return NULL;
    }
}

void printTree(PNODE root)
{
    if (root->left)
        printTree(root->left);
    printf("%s-%lu\n", root->word,
        root->count);
    if (root->right)
        printTree(root->right);
}

int height(PNODE root) // ń÷čňŕĺň đŕçíčöó âűńîň
{
    struct NODE* temp = root;
    int countleft = 0, countright = 0;
    {
        while (temp->right != NULL)
        {
            countright++;
            temp = temp->right;
        }
        temp = root;
        while (temp->left != NULL)
        {
            countleft++;
            temp = temp->left;
        }
        return(countleft - countright);
    }
}

PNODE turnLeft(PNODE root) //ďîâîđîň äĺđĺâŕ âëĺâî
{
    PNODE newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    return newRoot;
}

PNODE turnRight(PNODE root) //ďîâîđîň äĺđĺâŕ âďđŕâî
{
    PNODE newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    return newRoot;
}

PNODE balanceTree(PNODE root) // áŕëŕíńčđîâęŕ äĺđĺâŕ
{
    PNODE newRoot = root;
    if (height(newRoot) >= (-1) && height(newRoot) <= 1)
        return newRoot;
    else if (height(newRoot) < (-1))
        newRoot = turnLeft(newRoot);
    else if (height(newRoot) > 1)
        newRoot = turnRight(newRoot);
    balanceTree(newRoot);
}