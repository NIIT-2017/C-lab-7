#define N 256

struct SYM {
	unsigned char ch;
	int count = 0;
	float freq;
	struct SYM * left;
	struct SYM * right;
};

void filling(struct SYM * buf, char *file);
struct SYM * buildTree(struct SYM buf[256]);
void printTree(struct SYM * root);