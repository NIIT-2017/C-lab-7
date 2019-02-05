struct SYM {
	char symbol;
	int count=0;
	float freq;
	struct SYM *left;
	struct SYM *right;
};

struct SYM *createTree(struct SYM arr[256]);
struct SYM *addNode(struct SYM *root, struct SYM item);
void printTree(struct SYM *root);
void fillArr(struct SYM arr[256],char *filename);
