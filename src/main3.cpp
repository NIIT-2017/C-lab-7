#include "task3.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *fp;
	int ch;
	int count = 0;
	char buf[256];
	struct SYM *root = NULL;
	struct SYM arr[256];
	fp = fopen(argv[1], "rt");
	if (!fp)
	{
		perror("File: ");
		return 1;
	}
	while ((ch = fgetc(fp)) != EOF)
	{arr[(int)ch].count++;
	count++;
	}
	for(int i=256;i>0;i--)
		if (arr[i].count != 0)
		{
			arr[i].symbol = (char)i;
			arr[i].freq = (float)arr[i].count / count;
			root = createTree(root, arr[i]);
		}

	
	
	fclose(fp);
	printTree(root);
	return 0;
}