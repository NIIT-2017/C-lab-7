struct NODE
{
    char word[32];
    int count;
    struct NODE * left;
    struct NODE * right;
};

typedef struct NODE TNODE;
typedef TNODE * PNODE;

void chomp(char * str);
PNODE makeTree(PNODE root, char * word);
PNODE searchTree(PNODE root, char * word);
void printTree(PNODE root);