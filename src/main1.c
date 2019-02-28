#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"

int main(int argc, const char * argv[])
{
	if (argc < 2)
		printf("Arguments not found\n");
	FILE *fp;
	fp = fopen(argv[1], "r");
	if (fp == NULL)
		puts("not found");

	char buf[256];
	
	struct regions *head = NULL;
	struct regions *prev = NULL, *current = NULL;
	
	while (fgets(buf, 256, fp) != NULL)
	{
		current = (struct regions *) malloc(sizeof(struct regions));
		if (head == NULL)
			head = current;
		else
			prev->next = current;
		current->next = NULL;
		str(current, buf);
		prev = current;
	}

	char i = 0;
	char qwerty[256];
	printf("Press C, if you want to search the country\nPress R, if you want to search the region\n");
	scanf("%c", &i);
	if (i == 'R')
	{
		printf("Press the region, for example \"Encamp\"\n");
		scanf("%s", &qwerty);
		region(head, current, qwerty);
	}
	if (i == 'C')
	{
		printf("Press the country, for example AD\n");
		scanf("%s", &qwerty);
		country(head, current, qwerty);
	}

	fclose(fp);

	getchar();
	return 0;
}



