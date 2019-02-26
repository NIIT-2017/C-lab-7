#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "task2.h"

int main(int argc, char* argv[])
{
	FILE *fp;
	char str[M];
	PCOW root = NULL;
	char ch;
	int i = 0;

	if (argc != 3)
	{
		printf("Using: %s file name\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		puts("File not found!");
		exit(EXIT_FAILURE);
	}

	while (fgets(str, M, fp))
	{
		root = makeTree(root, str);
	}

	fclose(fp);
	if ((fp = fopen(argv[2], "r")) == NULL)
	{
		puts("File not found!");
		exit(EXIT_FAILURE);
	}

	while ((ch = fgetc(fp)) != EOF)
	{
		if (ch > 'a' && ch < 'z')
		{
			str[i] = ch;
			i++;
		}
		else
		{
			str[i] = '\0';
			searchTree(root, str);
			i = 0;
		}
	}
	
	fclose(fp);
	printTree(root);
	return 0;
}