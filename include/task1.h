#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Abr 3 //max length of abbreviation
#define Code 3 //max length of Code
#define RegionName 100 // max length of region name
#define maxBuf Abr+Code+RegionName // max length of string

struct region
{
	char abr[Abr];
	char regCode[Code];
	char regName[RegionName];
	struct region * next;
};

struct region * getData(const char * fileName);
void  setEndItem(struct region *current, char*buf, int sizeBuf);
void regionPrintf(struct region *head);
void regSearchAbr(struct region *head, char *abr);
void regSearchName(struct region *head, char *name);
void regionFreeMem(struct region *head);