struct TERRITORY_REC                      //NAME_REC
{
    char letterDesignation[20];     //name
    char code[3];
    char countryName[256];
};

typedef struct TERRITORY_REC TTERRITORY_REC;   //struct variable
typedef TTERRITORY_REC* PTERRITORY_REC;       //struct pointer


struct ITEM
 {
    PTERRITORY_REC letterDesignation_rec;        //name_rec;
    struct ITEM* next;
    struct ITEM* prev;
};

typedef struct ITEM TITEM;   //struct variable
typedef TITEM* PITEM;        /// struct pointer

void chomp(char* string);
PITEM createList(PTERRITORY_REC letterDesignation_rec);
PTERRITORY_REC createName(char* line);
PITEM addToTail(PITEM tail, PTERRITORY_REC letterDesignation_rec);
int countList(PITEM head);
PITEM findByLetterDesignation(PITEM head, char* letterDesignation);
PITEM showSuitableCountries(PITEM head, char* letterDesignation);
PITEM findByCountryName(PITEM head, char* countryName);      // findByName(PITEM head, char* name);
void printLetterDesignation(PITEM item);