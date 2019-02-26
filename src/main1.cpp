#pragma warning(disable:4996)
#include "task1.h"

 main()
 {
	struct region * head = NULL;
	head = getData("task1.txt");
	if (head == NULL)
	{
		printf("can't read data!");
		return -1;
	}
	int input=1;
	while (input)
	{
		printf("\nselect option:\n");
		printf("1. print all\n");
		printf("2. search by abbreviation\n");
		printf("3. search by name\n");
		printf("0. exit\n");
		printf("Your choice: ");

		scanf("%d", &input);
		switch (input) {
		case 1:
			regionPrintf(head);
			break;
		case 2:
			while (!getchar());
			printf("enter abbreviation \"XX\": ");
			char abr[Abr]="";
			fgets(abr, Abr,stdin);
			regSearchAbr(head, abr);
			break;
		case 3:
			while (!getchar());
			printf("enter name \"Xxxxx...\": ");
			char name[RegionName] = "";
			fgets(name, RegionName, stdin);
				if (name[strlen(name) - 1] == '\n')
					name[strlen(name) - 1] = '\0';
			regSearchName(head, name);
			break;
		case 0:
			break;
		default:
			printf("\nwrong input, try again\n");
		}
	}
	regionFreeMem(head);
	return 0;
 }