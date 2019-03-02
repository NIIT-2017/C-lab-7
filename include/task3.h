// структура листа в дереве (описание структуры узла)
struct SYM {
    unsigned char ch; // код ASCII символа
    int count = 0; // количество таких символов в тексте
    float freq; // частота встречаемости
    struct SYM * left; // указатель на левый лист
    struct SYM * right; // указатель на правый лист
};

void fillBuf(struct SYM * buf, char *fileName);
struct SYM * addNode (struct SYM * root, struct SYM * node);
struct SYM * buildTree (struct SYM buf [256]);
void printTree (struct SYM * root);
