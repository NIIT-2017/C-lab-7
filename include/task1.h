typedef struct countries TCOUNTRIES;
typedef TCOUNTRIES * PCOUNTRIES;
typedef ITEM TITEM;
typedef TITEM * PITEM;

struct countries
{
    char country [3];
    char region_code [3];
    char name[30];
};

struct ITEM
{
    PCOUNTRIES countries;
    struct ITEM * next;
    struct ITEM * prev;
};

PITEM creatList (PCOUNTRIES countries);

PITEM addToTail(PITEM tail, PCOUNTRIES countries);

int countList(PITEM head);
PITEM findByCountry(PITEM head, char*county);
PITEM findByCode(PITEM head, char*name);
void printCountry(PITEM item);
