#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "task2.h"

int main()
{
	FILE *fp;
	char buf[256];
	struct NODE *root=nullptr, *item=nullptr;
	fp = fopen("keywords.txt", "rt");
	while (fgets(buf, 256, fp))
	{
		chomp(buf);
		root = makeTree(root, buf);
	}
	fclose(fp);
	fp = fopen("War_World.txt", "rt");
	while (fscanf(fp, "%s", buf) == 1)
	{
		item = searchTree(root, buf);
		if (item != NULL)
			item->count++;
	}
	printTree(root);
	return 0;

}