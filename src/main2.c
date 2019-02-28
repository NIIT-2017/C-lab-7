#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task2.h"

int main(int argc, char *argv [])//первый аргумент - список ключевых слов, второй аргумент - проверяемый файл, функция chomp - не нужна
{
	if (argc < 3)
		printf("Arguments not found");

	FILE *fp;
	fp = fopen(argv[1], "rt");
	if (!fp)
	{
		perror("File: ");
		return 1;
	}

	int ch;
	char buf[256];
	PNODE root = NULL;
	fp = fopen(argv[1], "rt");
	
	while (fscanf(fp, "%s", buf) == 1)
		root = makeTree(root, buf);
	fclose(fp);

	
	fp = fopen(argv[2], "rt");
	if (!fp)
	{
		perror("File: ");
		return 1;
	}
	while (fscanf(fp, "%s", buf) == 1)
		searchTree(root, buf);
	fclose(fp);
	
	printTree(root);
	
	getchar();
	return 0;
}