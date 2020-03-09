struct NODE
{
	char  word[256]; // данные
	long  count;  // счётчик
	struct NODE* left;  // левый потомок
	struct NODE* right; // правый потомок
};
//typedef struct NODE TNODE;
//typedef TNODE* PNODE;
struct NODE* makeTree(struct NODE* root, char* word);
void printTree(struct NODE* root);
void searchTree(struct NODE* root, char* searchword);
void chomp(struct NODE* root);

