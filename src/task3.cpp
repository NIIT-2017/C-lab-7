#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task3.h"

void filling(SYM * buf, char * file)
{
	char ch;
	int totalCount = 0;
	FILE * fp;

	fp = fopen(file, "r");

	while ((ch = fgetc(fp)) != EOF)
	{
		buf[(int)ch].count++;
		totalCount++;
	}

	for (int i = 0; i < 256; i++)
	{
		buf[i].ch = (char)i;
		buf[i].freq = (float)(buf[i].count) / totalCount;
	}

	fclose(fp);

	return;
}

struct SYM * Node(struct SYM * root, struct SYM node)
{
	if (root == NULL)
	{
		root = (struct SYM*)malloc(sizeof(struct SYM));
		root->ch = node.ch;
		root->count = node.count;
		root->freq = node.freq;
		root->left = NULL;
		root->right = NULL;
	}

	else if (root->freq > node.freq)
		root->left = Node(root->left, node);
	else
		root->right = Node(root->right, node);

	return root;
}

struct SYM * buildTree(struct SYM buf[256])
{
	struct SYM * root = NULL;

	for (int i = 0; i < 256; i++)
	{
		root = Node(root, buf[i]);
	}
	return root;
}

void printTree(struct SYM * root)
{
	if (root)
	{
		printTree(root->right);
		if (root->freq > 0)
			printf("Symbol '%c' - repeated: %f\n", root->ch, root->freq);
		printTree(root->left);
		return;
	}
}
