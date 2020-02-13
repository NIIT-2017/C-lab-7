struct REGION_REC
{
	char country[3];
	char region[3];
	char name[256];
};

typedef struct REGION_REC TREGION_REC;
typedef TREGION_REC* PREGION_REC;

struct ITEM
{
	PREGION_REC region_rec;
	struct ITEM* next;
	struct ITEM* prev;
};

typedef struct ITEM TITEM;
typedef TITEM* PITEM;

PITEM createList(PREGION_REC name_rec);
PREGION_REC createName(char* line);
PITEM addToTail(PITEM tail, PREGION_REC name_rec);
int countList(PITEM head);
PITEM findByName(PITEM head, char* name);
PITEM findByCountryId(PITEM head, char* name);
void printItem(PITEM item);
