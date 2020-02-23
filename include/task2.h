
struct NODE {
    char word[100];
    int count;
    struct NODE* left;
    struct NODE* right;
};

typedef struct NODE TNODE;    //struct variable
typedef TNODE* PNODE;         // struct pointer 
void chomp(char* string);
PNODE makeTree(PNODE root, char* word);
PNODE searchTree(PNODE root, char* word);
void printTree(PNODE root);
void searchWords(char* str, PNODE kwtree);