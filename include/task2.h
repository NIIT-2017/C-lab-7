#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define maxWord 50

struct wordsTree
{
	char word[maxWord];
	int count;
	struct wordsTree *left;
	struct wordsTree *right;
};

struct wordsTree * makeTree(
	struct wordsTree * (*pFun)(struct wordsTree * node, char * buf),
	const char*fileName, struct wordsTree * root);

struct wordsTree * addWord(struct wordsTree * node, char * buf);
struct wordsTree * statWord(struct wordsTree * node, char * buf);

void printTree(struct wordsTree *node);
int freeMemTree(struct wordsTree *node);