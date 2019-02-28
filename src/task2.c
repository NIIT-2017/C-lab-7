#define _CRT_SECURE_NO_WARNINGS
#include "task2.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

PNODE makeTree(PNODE root, char *word)
{
	if (root == NULL)
	{
		root = (PNODE)malloc(sizeof(TNODE));

		strcpy(root->word, word);
		root->count = 0;
		root->left = root->right = NULL;
	}
	else if (strcmp(root->word, word) > 0)
		root->left = makeTree(root->left, word);
	else if (strcmp(root->word, word) < 0)
		root->right = makeTree(root->right,	word);
	
	return root;
}

void searchTree(PNODE root, char *word)
{
	
	if (strcmp(root->word, word) == 0)
		root->count++;
	if (root->left)
		searchTree(root->left, word);
	if (root->right)
		searchTree(root->right, word);
}

void printTree(PNODE root)
{
	if (root->count > 0)
		printf("%s-%lu\n", root->word, root->count);
	if (root->left)
		printTree(root->left);
	if (root->right)
		printTree(root->right);
}