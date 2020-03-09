#include <stdio.h>
#include "task2.h"
int main()
{
	KeyWords* root = NULL;
	FILE* fp = NULL;
	fp = fopen("C:\\labsss\\KeyWords.txt", "rt");
	if (!fp)
	{
		printf("file lost\n");
	}
	root = makeTree(root, fp);
	fclose(fp);
	fp = fopen("C:\\labsss\\task2.txt", "rt");
	if (!fp)
	{
		printf("file lost\n");
	}
	checkText(fp, root);
	fclose(fp);
	printTree(root);
	clearTree(root);
	return 0;
}