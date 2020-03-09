#include <stdio.h>
#define MAXWORD 32

typedef struct keyWord // обьявляем новый тип структуру
{
	char word[MAXWORD];
	short count;
	struct keyWord* left;
	struct keyWord* right;
}keyWordST;

keyWordST* makeTree(FILE* fp);
keyWordST* createStruct(char bufer[]);
void chomp(char bufer[]);
void searchTree(keyWord* keyList, const char bufer[]);
void sourceCodeAnaliz(FILE* fp, keyWord* keyList);
void printTree(keyWord* keyList);

void deleteTree(keyWordST* keyList);