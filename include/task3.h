#include <stdio.h>
#include <clocale>

#define LEN 256

struct SYM
{
    char ch = 0;
    unsigned long count = 0;
    float freq = 0.0;
};

typedef struct SYM SSYM;
typedef SSYM* PSYM;

void sortSYM(SSYM sym[LEN]);
void printSYM(SSYM sym[LEN]);