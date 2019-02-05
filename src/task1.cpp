#include "task1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ITEM* createList(struct CODE_REG *code_reg)
{
	struct ITEM *item = (struct ITEM*)malloc(sizeof(struct ITEM));
	item->code_reg = code_reg;
	item->previuos = NULL;
	item->next = NULL;
	return item;
}

struct CODE_REG* createRecord(char* line)
{
	struct CODE_REG* record = (struct CODE_REG*)malloc(sizeof(struct CODE_REG));
	int i = 0;
	while (*line && *line != ',')
		record->country[i++] = *line++;
	record->country[i] = 0;
	*line++;
	i = 0;
	while (*line && *line != ',')
		record->code[i++] = *line++;
	record->code[i] = 0;
	*line++;
	*line++;
	i = 0;
	while (*line && *line != '\n'&&*line!='\"')
		record->region[i++] = *line++;
	record->region[i] = 0;
	return record;
}

struct ITEM* addToTail(struct ITEM* tail, struct CODE_REG* record)
{
	struct ITEM* item = createList(record);
	if (tail != NULL)
	{
		item->previuos = tail;
		tail->next = item;
	}
	return item;
}

void findByCode(struct ITEM* item,char *line)
{
	while (item)
	{
		if (_strcmpi(item->code_reg->country,line)==0)
			printf("Country-%s code-%s region-%s\n", item->code_reg->country, item->code_reg->code, item->code_reg->region);
		item = item->next;;
	}

}

struct ITEM* findByRegion(struct ITEM* item, char* line)
{
	while (item)
	{
		if (_strcmpi(item->code_reg->region, line) == 0)
			return item;
		else
			item = item->next;
	}
	return NULL;
}