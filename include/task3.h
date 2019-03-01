struct SYM                           //представление символа
{
        unsigned char ch;            //ASCII-код
        float freq;                  //частота встречаетмости
        char code[256];              //массив для нового кода
        struct SYM *left;            //левый потомок в дереве
        struct SYM *right;           //правый потомок в дереве
};

struct SYM *buildTree(struct SYM *psym[],int N);

