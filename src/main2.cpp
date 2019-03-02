#include "task2.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	FILE *fp;
	char buf[N];
	PNODE root = NULL;
	char temp = 0;
	int i = 0;

	fp = fopen("cKeyWords.txt", "rt");
	if (fp == NULL)
	{
		puts("File not found!");
		return 1;
	}

	while (fgets(buf, N, fp))
	{
		chomp(buf);
		root = makeTree(root, buf);
	}
	fclose(fp);

	fp = fopen("source.txt", "r");
	if (fp == NULL)
	{
		puts("File not found!");
		return 1;
	}

	while ((temp = fgetc(fp)) != EOF)
	{
		if (temp >= 'a' && temp <= 'z')
		{
			buf[i] = temp;
			i++;
		}
		else
		{
			buf[i] = '\0';
			searchTree(root, buf);
			i = 0;
		}
	}
	
	fclose(fp);

	printTree(root);

	return 0;
}