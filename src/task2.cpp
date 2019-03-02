#include "task2.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


PNODE makeTree(PNODE root, char *word)
{
	if (root == NULL)
	{
		root = (PNODE)malloc(sizeof(NODE));

		strcpy(root->word, word);
		root->freq = 0;
		root->left = NULL;
		root->right = NULL;
	}
	
	else if (strcmp(root->word, word) > 0)
		root->left = makeTree(root->left, word);

	else 
		root->right = makeTree(root->right, word);

	return root;
}

PNODE searchTree(PNODE root,char * word)
{
	if (root == NULL)
	{
		return 0;
	}
	if (strcmp(root->word, word) == 0)
	{
		root->freq++;
		return root;
	}
	
	if (strcmp(root->word, word) > 0)
		return searchTree (root->left, word);
	else  
		return searchTree(root->right, word);
}

void printTree(PNODE root)
{
	if (root->left)
		printTree(root->left);
	printf("%s-%d\n", root->word,root->freq);
	if (root->right)
		printTree(root->right);
}

void chomp(char * line)
{
	if (line[strlen(line) - 1] == '\n')
		line[strlen(line) - 1] = '\0';
}