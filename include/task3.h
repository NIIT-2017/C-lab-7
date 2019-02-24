struct SYM 
{
	unsigned char ch; // ASCII-код 
	float freq; // частота встречаемости 
};

typedef struct SYM SYM;
SYM * MakingTableOfFrequencies(SYM * syms, const char * fileName);
SYM * SortingArrByFrequencies(SYM * syms);
void PrintSym(SYM a);
void PrintTableWithFrequencies(SYM * syms);