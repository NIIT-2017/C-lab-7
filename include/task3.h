struct SYM // ������������� ������� 
{
	unsigned char ch; // ASCII-��� 
	float freq; // ������� ������������� 
	char code[256]; // ������ ��� ������ ���� 
	struct SYM *left; // ����� ������� � ������ 
	struct SYM *right; // ������ ������� � ������ 
};

void makeSymArray(struct SYM *buf, char letter);
void initializeArray(struct SYM* buf);
void calculateFreq(struct SYM*buf, int count);
int comp(const void * x1, const void * x2);
void printArray(struct SYM* buf);