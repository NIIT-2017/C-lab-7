#define N 256

struct REGION
{
	char country[10];
	char code[10];
	char name[256];
};

typedef struct REGION REGION;
typedef REGION * PREGION;

struct ITEM
{
	PREGION region_rec; 
	struct ITEM *next;
	struct ITEM *prev;
};

typedef struct ITEM ITEM;
typedef ITEM * PITEM;

PITEM createList(PREGION region_rec); //create a list

PREGION createRegion (char *line);

PITEM addToTail(PITEM tail,PREGION region_rec);

void printRegion(PITEM item);

int countList(PITEM head);

void findByCountry(PITEM head, char * country);

void findByCode(PITEM head, char * code);

void findByName(PITEM head, char * name);
