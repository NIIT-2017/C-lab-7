#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "task1.h"

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("wrong format\n");
		return 1;
	}
	char buf[256] = { 0 };
	FILE * regFile = fopen(argv[1], "r");
	if (!regFile)
	{
		printf("cannot open file %s", argv[1]);
		return 2;
	}

	ITEM *listHead = 0;
	int count = 0;
	while (fgets(buf, 256, regFile))
	{
		listHead = Add2List(listHead, CreateRegion(buf));
		count++;
	}
	fclose(regFile);
	int action = -1;
	while (action)
	{
		printf("choose action:\npress '1' to start searching region by it's name;\npress '2' to start searching all regions by symbols;\nenter 0 to exit\n");
		scanf("%d", &action);
		fflush(stdin);
		switch (action)
		{
		case(1) :
			system("cls");
			printf("enter region name:");
			gets(buf);
			FindByRegionName(listHead, buf);
			break;
		case(2) :
			system("cls");
			printf("enter region symbols:");
			gets(buf);
			FindAllRegionsBySymbs(listHead, buf);
			break;
		case(0):
			system("cls");
			break;
		default: 
			system("cls");
			printf("unknown command\n\n");
			break;
		}
	}
	DeleteList(listHead);
	listHead = 0;
	return 0;
}