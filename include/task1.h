struct REGION
{
	char country[20];
	char number[5];
	char name[256];
};

typedef struct REGION TREGION;
typedef TREGION* PREGION;

struct ITEM
{
	PREGION region;
	struct ITEM* next;
	struct ITEM* prev;
};

typedef struct ITEM TITEM;
typedef TITEM* PITEM;

PITEM createList(PREGION region);
PREGION createName(char* line);
PITEM addToTail(PITEM tail,
	PREGION region);
int countList(PITEM head);
PITEM findByCountry(PITEM head, char* country);
PITEM findByRegion(PITEM head, char* name);
void printName(PITEM item);
