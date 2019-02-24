#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task2.h"

void printTree(PKEYWORD root)
{
	if (root->left)
		printTree(root->left);
	printf("%d - %s\n", root->freq, root->word);
	if (root->right)
		printTree(root->right);
}

PKEYWORD makeTree(PKEYWORD root, char * word)	//building tree on the basis of C-keywords file
{
	if (root == NULL)							//if there is no tree
	{
		root = (PKEYWORD)malloc(sizeof(KEYWORD));
		strcpy(root->word, word);
		root->freq = 0;
		root->left = NULL;						//because it is first element in the tree
		root->right = NULL;						//because it is first element in the tree
	}
	else if (strcmp(root->word, word) > 0) 
	{
		root->left = makeTree(root->left, word);
	}
	else 
	{
		root->right = makeTree(root->right, word);
	}
	return root;
}

void chomp(char * string) 
{
	if (string[strlen(string) - 1] == '\n')
	{
		string[strlen(string) - 1] = '\0';
	}
	return;
}


PKEYWORD searchTree(PKEYWORD root, char * word)
{
	while (strcmp(root->word, word) != 0)	//while we don't find the keyword
	{
		if (strcmp(root->word, word) > 0)
			root = root->left;
		else
			root = root->right;
		if (NULL == root)
			return NULL;					//we did not find the element
	}
	root->freq = root->freq + 1;			//increasing the frequency
	return root;
}
