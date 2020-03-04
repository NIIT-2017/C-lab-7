#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 256

struct NODE
{
	char word[BUF];
	unsigned long count;
	struct NODE *left;
	struct NODE *right;
};

typedef struct NODE TNODE;
typedef TNODE* PNODE;

PNODE createTree(PNODE root, char *word);
void printTree(PNODE root);

PNODE createTree(PNODE root, char *word)
{
	if (root == NULL)
	{
		root = (PNODE)malloc(sizeof(TNODE));

		strcpy(root->word, word);
		root->count = 1;
		root->left = root->right = NULL;
	}
	else if (strcmp(root->word, word)>0)
		root->left = createTree(
		root->left,
		word);
	else if (strcmp(root->word, word)<0)
		root->right = createTree(
		root->right,
		word);
	else
		root->count++;
	return root;
}

void printTree(PNODE root)
{
	if (root->left)
		printTree(root->left);
	printf("%s-%lu\n", root->word,
		root->count);
	if (root->right)
		printTree(root->right);
}

int main(int argc, char **argv)
{
	FILE *fp;
	int ch;
	char buf[BUF];
	PNODE root = NULL;
	fp = fopen(argv[1], "rt");
	if (!fp) {
		perror("File: ");
		return 1;
	}
	while (fscanf(fp, "%s", buf) == 1)
		root = createTree(root, buf);
	fclose(fp);
	printTree(root);
	return 0;
}