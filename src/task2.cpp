#define _CRT_SECURE_NO_WARNINGS
#include "task2.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void chomp(char* line)
{
	if (line[strlen(line) - 1] == '\n')
		line[strlen(line) - 1] = 0;
}

struct NODE* makeTree(struct NODE *root, char *word)
{
	if (root == NULL)
	{
		root = (struct NODE*)malloc(sizeof(struct NODE));
		strcpy(root->word, word);
		root->count = 0;
		root->left = NULL;
		root->right = NULL;
	}
	else if (strcmp(root->word, word) > 0)
		root->left = makeTree(root->left, word);
	else
		root->right = makeTree(root->right, word);

	return root;
}

struct NODE *searchTree(struct NODE *root, char *word)
{
	if (root == NULL)
		return NULL;
	if (strcmp(root->word, word) == 0)
		return root;
	if (strcmp(root->word, word) > 0)
		return searchTree(root->left, word);
	else
		return searchTree(root->right, word);
}

void printTree(struct NODE *root)
{
	if (root)
	{
		printTree(root->left);
		printf("%s - %d\n", root->word, root->count);
		printTree(root->right);
	}

	return;
}