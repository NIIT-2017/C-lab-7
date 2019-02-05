#include "task3.h"
#include <stdio.h>

int main()
{
	char filename[10] = "1.txt";
	struct SYM arr[256],*root;
	fillArr(arr, filename);
	root = createTree(arr);
	printTree(root);

	return 0;
}