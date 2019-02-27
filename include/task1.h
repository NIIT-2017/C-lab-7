#ifndef TASK1_H
#define TASK1_H

struct REGION
{
	char countrySymbs[10];
	char number[10];
	char regionName[256];
};
typedef struct REGION REGION;

typedef struct ITEM
{
	REGION * region;
	struct ITEM * next;
	struct ITEM * prev;
}ITEM;

REGION * CreateRegion(char * name);
ITEM * FindByRegionName(ITEM * list, char * regName);
//ITEM * FindByRegionNumb(ITEM * list, char * regNumb);
void FindAllRegionsBySymbs(ITEM * list, char * countrySymbs);
void printRegion(ITEM * item);
void DeleteList(ITEM *phead);

ITEM *Add2List(ITEM *phead, const REGION *reg);

#endif