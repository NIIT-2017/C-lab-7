//Clab 7 task3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node
{
	unsigned int frequency = 0;
	char keySym;
	node* left = NULL;
	node* right = NULL;
};

node* create(char symbol);
node* add(node* currentNode, char symbol);
void createArr(node* currentNode, node* arr[255]);
void sort(node* arr[255]);
void printTree(node* arr[255]);