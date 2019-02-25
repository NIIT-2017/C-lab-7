struct SYM // представление символа 
{
	unsigned char ch; // ASCII-код 
	float freq; // частота встречаемости 
	char code[256]; // массив для нового кода 
	struct SYM *left; // левый потомок в дереве 
	struct SYM *right; // правый потомок в дереве 
};

void makeSymArray(struct SYM *buf, char letter);
void initializeArray(struct SYM* buf);
void calculateFreq(struct SYM*buf, int count);
int comp(const void * x1, const void * x2);
void printArray(struct SYM* buf);