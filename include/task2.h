#define SIZE 256

struct NODE
{
    int count;
    char word[SIZE];
    struct NODE *left;
    struct NODE *right;
};

struct NODE * makeTree(struct NODE *root,char *word);
struct NODE * searchTree(struct NODE *root,char *word);
void printTree(struct NODE *root);
void chomp(char * string);
