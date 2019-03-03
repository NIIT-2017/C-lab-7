#define N 256

struct NODE
{
	int count;
	char word[N];
	struct NODE *left;
	struct NODE *right;
};

struct NODE *makeTree(struct NODE *root, char *word);
void searchTree(struct NODE *root, char *buf);
int searchMax(struct NODE *root);
void printTree(struct NODE *root);