#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task2.h"

KEYWORD * AddWordToTree(KEYWORD * root, char * word)
{
	if (root == NULL)
	{
		root = (KEYWORD *)malloc(sizeof(KEYWORD));
		strcpy(root->word, word);
		root->freq = 0;
		root->left = NULL;
		root->right = NULL;
	}
	else
	if (strcmp(root->word, word) > 0)
		root->left = AddWordToTree(root->left, word);
	else
		root->right = AddWordToTree(root->right, word);
	return root;
}

KEYWORD * searchTree(KEYWORD * root, char * word)
{
	if (!root)
		return 0;
	if (strcmp(root->word, word) == 0)
		return root;
	if (strcmp(root->word, word) > 0)
		return searchTree(root->left, word);
	else
		return searchTree(root->right, word);
}

void printTree(KEYWORD * root)
{
	if (root)
	{
		printTree(root->left);
		printf("Word: '%s'\tFreq: %d\n", root->word, root->freq);
		printTree(root->right);
	}
}

void chomp(char * string)
{
	if (string[strlen(string) - 1] == '\n')
		string[strlen(string) - 1] = '\0';
}