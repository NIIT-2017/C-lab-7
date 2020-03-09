//Clab 7 task2

#include "task2.h"

node* create(char* anyWord)
{
	node* root = (node*)malloc(sizeof(node));
	strcpy(root->keyWord, anyWord);
	root->left = NULL;
	root->right = NULL;

	return root;
}

node* add(node* currentNode, char* anyWord)
{
	if (currentNode == NULL)
	{
		currentNode = (node*)malloc(sizeof(node));
		currentNode->left = NULL;
		currentNode->right = NULL;
		currentNode->frequency = 0;
		strcpy(currentNode->keyWord, anyWord);
	}

	else if (strcmp(currentNode->keyWord, anyWord) < 0)
	{
		currentNode->left = add(currentNode->left, anyWord);
	}

	else if (strcmp(currentNode->keyWord, anyWord) > 0)
	{
		currentNode->right = add(currentNode->right, anyWord);
	}

	return currentNode;
}

void search(node* currentNode, char* anyWord)
{
	if (strcmp(currentNode->keyWord, anyWord) == 0)
		currentNode->frequency++;

	else if (strcmp(currentNode->keyWord, anyWord) < 0 && currentNode->left != NULL)
		search(currentNode->left, anyWord);

	else if (strcmp(currentNode->keyWord, anyWord) > 0 && currentNode->right != NULL)
		search(currentNode->right, anyWord);
}

void printTree(node* currentNode)
{
	if (currentNode->left != NULL)
		printTree(currentNode->left);

	if (currentNode->right !=NULL)
		printTree(currentNode->right);

	printf("%s\t%u\n", currentNode->keyWord, currentNode->frequency);
}

