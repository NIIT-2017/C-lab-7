#include "task3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SYM* createTree(struct SYM*root, struct SYM item)
{
	if (root == NULL)
	{
		root = (struct SYM*)malloc(sizeof(struct SYM));
		root->symbol = item.symbol;
		root->count = item.count;
		root->freq = item.freq;
		root->left = root->right = NULL;
	}
	else if (root->freq > item.freq)
		root->left = createTree(root->left, item);
	else
		root->right = createTree(root->right, item);

	return root;
}

void printTree(struct SYM*root)
{
	if (root)
	{
		printTree(root->left);
		if ((root->freq) > 0)
			printf("Symbol: '%c' frequency : %5.3f%%\n", root->symbol, (root->freq) * 100);
		printTree(root->right);
	}
	

}