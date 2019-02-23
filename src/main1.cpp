#include "task1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	int count = 0;
	char buf[512];
	struct ITEM *head, *tail, *item;
	fp = fopen("fips.csv", "rt");
	if (!fp)
	{
		perror("File flips.csv:");
		exit(1);
	}
	fgets(buf, 512, fp);
	while (fgets(buf, 512, fp))
	{
		if (count == 0)
		{
			head = createList(createRec(buf));
			tail = head;
		}
		else
		{
			tail = addToTail(tail, createRec(buf));
		}
		count++;
	}
	fclose(fp);
	printf("Total items:%d\n", countList(head));
	item = findByCountry(head,(char*)"AD");
	if (item == NULL)
		printf("Not found!\n");
	else
		printCountry(item);
	
	return 0;
}