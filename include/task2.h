#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_SIZE 128
#define LETTER 1
#define NOTLETTER 0
#define OUTWORD 0
#define INTOWORD 1

struct TREE
{
    char word[WORD_SIZE];
    int count;
    struct TREE* right;
    struct TREE* left;
};

typedef struct TREE t_TREE;
typedef t_TREE* p_TREE;

p_TREE makeTREE(p_TREE root, char* word);
void searchTREE(p_TREE root, char* word);
void printTree(p_TREE root);
int check_ch(char ch);
void clean_buf(char* buf, int size);