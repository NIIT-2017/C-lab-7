#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "task1.h"

int main()
{
	FILE *fp;
	char buf[250];
	struct ITEM *head=nullptr, *tail=nullptr, *item;
	int count = 0;
	fp = fopen("1.txt", "rt");
	fgets(buf, 256, fp);
	while (fgets(buf, 256, fp))
	{
		if (count == 0)
		{
			head = createList(createRecord(buf));
			tail = head;
		}
		else
			tail = addToTail(tail, createRecord(buf));
		count++;
	}
	fclose(fp);
	printf("%d records\n", count);
	printf("Input country: ");
	scanf("%s", buf);
	findByCode(head, buf);
	printf("Input region: ");
	scanf("%s", buf);
	item = findByRegion(head, buf);
	printf("Country-%s, code-%s, region-%s\n", item->code_reg->country, item->code_reg->code, item->code_reg->region);

	return 0;
}