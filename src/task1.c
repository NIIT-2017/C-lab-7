#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"

REGION * CreateRegion(char * regInfo)
{
	if (!regInfo)
		return NULL;
	struct REGION * newReg = (struct REGION *)malloc(sizeof(struct REGION));
	int i = 0;
	regInfo++;
	while (*regInfo != ',')
		newReg->countrySymbs[i++] = *regInfo++;
	newReg->countrySymbs[i] = 0;

	i = 0;
	regInfo++;
	while (*regInfo != ',')
		newReg->number[i++] = *regInfo++;
	newReg->number[i] = 0;

	i = 0;
	regInfo+=3;
	while (*regInfo != '"')
		newReg->regionName[i++] = *regInfo++;
	newReg->regionName[i] = 0;
	return newReg;
}

ITEM *Add2List(ITEM *phead, const REGION *reg)
{
	ITEM *p = phead;
	while (p && p->next)
		p = p->next;
	if (!p)
	{
		p = (ITEM *)malloc(sizeof(ITEM));
		p->region = (REGION*)malloc(sizeof(REGION));
		strcpy(p->region->countrySymbs, reg->countrySymbs);
		strcpy(p->region->regionName, reg->regionName);
		strcpy(p->region->number, reg->number);
		p->next = NULL;
		return p;
	}
	p->next = (ITEM *)malloc(sizeof(ITEM));
	p->next->region = (REGION*)malloc(sizeof(REGION));
	strcpy(p->next->region->countrySymbs, reg->countrySymbs);
	strcpy(p->next->region->regionName, reg->regionName);
	strcpy(p->next->region->number, reg->number);
	p->next->next = NULL;
	return phead;
}

ITEM * FindByRegionName(ITEM * list, char * regName)
{
	int counter = 1;
	while (list)
	{
		if (strcmpi(list->region->regionName, regName) == 0)
		{
			printf("position in list (from 1): %d\n", counter);
			printRegion(list);
			return list;
		}
		list = list->next;
		counter++;
	}
	printf("**not found**\n", regName);
	return 0;
}

void FindAllRegionsBySymbs(ITEM * list, char * countrySymbs)
{
	int counter = 1, flag = 0;
	while (list)
	{
		if (strcmpi(list->region->countrySymbs, countrySymbs) == 0)
		{
			printf("position in list (from 1): %d\n", counter);
			printRegion(list);
			flag++;
		}
		list = list->next;
		counter++;
	}
	if (flag == 0)
		printf("**not found**\n");
	return;
}

//ITEM * FindByRegionNumb(ITEM * list, char * regNumb)
//{
//	int counter = 1, flag = 0;
//	while (list)
//	{
//		if (strcmpi(list->region->number, regNumb) == 0)
//		{
//			printf("position in list (from 1): %d\n", counter);
//			printRegion(list);
//			flag++;
//		}
//		list = list->next;
//		counter++;
//	}
//	if (flag == 0)
//		printf("**not found**\n");
//	return 0;
//}

void printRegion(ITEM * item)
{
	printf("\nRegion country symbols: %s   Region number: %s   Region name: %s\n\n", item->region->countrySymbs, item->region->number, item->region->regionName);
}

void DeleteList(ITEM *phead)
{
	if (phead)
	{
		DeleteList(phead->next);
		free(phead->region);
		free(phead);
	}
}