struct SYM
{
	unsigned char ch;
	float freq;
};

typedef struct SYM TSYM;
typedef TSYM* PSYM;

void create(PSYM root, unsigned char ch, int count);
void print(PSYM buf);
void Sort(PSYM buf);
static int compar(const void* p1, const void* p2);
