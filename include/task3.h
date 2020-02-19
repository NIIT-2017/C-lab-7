struct SYM // представление символа
{
    unsigned char ch; // ASCII-код
    float freq; // частота встречаемости
    char code[256]; // массив для нового кода
    struct SYM* left; // левый потомок в дереве
    struct SYM* right; // правый потомок в дереве
};
typedef struct SYM TSYM;
typedef TSYM* PSYM;
int read(FILE* fp, SYM* syms);//записывает файл посимвольно в массив syms
void countFreq(int sum, SYM* syms); // заполняет частоту встречаемости в массиве syms
int cmp(const void* a, const void* b); // сортирует массив syms