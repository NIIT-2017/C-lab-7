struct CODE_REG {
	char country[5];
	char code[5];
	char region[50];
};

struct ITEM {
	struct CODE_REG *code_reg;
	struct ITEM *next;
	struct ITEM *previuos;
};

struct ITEM* createList(struct CODE_REG *code_reg);
struct CODE_REG* createRecord(char* line);
void findByCode(struct ITEM *item, char* line);
struct ITEM* findByRegion(struct ITEM *item, char* line);
struct ITEM* addToTail(struct ITEM* tail, struct CODE_REG* record);
