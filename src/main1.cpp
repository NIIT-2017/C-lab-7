#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "task1.h"

#define M 256

int main()
{
	int count = 0, numrec = 0, option = 0;
	FILE *fp;
	char buf[M];
	struct REGION *head = NULL;
	if ((fp = fopen("fips.txt", "r")) == NULL)
	{
		puts("File not found!");
		exit(EXIT_FAILURE);
	}

	fgets(buf, M, fp);
	head = create(buf);
	while (fgets(buf, M, fp) )
	{
		add(head, buf);
	}
	fclose(fp);
	printf("Enter '1' to search by iso or enter '2' to search by name: ");
	scanf("%d", &option);
	if (option == 1)
	{
		printf("Enter iso or '#' for exit: ");
		while ((scanf("%s", buf) == 1) && buf[0] != '#')
		{
			searchByIso(head, buf);
			printf("Enter iso or '#' for exit: ");
		}
	}
	else
	{
		printf("Enter name of the region or '#' for exit: ");
		while ((scanf("%s", buf) == 1) && buf[0] != '#')
		{
			searchByName(head, buf);
			printf("Enter iso or '#' for exit: ");
		}
	}
	return 0;
}