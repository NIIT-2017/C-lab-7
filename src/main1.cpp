#include "task1.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	FILE* fp;
	int count = 0;
	char buf[256];
	PItem head, tail, item, desired_region;
	fp = fopen("fips10_4.csv", "rt");

	if (!fp)
	{
		perror("File fips10_4.csv:");
		exit(1);
	}

	fgets(buf, 256, fp);
	while (fgets(buf, 256, fp))
	{
		if (count == 0)
		{
			head = createList(createRegion(buf));
			tail = head;
		}
		else
			tail = addToTail(tail, createRegion(buf));

		count++;
	}

	fclose(fp);
	printf("Total items:%d\n", countList(head));

	findOllData(head, "AF");

	desired_region = findDesiredRegion(head, "Canillo");
	if (desired_region == NULL)
		printf("Not found!\n");
	else
		printDesiredRegion(desired_region);
	return 0;
}