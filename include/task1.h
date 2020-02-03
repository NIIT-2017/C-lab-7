struct REGIONS
{
    char cCode[3]; // country code     symbols
    char rCode[3]; // region code      number
    char rName[50]; // region name     region
};

typedef struct REGIONS TREGIONS;

typedef TREGIONS * PREGIONS;

struct ITEM
{
    PREGIONS regions;
    struct ITEM * next;
    struct ITEM * prev;
};

typedef struct ITEM TITEM;
typedef TITEM * PITEM;

PITEM createList(PREGIONS regions);
PREGIONS createName(char * line);
PITEM addToTail(PITEM tail, PREGIONS regions);

int countList(PITEM head);

void findByCCode(PITEM head, char * cCode);

PITEM findByRName(PITEM head, char * rName);

void printItem(PITEM item);