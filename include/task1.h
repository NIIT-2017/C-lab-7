struct REC
{
	char country[10];
	char code[10];
	char region[256];
	
};


struct ITEM
{
	struct REC *P_REC;
	struct ITEM *next;
	struct ITEM *prev;
};

struct ITEM * createList(struct REC *P_REC);
struct REC * createRec(char*line);
struct ITEM * addToTail(struct ITEM *tail, struct REC *P_REC);
int countList(struct ITEM *head);
struct ITEM * findByCountry(struct ITEM * head, char *country);
struct ITEM * findByCode(struct ITEM *head, char*code);
struct ITEM * findByRegion(struct ITEM * head, char *region);
void printCountry(struct ITEM* item);


