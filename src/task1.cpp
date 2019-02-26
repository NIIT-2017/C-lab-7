#include "task1.h"
#define MAXSIZE_X 256

struct region * getData(const char * fileName)
{
	struct region * head = NULL;
	struct region * prev = NULL;
	struct region * current = NULL;
	char buf[maxBuf] = { 0 };
	FILE *mf;

	mf = fopen(fileName, "r");
	if (mf == NULL) { printf("file open error\n"); return NULL; }

	fgets(buf, maxBuf, mf); //remove first string (becouse it is not data)
	while (fgets(buf, maxBuf, mf) != NULL)
	{
		int sizeBuf = strlen(buf);
		if (buf[sizeBuf - 1] == '\n')
			buf[sizeBuf-- - 1] = '\0';
		current = (struct region *) malloc(sizeof(struct region));
		if (head == NULL)
			head = current;
		else
			prev->next = current;
		setEndItem(current, buf, sizeBuf);
		prev = current;
	}
	fclose(mf);
	return head;
}

void  setEndItem(struct region *current , char*buf, int sizeBuf)
{
	for (int i = 0; i < 2; i++)
		current->abr[i] = buf[i];
		current->abr[2] = '\0';

	for (int i = 3; i < 5; i++)
		current->regCode[i-3] = buf[i];
		current->regCode[2] = '\0';
	
	for (int i = 7; i < sizeBuf; i++) //without " at the beginning and end
		current->regName[i-7] = buf[i];
		current->regName[sizeBuf-8] = '\0';

		current->next = NULL;
}

void regionPrintf(struct region *head)
{
	while (head != NULL)
	{
		printf("%s  %s  %s\n", head->abr, head->regCode, head->regName);
		head = head->next;
	}
}

void regSearchAbr(struct region *head, char *abr)
{
	while (head != NULL)
	{
		if (!strcmp( head->abr, abr))
			printf("%s  %s  %s\n", head->abr, head->regCode, head->regName);
		head = head->next;
	}
}

void regSearchName(struct region *head, char *name)
{
	while (head != NULL)
	{
		if (!strcmp(head->regName, name))
			printf("\n%s  %s  %s\n", head->abr, head->regCode, head->regName);
		head = head->next;
	}
}

void regionFreeMem(struct region *head)
{
	struct region * current = head;
	while (head != NULL)
	{
		current = head;
		head = current->next;
		free(current);
	}
}