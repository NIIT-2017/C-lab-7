#define _CRT_SECURE_NO_WARNINGS

typedef struct region
{
	char cod_country[5];
	char index[5];
	char town[50];
} TRegion;
typedef TRegion* PRegion;

typedef struct item   
{
	PRegion region; 
	struct item *next;
	struct item *prev;
} TItem;
typedef TItem* PItem;

PItem createList(PRegion pregion);
PRegion createRegion(char* line);
PItem addToTail(PItem tail, PRegion pregion);

int countList(PItem head);
void findOllData(PItem head, char* town);

PItem findDesiredRegion(PItem head, char* town);
void printDesiredRegion(PItem item);
