#include "task1.h"
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	int count = 0;
	char buf[500];

	PITEM head = NULL, tail = NULL, item = NULL;
	fp = fopen("fips10_4 (3).csv", "rt");
	if (!fp)
	{
		printf("Cannot read file!\n");
		return 1;
	}

	fgets(buf, 512, fp);//throwing away the first string

	while (fgets(buf, 512, fp))// reading the document
	{
		if (count == 0)//it is the first element
		{
			head = createList(createRegion(buf));//creating a list
			tail = head;//because there is only one element in the list now
		}
		else//there is a list
		{
			tail = addToTail(tail, createRegion(buf));//adding element to the tail 
		}
		count++;
	}
	fclose(fp);//closing file

	int choice = 0;
	do
	{
		char nameOfRegion[30] = { 0 };
		char symbols[3] = { 0 };
		printf("MENU\n");
		printf("If you want find a region by name enter 1\n");
		printf("If you want find all regions by symbols enter 2\n");
		printf("If you want to escape enter 3\n");
		scanf("%d", &choice);
		fgets(nameOfRegion, 2, stdin);//deleting \n after scanf
		switch (choice)
		{
		case(1): printf("Enter the name of region\n");
			fgets(nameOfRegion, 28, stdin);

			if (nameOfRegion[strlen(nameOfRegion) - 1] = '\n')//deleting \n
				nameOfRegion[strlen(nameOfRegion) - 1] = '\0';

			item = findByRegion(head, nameOfRegion);//searching the region
			if (item == NULL)//if we did not found this region
				printf("Not found!\n");
			else
				printRegion(item);
			break;
		case(2): printf("Enter the symbols, for example \"BR\"\n");
			fgets(symbols, 4, stdin);

			if (symbols[strlen(symbols) - 1] = '\n')//deleting \n
				symbols[strlen(symbols) - 1] = '\0';
			findBySymbols(head, symbols);
			break;
		case(3): exit(0);

		default: printf("Wrong choice\nTry again!\n");
			break;
		}//brace from switch
	}//brace from do
	while (choice != 3);


	/*//code for checking
	item = findByRegion(head, "Amazonas");//an example of searching the region
	if (item == NULL)//if we did not found this region
		printf("Not found!\n");
	else
		printRegion(item);
	findBySymbols(head, "BR");
	*/
	return 0;
}