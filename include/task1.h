#define SIZE 512
#define REGION_ABBR_SIZE 3
#define REGION_NUM_SIZE 3
#define REGION_NAME_SIZE 50

struct REGION
{
	char abbr[REGION_ABBR_SIZE]; // abbreviation
	char number[REGION_NUM_SIZE];
	char name[REGION_NAME_SIZE];
};


struct ITEM
{
	struct REGION* region;
	struct ITEM* next;
	struct ITEM* prev;
};


struct ITEM* createList(struct REGION* region);
struct REGION* createRegionData(char *line);
struct ITEM* addToTail(struct ITEM* our_item, struct REGION* region);
int countList(struct ITEM* head);
struct ITEM* findByAbbr(struct ITEM* item, char *abbr);
void PrintByAbbr(struct ITEM* item, char *abbr);
struct ITEM* findByName(struct ITEM* item, char *name);
void printRegionData(struct ITEM* item);
int checkStr(struct REGION* region);