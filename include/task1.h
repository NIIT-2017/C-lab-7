#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <clocale>

#define BUF 256

struct NAME_REC {
	char reg[3];
	char code[3];
	char name[BUF];
};

typedef struct NAME_REC TNAME_REC;
typedef TNAME_REC* PNAME_REC;

struct ITEM {
	PNAME_REC name_rec;
	struct ITEM* next;
	struct ITEM* prev;
};

typedef struct ITEM TITEM;
typedef TITEM* PITEM;

PITEM createList(PNAME_REC name_rec);
PNAME_REC createName(char* line);
PITEM addToTail(PITEM tail, PNAME_REC name_rec);
int countList(PITEM head);
PITEM findByName(PITEM head, char* name);
PITEM findByCode(PITEM head, char* code);
PITEM findByRegion(PITEM head, char* reg);
void printRegion(PITEM item);
void printCode(PITEM item);
void printName(PITEM item);
void printItem(PITEM item);

//PITEM findByItem(PITEM item);
