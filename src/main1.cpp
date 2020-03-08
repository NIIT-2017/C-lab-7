#include "task1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	int count=0;
	char buf[512];
	PITEM head,tail,item;
	fp=fopen("fips10_4.csv","rt");
	if(!fp) {
		perror("File fips10_4.csv:");
		exit(1);
	}
	fgets(buf,512,fp);
	printf("%s", buf);
	while(fgets(buf,512,fp))
	{
		if(count==0)
		{
			head=createList(createCountry(buf));
			tail=head;
		}
		else
		{
			tail=addToTail(tail,createCountry(buf));
		}
		count++;
	}
	fclose(fp);
	printf("Total items: %d\n",countList(head));
	item = findByCountry(head, (char*)"ru");
	if (item == NULL)
		printf("Not found!\n");
	else
	{
		findAllCountries(head, (char*)"ru");
	}
	item = findByName(head, (char*)"Yerevan");
	if (item == NULL)
		printf("Not found!\n");
	else
		printCountry(item);
	return 0;
}