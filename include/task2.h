struct keyWord
{
    char word[20];
    int count;
    keyWord* left;
    keyWord* right;
};

char* chomp(char* buf);
keyWord* makeTree(keyWord* root, FILE* fp);
void cleanTree(keyWord* root);
void printTree(keyWord* root);
void searchTree(char* buf, keyWord* item);
void analise(FILE* fp, keyWord* root);