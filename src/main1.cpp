#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "task1.h"

#define M 100

int main()
{
	int  isoORname = 0;
	char buf[M];
	TREGION *REG=NULL;

	FILE *fp;
	fp = fopen("file.txt", "r");
	if (fp == NULL)
	{
		puts("File not open");
		exit(EXIT_FAILURE);
	}
	
	fgets(buf, M, fp);
	REG = create(buf);
	
	while (fgets(buf, M, fp))
	{
		add(REG, buf);
	}
	fclose(fp);
	
	printf("Enter search iso (1) or name(2): ");
	scanf("%d", &isoORname);
	if (isoORname == 1)
	{
		printf("Enter iso: ");
		scanf("%s", buf);
		SearchIso(REG, buf);
	}
	if (isoORname == 2)
	{
		printf("Enter name: ");
		scanf("%s", buf);
		SearchName(REG, buf);
	}
	return 0;
}