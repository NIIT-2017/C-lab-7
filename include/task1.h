#ifndef TASK1_H
#define TASK1_H

struct REGION//element for a list
{
	char symbols[3];//box for symbols
	char number[3];//box for number
	char region[150];//box for the name of region
};

typedef struct REGION REGION;
typedef REGION * PREGION;//pointer to REGION element

struct ITEM//container for a list
{
	PREGION region_rec;//pointer to REGION element
	struct ITEM *next;//pointer to the next element
	struct ITEM *prev;//pointer to the previous element
};

typedef struct ITEM ITEM;
typedef ITEM * PITEM;//pointer to the ITEM element

PITEM createList(PREGION region_rec);//creating a list

PREGION createRegion(char *line);//creating region

PITEM addToTail(PITEM tail, PREGION region_rec);

PITEM findByRegion(PITEM head, char *region);

void findBySymbols(PITEM head, char *symbols);

void printRegion(PITEM item);

 #endif