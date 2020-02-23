#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "task2.h"

void chomp(char* string) {                       //delating symbol of end of string
    if (string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}                                    

PNODE makeTree(PNODE root, char* word) {                    
    if (root == NULL) {
        root = (PNODE)malloc(sizeof(TNODE));
        strcpy(root->word, word);
        root->count = 0;
        root->left = NULL;
        root->right = NULL;
    }
    else if (strcmp(root->word, word) > 0) {  //new word is smaller  
        root->left = makeTree(root->left, word);
    }
    else if (strcmp(root->word, word) < 0) {
        root->right = makeTree(root->right, word);
    }
    return root;
}     

PNODE searchTree(PNODE root, char* word) {  
    if (root == NULL) {
        return NULL;
    }
    else if (strcmp(root->word, word) > 0) {
       return searchTree(root->left, word);
    }
    else if (strcmp(root->word, word) < 0) {
        return searchTree(root->right, word);
    }
    else root->count++;
    return root;
}   

void printTree(PNODE root) {
    if (root->left) {
        printTree(root->left);
    } 
    printf("%s, %4d\n", root->word, root->count);
    if (root->right) {
        printTree(root->right);
    }
}

void searchWords(char *str, PNODE kwtree) {
    char arr[256];
    int i = 0;
    int inWord = 0;
    while (*str) {
        if (isalpha(*str) && inWord == 0) {     
            arr[i] = *str;                    
            i++;
            inWord = 1;
        }
        else if (isalpha(*str) && inWord == 1) {
            arr[i] = *str;
            i++;
        }

        else if (!isalpha(*str) && inWord == 1) {
            inWord = 0;
            arr[i] = '\0';
            searchTree(kwtree, arr);
            i=0;                                       //Rewriting previous symbols by symbols of next word
        }
        str++;                                   
    }
}
