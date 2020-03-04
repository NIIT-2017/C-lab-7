#include "task2.h"
#include <string.h>
#include <stdlib.h>

void leftRotate(PKEYWORD x)
{
	PKEYWORD y = NULL;
	y = (PKEYWORD)malloc(sizeof(TKEYWORD));
	y = x->right;
	x->right = y->left;

	if (y->left != NULL)
		y->left->p = x;
	y->p = x->p;

	if (x != NULL && x->p != NULL && x == x->p->left)
		x->p->left = y;
	else if (x != NULL && x->p != NULL)
		x->p->right = y;

	y->left = x;
	x->p = y;
}

void rightRotate(PKEYWORD y)
{
	PKEYWORD x = NULL;
	x = (PKEYWORD)malloc(sizeof(TKEYWORD));
	x = y->left;
	y->left = x->right;

	if (x->right != NULL)
		x->right->p = y;
	x->p = y->p;
	//if(y->p == NULL)
	if (y != NULL && y->p != NULL && y == y->p->right)
		y->p->right = x;
	else if (y != NULL && y->p != NULL)
		y->p->left = x;
	x->right = y;
	y->p = x;
}

void printTree(PKEYWORD node)
{
	if (node)
	{
		printTree(node->left);
		printf("word: %9s; count: %d\n", node->word, node->count);
		printTree(node->right);
	}

}

PKEYWORD getRoot(PKEYWORD x)
{
	while (x->p != NULL)
		x = x->p;
	return x;
}

void rbInsertFixup(PKEYWORD t, PKEYWORD z)
{
	PKEYWORD y = NULL;
	y = (PKEYWORD)malloc(sizeof(TKEYWORD));
	while (z->p != NULL && z->p->color == RED)
	{
		if (z->p == z->p->p->left)
		{
			y = z->p->p->right;
			if (y != NULL && y->color == RED)
			{
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else if (z == z->p->right)
			{
				z = z->p;
				leftRotate(z);
			}
			else
			{
				z->p->color = BLACK;
				z->p->p->color = RED;
				rightRotate(z->p->p);
			}
		}
		else if (z->p == z->p->p->right)
		{
			y = z->p->p->left;
			if (y != NULL && y->color == RED)
			{
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else if (z == z->p->left)
			{
				z = z->p;
				rightRotate(z);
			}
			else
			{
				z->p->color = BLACK;
				z->p->p->color = RED;
				leftRotate(z->p->p);
			}
		}
	}
	y = getRoot(z);
	y->color = BLACK;
}

PKEYWORD rbInsert(PKEYWORD t, PKEYWORD z)
{
	if (t == NULL)
	{
		t = (PKEYWORD)malloc(sizeof(TKEYWORD));
		t = z;
		t->color = BLACK;
		t->p = NULL;
		t->left = NULL;
		t->right = NULL;
		return t;
	} 
	else
	{
		PKEYWORD y = NULL;
		y = (PKEYWORD)malloc(sizeof(TKEYWORD));
		PKEYWORD x = NULL;
		x = (PKEYWORD)malloc(sizeof(TKEYWORD));
		x = getRoot(t);
		while (x != NULL)
		{
			y = x;
			if (strcmp(z->word, x->word) < 0)
				x = x->left;
			else
				x = x->right;
		}
		z->p = y;
		if (strcmp(z->word, y->word) < 0)
			y->left = z;
		else
			y->right = z;
		z->left = NULL;
		z->right = NULL;
		z->color = RED; //новый узел красный
		rbInsertFixup(t, z);
		return z;
	}
}

char* chomp(char* str)
{
	if (str[strlen(str) - 1] == '\n')
		str[strlen(str) - 1] = '\0';
	return str;
}

void searchTree(struct KEYWORD* node, char* word)
{
	if (node) {
		searchTree(node->left, word);
		if (strcmp(word, node->word) == 0)
			node->count++;
		searchTree(node->right, word);
	}
}