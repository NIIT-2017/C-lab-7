#ifndef TASK3_H
#define TASK3_H
#define SIZE1 256
struct SYM 
{
	unsigned char ch; // ASCII-код 
	float freq; // частота встречаемости 
};

typedef struct SYM SYM;
SYM * MakingTableOfFrequencies(SYM * syms, const char * fileName, int * pcountUniqSymb);
SYM * SortingArrByFrequencies(SYM * syms, int countUniqSymb);
void PrintSym(SYM a);
void PrintTableWithFrequencies(SYM * syms, int countUniqSymb);

#endif