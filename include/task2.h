struct NODE
{
	char word[256];
	unsigned long count;
	struct NODE *left;
	struct NODE *right;
};
typedef struct NODE TNODE;
typedef TNODE* PNODE;
PNODE makeTree(PNODE root, char *word);
void searchTree(PNODE root, char *word);
void printTree(PNODE root);