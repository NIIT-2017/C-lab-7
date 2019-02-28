#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task2.h"


struct NODE * makeTree(struct NODE *root,char *word)
{
    if(root==NULL)
    {
        struct NODE *temp=(struct NODE*)malloc(sizeof(struct NODE));
        temp->count=1;
        strcpy(temp->word,word);
        temp->left=temp->right=NULL;
        return temp;
    }
    else if(strcmp(root->word,word)>0)
    {
        root->left=makeTree(root->left,word);
        return root;
    }
    else if(strcmp(root->word,word)<0)
    {
        root->right=makeTree(root->right,word);
        return root;
    }
    else
    {
        root->count++;
        return root;
    }
}

struct NODE * searchTree(struct NODE *root,char *word)
{
    while(root)
    {
      if(strcmp(root->word, word) == 0)
          return root;
      if(strcmp(root->word, word) > 0)
          return searchTree(root->left, word);
      else return searchTree(root->right, word);
    }
    return NULL;  // подходящий элемент не найден
}

void printTree(struct NODE *root)
{
    if(root)
    {
        if(root->left)
            printTree(root->left);
        printf("%s - %d\n",root->word,root->count);
        if(root->right)
            printTree(root->right);
    }
}

void chomp(char * string)                       // - удаление символа конца строки
{
    if (string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = '\0';
}
