#define N 256

struct NODE
{
	char word[N];
	int freq;
	struct NODE *left;
	struct NODE *right;
};

typedef struct NODE NODE;
typedef NODE* PNODE;

PNODE makeTree(PNODE root, char * word);
PNODE searchTree(PNODE root, char * word);
void printTree(PNODE root);
void chomp(char * string);

