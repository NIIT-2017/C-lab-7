#ifndef TASK2_H
#define TASK2_H

#define SIZE 200

typedef struct KEYWORD
{
	char word[SIZE];
	int freq;
	struct KEYWORD* left;
	struct KEYWORD* right;
}KEYWORD;

KEYWORD * AddWordToTree(KEYWORD * root, char * word);
void printTree(KEYWORD * root);
void chomp(char * string);
KEYWORD * searchTree(KEYWORD * root, char * word);

#endif