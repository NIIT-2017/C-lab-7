struct REGION
{
	char iso[5];
	char code[10];
	char name[256];
	struct REGION *next;
};

typedef struct REGION REG;

struct REGION *create(char *buf);
void print(REG *event);
void add(REG *event, char *buf);
void searchByIso(REG *event, char *iso);
void searchByName(REG *event, char *name);