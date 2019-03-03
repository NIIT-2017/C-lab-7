#include <stdio.h>
#include "task1.h"
#define N 100

int main()
{
	FILE *fp;
	int count = 0;
	char buf[N] = { 0 };
	int menu = 0;
	char search[N] = { 0 };
	PITEM head, tail, item;

	fp = fopen("fips10_4.csv", "r");
	if (fp == NULL)
	{
		printf("File not found!\n");
		return 1;
	}
	fgets(buf, N, fp);
	while (fgets(buf, N, fp))
	{
		if (count == 0)
		{
			head = createList(createName(buf));
			tail = head;
		}
		else
		{
			tail = addToTail(tail, createName(buf));
		}
		count++;
	}
	fclose(fp);

	printf("Total items: %d\n", countList(head));
	
	printf("Select search:\n");
	printf("1 - search by iso\n");
	printf("2 - search by city name\n");
	printf("Another button to exit\n");
	scanf("%d", &menu);

	while (menu==1||menu==2)
	{
		switch (menu)
		{
		case 1:
			printf("Please enter iso country: \n");
			scanf("%s", search);
			findIso(head, search);
			break;
		case 2:
			printf("Enter the city name: \n");
			scanf("%s", search);
			findName(head, search);
			break;
		}
		printf("Select search:\n");
		printf("1 - search by iso\n");
		printf("2 - search by city name\n");
		printf("Another button to exit\n");
		scanf("%d", &menu);
	}
	return 0;
}