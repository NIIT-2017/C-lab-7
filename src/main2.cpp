#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "task2.h"

int main()
{
	char buf[M];
	PWT root = NULL;
	char ch;
	int i = 0;

	FILE *fp;
	fp = fopen("words C#.txt", "r");
	if (fp == NULL)
	{
		puts("File not open");
		exit(EXIT_FAILURE);
	}

	while (fgets(buf, M, fp))
	{
		root = makeTree(root, buf);
	}
	fclose(fp);

	fp = fopen("task2.txt", "r");
	if (fp == NULL)
	{
		puts("File not open");
		exit(EXIT_FAILURE);
	}

	while ((ch = fgetc(fp)) != EOF)
	{
		if (ch > 'a' && ch < 'z')
		{
			buf[i] = ch;
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