struct NODE {
	char word[200];
	int count;
	struct NODE* left;
	struct NODE* right;
};

void chomp(char* line);
struct NODE* makeTree(struct NODE *root,char *word);
struct NODE* searchTree(struct NODE* root, char* word);
void printTree(struct NODE* root);

