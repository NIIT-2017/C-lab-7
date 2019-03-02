#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "task2.h"

void chomp (char * buf){
    if(buf[strlen(buf)-1] == '\n')
        buf[strlen(buf)-1] = '\0';
}

struct KEYWORD * buildTree(struct KEYWORD * root, char * buf){
    if(root == NULL){
        root = (struct KEYWORD *)malloc(sizeof(struct KEYWORD));
        strcpy(root->word, buf);
        root->count = 0;
        root->left = NULL;
        root->right = NULL;
    }else if (strcmp(root->word, buf) > 0){
        root->left = buildTree(root->left, buf);
    }else if (strcmp(root->word, buf) <= 0 ){
        root->right = buildTree(root->right, buf);
    }
    return root;
}

struct KEYWORD * searchTree(struct KEYWORD * root, char * buf){
    if(root == NULL)
        return root;
    if(strcasecmp(root->word, buf) == 0)
        return root;
    else if(strcasecmp(root->word, buf) > 0)
        return searchTree(root->left, buf);
    else
        return searchTree(root->right, buf);
}

void printTree (struct KEYWORD * root){
    if(root){
        printTree(root->right);
        if(root->count > 0)
            printf("Word '%s' is found %d\n", root->word, root->count);
        printTree(root->left);
        return;
    }
}
