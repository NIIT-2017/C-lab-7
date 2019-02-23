#include "task2.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char buf[512];
	struct tnode *root = NULL, *item = NULL;
	fp = fopen("WordList.txt", "rt");
	if (!fp)
	{
		perror("File WordList.txt:");
		exit(1);
	}
	while (fgets(buf, 512, fp))
	{
		chomp(buf);
		root = makeTree(root, buf);
	}
	fclose(fp);
	fp = fopen("Check.txt", "rt");
	while (fscanf(fp, "%s", buf) == 1)
	{
		item = searchTree(root, buf);
		/*if (item != NULL)
			item->count++;*/
	}
	printTree(root);
	return 0;
}