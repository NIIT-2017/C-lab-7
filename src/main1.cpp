#include "task1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	FILE* fp;
	int count = 0;
	char buf[512];
	PITEM head, tail, item;
	fp = fopen("fips10_4.csv", "rt");
	if (!fp) {
		perror("File names.csv:");
		exit(1);
	}
	fgets(buf, 512, fp);
	while (fgets(buf, 512, fp))
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
	while (head)
	{
		item = findByCountry(head, (char*)"TH");
		if (item == NULL)
			printf("End!\n");
		else
			printName(item);
		head = item->next;
	}
	return 0;
}