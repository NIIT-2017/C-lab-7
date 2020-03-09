struct REGION_REC
{
    char country[10];
    char code[10];
    char name[50];
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

PITEM createList(PREGION_REC country_rec);
PREGION_REC createRegion(char* line);
PITEM addToTail(PITEM tail,
    PREGION_REC region_rec);
int countList(PITEM head);
PITEM findByCountry(PITEM head, char* region);
void printRegion(PITEM item);
PITEM findByName(PITEM head, char* name);
void findAllCountries(PITEM head, char* country);