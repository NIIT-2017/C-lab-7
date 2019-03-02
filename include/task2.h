struct KEYWORD {
    char word [30];
    int count = 0;
    struct KEYWORD * left;
    struct KEYWORD * right;
};

void chomp(char * buf);
struct KEYWORD * buildTree(struct KEYWORD * item, char * buf);
struct KEYWORD * searchTree(struct KEYWORD * item, char * buf);
void printTree(struct KEYWORD * root);

