struct NAME_REC
{
	char country[10];
	char code[30];
	char name[50];
};

typedef struct NAME_REC TNAME_REC;
typedef TNAME_REC * PNAME_REC;

struct ITEM
{ 
	PNAME_REC name_rec;
	struct ITEM *next;
	struct ITEM *prev;
};

typedef struct ITEM TITEM;
typedef TITEM * PITEM;

PITEM createList(PNAME_REC name_rec);
PNAME_REC createCountry(char *line);
PITEM addToTail(PITEM tail,
			   PNAME_REC name_rec);
int countList(PITEM head);
PITEM findByCountry(PITEM head,char *name);
void printCountry(PITEM item);
PITEM findByName(PITEM head, char* name);
void findAllCountries(PITEM head, char* country);