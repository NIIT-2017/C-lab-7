#include "task2.h"
#include <stdio.h>
#include <stdlib.h>
#include < string.h >

struct NODE* makeTree(struct NODE* root, char* word)
{
	if (root == NULL) // дерево пустое значит корень пустой
	{
		root = (struct NODE*)malloc(sizeof(struct NODE)); // выделяем память в heap
		strcpy((char*)root->word, word); // копирует word в root->word
		root->count = 0; // увеличиваем счетчик на 1
		root->left = root->right = NULL; // присваимаем левому и правому узлу дерева 0
	}
	else if (strcmp((char*)root->word, word) > 0) // сравниваем первый символ строки word и root->word
		root->left = makeTree(root->left,word); // доавляем левый узел если strcmp вернула значение >0
	else if (strcmp((char*)root->word, word) < 0)
		root->right = makeTree(root->right,word);// доавляем правый узел если strcmp вернула значение <0
	return root;
}

void searchTree(struct NODE* root, char* searchword) // поиск нужного слова в дереве
{
	if (root == NULL)
		return;
	if (strcmp(root->word, searchword) == 0)
	{
		root->count++;
	}
	else if (strcmp(root->word, searchword) > 0)
		searchTree(root->left, searchword);
	else if (strcmp(root->word, searchword) < 0)
		searchTree(root->right, searchword);
}
void printTree(struct NODE* root)
{
	if (root->left)
		printTree(root->left);
	printf("%s-%d\n", root->word, root->count);
	if (root->right)
		printTree(root->right);
}

void chomp(struct NODE* root)
{
	if (root->left)
		chomp(root->left);
	if (root->word[strlen(root->word) - 1] == '\n')
		root->word[strlen(root->word) - 1] = '\0';
	if (root->right)
		chomp(root->right);
}