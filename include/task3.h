struct SYM
{
	char symbol;
	float freq=0;
	unsigned long count=0;
	struct SYM * left;
	struct SYM *right;
};

struct SYM* createTree(struct SYM*root, struct SYM item);
void printTree(struct SYM * root);