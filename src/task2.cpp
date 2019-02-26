#include "task2.h"


PCOW makeTree(PCOW root, char *word)
{
	if (word[strlen(word) - 1] == '\n')
		word[strlen(word) - 1] = '\0';

	if (root == NULL)
	{
		root = (PCOW)malloc(sizeof(TCOW));

		strcpy(root->word, word);
		root->count = 0;
		root->left = root->right = NULL;
	}
	else if (strcmp(root->word, word) > 0)
		root->left = makeTree(root->left, word);
	else if (strcmp(root->word, word) < 0)
		root->right = makeTree(root->right, word);

	return root;
}

void searchTree(PCOW root, char *word)
{
	if (root == NULL)
	{
		return;
	}
	 else if (strcmp(root->word, word) > 0)
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
void printTree(PCOW root)
{
	if (root->left)
		printTree(root->left);
	printf("%s %d\n", root->word, root->count);
	if (root->right)
		printTree(root->right);
}