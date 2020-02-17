struct SYM // представление символа
{
	unsigned char ch; // ASCII-код
	float freq; // частота встречаемости
};

int cmp(const void* a, const void* b);
void print(struct SYM* syms);
