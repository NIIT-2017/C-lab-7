#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 256

struct COW
{
	char word[M];
	int count;
	struct COW *left;
	struct COW *right;
};

typedef struct COW TCOW;
typedef TCOW* PCOW;

PCOW makeTree(PCOW root, char *word);
void searchTree(PCOW root, char *word); 
void printTree(PCOW root);