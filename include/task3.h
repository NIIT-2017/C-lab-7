#define N 256

struct SYM 
{
	unsigned char ch; 
	float freq; 
	char code[N]; 
	struct SYM *left; 
	struct SYM *right; 
};

typedef struct SYM SYM;
typedef struct SYM * PSYM;

void createStruct(PSYM syms, unsigned char ch, int count, int * uniqueCount);

void sortStruct(PSYM syms, int size);

void printStruct(PSYM syms, int uniqueCount);
