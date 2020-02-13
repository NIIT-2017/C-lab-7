#include "task2.h"
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 1024

int main()
{
	FILE* fw;
	fw = fopen("keywords.txt", "r");
	if (fw == NULL)
	{
		puts("File open error!");
		return 1;
	}
	char words[MAX_LEN];
	PKEYWORD node = NULL;
	while (fgets(words, 256, fw) != NULL)
	{
		chomp(words);

		int i = 0;
		int inWord = 0;
		int count = 0;
		char temp[256];
		PKEYWORD tnode = NULL;
		while (words[i])
		{
			if (words[i] != ' ' && inWord == 0)
			{
				temp[count] = words[i];
				count++;
				inWord = 1;
			}
			else if (words[i] != ' ' && inWord == 1)
			{
				temp[count] = words[i];
				count++;
			}
			else if (words[i] == ' ' && inWord == 1)
			{
				inWord = 0;
				temp[count] = '\0';
				tnode = (PKEYWORD)malloc(sizeof(TKEYWORD));
				strcpy(tnode->word, temp);
				tnode->count = 0;
				node = rbInsert(node, tnode);
				count = 0;
			}
			i++;
		}
	}
	fclose(fw);
	node = getRoot(node);
	fw = fopen("task8.cpp", "r");
	if (fw == NULL)
	{
		puts("File cpp open error!");
		return 1;
	}
	while (fgets(words, 256, fw) != NULL)
	{
		chomp(words);

		int i = 0;
		int inWord = 0;
		int count = 0;
		char temp[256];
		while (words[i])
		{
			if (words[i] < 'A' || words[i] > 'Z' && words[i] < 'a' || words[i] > 'z')
				words[i] = ' ';
			i++;
		}
		i = 0;
		while (words[i])
		{
			if (words[i] != ' ' && inWord == 0)
			{
				temp[count] = words[i];
				count++;
				inWord = 1;
			}
			else if (words[i] != ' ' && inWord == 1)
			{
				temp[count] = words[i];
				count++;
			}
			else if (words[i] == ' ' && inWord == 1)
			{
				inWord = 0;
				temp[count] = '\0';
				searchTree(node, temp);
				count = 0;
			}
			i++;
		}
	}
	printTree(node);
	return 0;
}