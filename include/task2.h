#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <clocale>

#define MAX_LEN 1024
#define BUF 256
#define Q 64

struct NODE {
	char word[BUF];
	unsigned long count;
	struct NODE* left;
	struct NODE* right;
};

typedef struct NODE SNODE;
typedef SNODE* PNODE;

char* chomp(char* str);
//PNODE chomp(PNODE root);
PNODE makeTree(PNODE root, char* word);
void searchTree(PNODE root, char* word);
void printTree(PNODE root);
