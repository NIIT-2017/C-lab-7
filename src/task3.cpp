#define _CRT_SECURE_NO_WARNINGS
#include "task3.h"
#include <stdio.h>
#include <stdlib.h>

void fillArr(struct SYM arr[256], char *filename)
{
	FILE *fp;
	char ch;
	int count = 0;
	fp = fopen(filename, "rt");
	while ((ch = fgetc(fp)) != EOF)
	{
		arr[(int)ch].count++;
		count++;
	}
	fclose(fp);
	for (int i = 0; i < 256; i++)
	{
		arr[i].freq = (float)(arr[i].count) / count;
		arr[i].symbol = (char)i;
	}
	return;
}

struct SYM *createTree(struct SYM arr[256])
{
	struct SYM *root = nullptr;
	for (int i = 0; i < 256; i++)
		root = addNode(root, arr[i]);
	return root;
}

struct SYM *addNode(struct SYM *root, struct SYM item)
{
	if (root == NULL)
	{
		root = (struct SYM*)malloc(sizeof(struct SYM));
		root->symbol = item.symbol;
		root->freq = item.freq;
		root->count = item.count;
		root->right = NULL;
		root->left = NULL;

	}
	else if (root->freq > item.freq)
		root->left = addNode(root->left, item);
	else
		root->right = addNode(root->right, item);

	return root;
}

void printTree(struct SYM *root)
{
	if (root) {
		printTree(root->left);
		if (root->freq>0)
			printf("Symbol: '%c' frequency :%5.3f%%\n", root->symbol, (root->freq)*100);
		printTree(root->right);
	}

	return;
}