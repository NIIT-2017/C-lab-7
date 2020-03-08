#include "task3.h"
#include <ctype.h>
void loadingChart(SYM* top)
{
	for (int i = 0; i < 256; i++)
	{
		top[i].symbol = i;
		top[i].frequency = 0;
		top[i].count = 0;
	}
}
void printChart(SYM* top)
{
	for (int i = 0; i < 256; i++)
	{
		if (top[i].symbol == 0)
			printf("symbol #%3i : \"\\0\", frequency = %f\n", top[i].symbol, top[i].frequency);
		else if (top[i].symbol == 9)
			printf("symbol #%3i : \"\\t\", frequency = %f\n", top[i].symbol, top[i].frequency);
		else if (top[i].symbol == 10)
			printf("symbol #%3i : \"\\n\", frequency = %f\n", top[i].symbol, top[i].frequency);
		else if (isspace(top[i].symbol))
			printf("symbol #%3i : \"WS\", frequency = %f\n", top[i].symbol, top[i].frequency);
		else if (iscntrl(top[i].symbol))
			printf("symbol #%3i : \"CS\", frequency = %f\n", top[i].symbol, top[i].frequency);
		else
			printf("symbol #%3i :  \"%c\", frequency = %f\n", top[i].symbol, top[i].symbol, top[i].frequency);
	}
}
void letterCount(SYM* top, FILE* fp)
{
	unsigned char c;
	int ch;
	long int counter = 0;
	while ((ch = fgetc(fp)) != EOF)
	{
		c = (unsigned char)ch;
		top[c].count++;
		counter++;
	}
	for (int i = 0; i < 256; i++)
		top[i].frequency = (float)top[i].count / counter;
}
int sopostavl(const void* p1, const void* p2)
{
	SYM* f1 = (SYM*)p1;
	SYM* f2 = (SYM*)p2;
	if (f1->frequency >(f2->frequency)) 
		return -1;
	if (f1->frequency == (f2->frequency)) 
		return 0;
	if (f1->frequency < (f2->frequency)) 
		return 1;
}