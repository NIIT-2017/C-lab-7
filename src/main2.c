#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "task2.h"

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		printf("wrong format\n");
		return 1;
	}
	FILE *file = fopen(argv[1], "r");
	if (!file)
	{
		printf("cannot read %s\n", argv[1]);
		return 2;
	}

	char bufWord[SIZE] = { 0 };
	KEYWORD * root = 0, * word = 0;
	while (!feof(file))
	{
		fgets(bufWord, SIZE, file);
		chomp(bufWord);
		root = AddWordToTree(root, bufWord);
	}
	fclose(file);
	file = 0; 
	file = fopen(argv[2], "r");
	if (!file)
	{
		printf("cannot read %s\n", argv[2]);
		return 2;
	}

	while (fscanf(file, "%s", bufWord) == 1)
	{
		word = searchTree(root, bufWord);
		if (word != NULL)
			word->freq++;
	}
	fclose(file);
	printTree(root);
	return 0;
}