#include "task2.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void chomp (char * line)
{
	if (line[strlen(line) - 2] == ' ')
	{
		line[strlen(line) - 2] = '\0';
	}
	 if (line[strlen(line) - 1] == '\n')
	{
		line[strlen(line) - 1] = '\0';
	}	
}

struct tnode * makeTree(struct tnode*tree, char *word)
{
	if (tree == NULL)
	{
		tree = (struct tnode*)malloc(sizeof(struct tnode));
		strcpy(tree->word, word);
		tree->left = NULL;
		tree->right = NULL;
		tree->count = 0;
		
	}
	else if (strcmp(tree->word, word) > 0)
		tree->left = makeTree(tree->left, word);
	else
		tree->right = makeTree(tree->right, word);
	return tree;		
}

struct tnode *searchTree(struct tnode*tree, char *word)
{
	if (tree == NULL)
		return NULL;
	if (strcmp(tree->word, word) == 0)
	{
		tree->count++;
		return tree;
	}
	if (strcmp(tree->word, word) > 0)
		return searchTree(tree->left, word);
	else
		return searchTree(tree->right, word);
	return tree;
}

void printTree(struct tnode *p)
{
	if (p != 0)
	{
		printTree(p->left);
		printf("%s %d\n", p->word, p->count);
		printTree(p->right);
	}
}
