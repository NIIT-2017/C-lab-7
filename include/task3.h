#define SIZE 256

struct SYM
{
    unsigned char ch = 0;
    long count = 0;
    float frequency = 0;
    struct SYM * left;
    struct SYM * right;
};

typedef struct SYM TSYM;
typedef TSYM * PSYM;

void initData(TSYM data[SIZE]);
void sortData(TSYM data[SIZE]);
void printData(TSYM data[SIZE]);