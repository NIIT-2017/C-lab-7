#include "task1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	FILE *fp;
	int count = 0;
	char buf[N];
	int click = 0;
	char search[N] = { 0 };

	ITEM * head = NULL;
	ITEM * item = NULL;
	ITEM * tail = NULL;

	fp = fopen("fips10_4.csv", "rt");
	if (fp == NULL)
	{
		puts("File not found!");
		return 1;
	}
	
	fgets(buf, N, fp);
	while (fgets(buf, N, fp))
	{
		if (count == 0)
		{
			head = createList(createRegion(buf));
			tail = head;
		}
		else
		{
			tail = addToTail(tail, createRegion(buf));
		}
		count++;
	}
	fclose(fp);
	
	printf("Total items: %d\n", countList(head));
	
	do
	{
		printf("Enter 1 - if you want to search by country;\n");
		printf("Enter 2 - if you want to search by code;\n");
		printf("Enter 3 - if you want to search by region name;\n");
		printf("Enter 4 for exit;\n");
		scanf("%d", &click);
		fgets(search, 2, stdin);

		switch (click)
		{
		case (1):
			printf("Enter country letter:\n");
			fgets(search, N, stdin);

			if (search[strlen(search) - 1] = '\n')
				search[strlen(search) - 1] = '\0';

			findByCountry(head, search);
			break;
		case (2):
			printf("Enter code of region:\n");
			fgets(search, N, stdin);

			if (search[strlen(search) - 1] = '\n')
				search[strlen(search) - 1] = '\0';

			findByCode(head, search);
			break;
		case (3):
			printf("Enter name of region:\n");
			fgets(search, N, stdin);

			if (search[strlen(search) - 1] = '\n')
				search[strlen(search) - 1] = '\0';

			findByName(head, search);
			break;
		case (4):
			break;
		default:
			printf("You entered an incorrect number!\n");
		}
	} while (click != 4);


	return 0;
}