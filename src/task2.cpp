#include "task2.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void chomp(char* bufer) // удаляем символ переноса строки
{
	if (bufer[strlen(bufer) - 1] == '\n')
        bufer[strlen(bufer) - 1] = 0;
}

keyWordST* createStruct(char bufer[]) // создаем структуру
{
	keyWordST* keyCell = (keyWordST*)malloc(sizeof(keyWordST));
	strcpy(keyCell->word, bufer);
	keyCell->count = 0;
	keyCell->left = NULL;
	keyCell->right = NULL;
	return keyCell;
}

keyWordST* makeTree (FILE* fp) // создаем дерево ключевых слов на основании файла
{
	char bufer[32] = { 0 };
	keyWordST* first = NULL;
	keyWordST* subsequent = NULL;
	fgets(bufer, 32, fp);
	chomp(bufer);
	first = createStruct(bufer);
	subsequent = first;
	
	while (fgets(bufer, 32, fp))
	{
		chomp(bufer);
		if (strcmp(subsequent->word, bufer))
		{
			subsequent->right = createStruct(bufer);
			subsequent = subsequent->right;
		}
		else
		{
			subsequent->left = createStruct(bufer);
			subsequent = subsequent->left;
		}
	}
    return first;
}

void searchTree(keyWord* keyList, const char bufer[]) // поиск слова в дереве ключевых слов
{
	if (strcmp(keyList->word, bufer) == 0)
		keyList->count++;
	else if (strcmp(keyList->word, bufer) < 0)
		if (keyList->right != NULL)
			searchTree(keyList->right, bufer);
	else
		if (keyList->left != NULL)
			searchTree(keyList->left, bufer);
}

void sourceCodeAnaliz(FILE* fp, keyWord* keyList) // анализируем файл исходного кода, делим на слова
{
	char str[256] = { 0 };
	char word[32] = { 60 };
	while (fgets(str, 256, fp))
	{
		if (str[strlen(str) - 1] == '\n')
			str[strlen(str) - 1] = '\0';
		for (int i = 0, inWord = 0, position = 0; str[i] != 0; i++)
		{
			if (!isalpha(str[i]))
			{
				if (inWord == 1)
				{
					int j = 0;
					for (; position < i; position++, j++)
						word[j] = str[position];
					for (; j < 32; j++)
						word[j] = 0;
					searchTree(keyList, word);
					inWord = 0;
				}
			}
			else if (isalpha(str[i]) && inWord == 0)
			{
				inWord = 1;
				position = i;
			}
			else if (isalpha(str[i]) && inWord == 1)
				if (!str[i + 1])
				{
					int j = 0;
					for (; position < i; position++, j++)
						word[j] = str[position];
					for (; j < 32; j++)
						word[j] = 0;
					searchTree(keyList, word);
				}
		}
	}	
}

void printTree(keyWord* keyList) // распечатка дерева
{
	if (keyList->left != NULL)
		printTree(keyList->left);
	printf("%10s : %i\n", keyList->word, keyList->count);
	if (keyList->right != NULL)
		printTree(keyList->right);
}

void deleteTree(keyWordST* keyList) // освобождаем выделенную память
{
	if (keyList->left != NULL)
		free(keyList->left);
	if (keyList->right != NULL)
		free(keyList->right);
	free(keyList);
}