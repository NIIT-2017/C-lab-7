#include <stdio.h>
#include "task2.h"

int main(int argc,char *argv[])
{
	if (argc < 3)
		printf("Arguments not found!\n");

	struct NODE *root = NULL;
	FILE *fp;
	char buf[N];
	int max;

	fp = fopen("Words.txt", "r");
	if (fp == NULL)
	{
		printf("File not found!\n");
		return 1;
	}

	while (!feof(fp))
	{
		fscanf(fp, "%s", buf);
		root = makeTree(root, buf);
	}
	fclose(fp);

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("File not found!\n");
		return 2;
	}

	while (!feof(fp))
	{
		fscanf(fp, "%s", buf);
		searchTree(root, buf);
	}

	max = searchMax(root);

	while (max >= 0)
	{
		printTree(root);
		max--;
	}
	return 0;
}