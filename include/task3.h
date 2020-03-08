#include <stdio.h>
struct SYM
{
	unsigned char symbol;
	float frequency;
	long int count;
};
void loadingChart(SYM* top);
void letterCount(SYM* top, FILE* fp);
void printChart(SYM* top);
int sopostavl(const void* p1, const void* p2);