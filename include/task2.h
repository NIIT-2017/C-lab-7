struct tnode
{
	char word[256];
	struct tnode *left;
	struct tnode *right;
	int count;
};
void chomp(char * line);
void printTree(struct tnode *p);
struct tnode * makeTree(struct tnode*tree, char *word);
struct tnode *searchTree(struct tnode*tree, char *word);
