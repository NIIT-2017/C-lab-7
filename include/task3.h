struct SYM
{
    unsigned char ch;
    float freq;
};

typedef struct SYM TSYM;     //struct variable
typedef TSYM* PSYM;         // struct pointer
void initializeTable(SYM* table, char* str, float total);
void makeTable(SYM* table, char *str, float total);
void printTable(SYM* table);
int cmp(const void* a, const void* b);
void chomp(char* string);