//Clab 7 task3

#include "task3.h"

int i = 0;

node* create(char symbol)
{
	node* root = (node*)malloc(sizeof(node));
	root->keySym = symbol;
	root->left = NULL;
	root->right = NULL;

	return root;
}

node* add(node* currentNode, char symbol)
{
	if (currentNode == NULL)
	{
		currentNode = (node*)malloc(sizeof(node));
		currentNode->left = NULL;
		currentNode->right = NULL;
		currentNode->frequency = 0;
		currentNode->keySym = symbol;
	}

	else if (currentNode->keySym < symbol)
	{
		currentNode->left = add(currentNode->left, symbol);
	}

	else if (currentNode->keySym > symbol)
	{
		currentNode->right = add(currentNode->right, symbol);
	}

	else if (currentNode->keySym == symbol)
	{
		currentNode->frequency++;
	}

	return currentNode;
}

void createArr(node* currentNode, node* arr[256])
{
	if (currentNode->left != NULL)
		createArr(currentNode->left, arr);

	if (currentNode->right != NULL)
		createArr(currentNode->right, arr);

	arr[i] = currentNode;
	i++;
}

void sort(node* arr[255])
{
	int i = 0;
	int j = 0;
	node* change;
	
	for (; i <= 255; i++)
	{
		if (arr[i] == NULL)
			break;

		int numMin = i;
		for (j = i; j < 255; j++)
		{
			if (arr[j] == NULL)
				break;
			if (arr[j]->frequency <= arr[numMin]->frequency)
			{
				numMin = j;
				j++;
			}
		}
		change = arr[i];
		arr [i] = arr [numMin];
		arr [numMin] = change;
	}

 }

void printTree(node *arr[255])
{
	for (int j=0; j < 255; j++)
	{
		if (arr[j] == NULL)
			break;
		printf("%c\t%u\n", arr[j]->keySym, arr[j]->frequency);
	}
}