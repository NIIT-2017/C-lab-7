#define _CRT_SECURE_NO_WARNINGS
#include "task2.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstring>


PWT makeTree(PWT root, char *word)
{
	if (word[strlen(word) - 1] == '\n')
		word[strlen(word) - 1] = '\0';

	if (root == NULL)
	{
		root = (PWT)malloc(sizeof(TWT));
		strcpy(root->word, word);
		root->count = 0;
		root->left = NULL;
		root->right = NULL;
	}
	if (strcmp(root->word, word) > 0)
		root->left = makeTree(root->left, word);
	if (strcmp(root->word, word) < 0)
		root->right = makeTree(root->right, word);
	return root;
}

void searchTree(PWT root, char *word)
{
	if (root == NULL)
	{
		return;
	}
	if (strcmp(root->word, word) > 0)
	{
		root = root->left;
		searchTree(root, word);
	}
	else if (strcmp(root->word, word) < 0)
	{
		root = root->right;
		searchTree(root, word);
	}
	else
		root->count++;
}

void printTree(PWT root)
{
	if (root->left)
		printTree(root->left);
	printf("%s %d\n", root->word, root->count);
	if (root->right)
		printTree(root->right);
}