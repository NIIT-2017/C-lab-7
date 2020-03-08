#include <stdio.h>
#define LEN 256
#define MAX_LEN 1024

struct SYM {
	unsigned char ch;
	float freq;
};

int cmp(const void* a, const void* b);
char* chomp(char* str);