#define SIZE 256

typedef struct simbol
{
	unsigned char code;
	float occurrence;
} SYM;

void initialize(SYM* psimbol_fp); //Initialization of a array SYM by empty contents
int analysis_fp(SYM* psimbol_fp, FILE* fp); //The analysis of a contained file
void calculation_occurrence(SYM* psimbol_fp, int count_simbol); //Calculation of frequency of occurrence of symbols
void sort(SYM* psimbol_fp); //Sorting of a array SYM
void print_simbols(SYM* psimbol_fp); //Print of symbols and their frequencies of occurrence
