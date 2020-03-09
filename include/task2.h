struct NODE
{
    char word[256];
    unsigned long count;
    struct NODE* left;
    struct NODE* right;
};
typedef struct NODE TNODE;
typedef TNODE* PNODE;
PNODE makeTree(PNODE root, char* word);
PNODE searchTree(PNODE root, char* word);
void printTree(PNODE root);
void  chomp(char* str);
void read(PNODE root, char* buf);
int height(PNODE root);
PNODE turnLeft(PNODE root);
PNODE turnRight(PNODE root);
PNODE balanceTree(PNODE root);
