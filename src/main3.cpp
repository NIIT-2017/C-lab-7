#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "task3.h"

int main(int argc, char * argv[])
{
	char * file;
	SYM buf[N];
	struct SYM * root = NULL;
	
	if (argc < 2)
	{
		printf("Error!\n");
		return 1;
	}
	else
		file = argv[1];

	filling(buf, file);
	root = buildTree(buf);
	printTree(root);

	return 0;
}