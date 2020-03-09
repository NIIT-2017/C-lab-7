struct KeyWords
{
	char word[20];
	int count;
	KeyWords* left;
	KeyWords* right;
};
char* chomp(char* buf);
KeyWords* makeTree(KeyWords* root, FILE* fp);
void searchTree(char* buf, KeyWords* item);
void printTree(KeyWords* root);
void clearTree(KeyWords* root);
void checkText(FILE* fp, KeyWords* root);