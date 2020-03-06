#include <stdio.h>
#define NUMBERCHAR 256

typedef struct sym
{
	unsigned char ch;
	long double repeatability;
	int count;
}symST;

void fillTable(FILE* fp, sym* charOccurrence);
int compar(const void* p1, const void* p2);