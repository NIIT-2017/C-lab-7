//Clab 7 task1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define SIZE_C 300


struct node
{
	unsigned int frequency = 0;
	char keyWord[SIZE];
	node* left = NULL;
	node* right = NULL;
};

node* create(char* anyWord);
node* add(node* currentNode, char* anyWord);
void search(node* currentNode, char* anyWord);
void printTree(node* currentNode);