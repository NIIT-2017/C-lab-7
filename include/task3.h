#include <stdio.h>

struct SYM
{
    unsigned char symbol;
    float frequency;
    long int count;
};

void fillChart(SYM* chart);
void printChart(SYM* chart);
void findOut(SYM* chart, FILE* fp);
int compar(const void* p1, const void* p2);
