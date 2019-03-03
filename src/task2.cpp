#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task2.h"

int max = 0;

struct NODE *makeTree(struct NODE *root, char *word)
{
	if (root == NULL)
	{
		struct NODE *temp = (struct NODE*)malloc(sizeof(struct NODE));
		strcpy(temp->word, word);
		temp->count = 0;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	else if (strcmp(root->word, word) > 0)
	{
		root->left = makeTree(root->left, word);
		return root;
	}
	else if (strcmp(root->word, word) < 0)
	{
		root->right = makeTree(root->right, word);
		return root;
	}
	else
		root->count++;
	return root;
}

void searchTree(struct NODE *root, char *buf)
{
	if (root)
	{
		searchTree(root->left, buf);
		if (strcmp(root->word, buf) == 0)
			root->count++;
		searchTree(root->right, buf);
	}
}

int searchMax(struct NODE *root)
{
	if (root)
	{
		searchMax(root->left);
		if (max < root->count)
			max = root->count;
		searchMax(root->right);
	}
	return max;
}

void printTree(struct NODE *root)
{
	if (root)
	{
		printTree(root->left);
		if (max == root->count)
			printf("%d - %s\n", root->count, root->word);
		printTree(root->right);
	}
}