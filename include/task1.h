struct REGION
{
	char iso[3] = { 0 };
	char code[3] = { 0 };
	char region[100] = { 0 };
};

typedef REGION TREGION;
typedef TREGION * PREGION;

struct ITEM
{
	PREGION region;
	struct ITEM *next;
	struct ITEM *prev;
};

typedef struct ITEM TITEM;
typedef TITEM * PITEM;

PITEM createList(PREGION region);
PREGION createName(char *buf);
PITEM addToTail(PITEM tail, PREGION region);
int countList(PITEM head);
void findIso(PITEM head, char *region);
void findName(PITEM head, char *city);