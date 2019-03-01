struct REGION
{
	char iso[50];
	char code[50];
	char name[50];
	struct REGION *next;
};

typedef struct REGION TREGION;

TREGION *create(char *buf);
void add(TREGION *head, char *buf);
void SearchIso(TREGION *head, char *iso);
void SearchName(TREGION *head, char *name);