#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

struct SYM
{
	unsigned char ch; // ASCII-код
	float freq; // частота встречаемости
	char code[256]; // массив для нового кода
	struct SYM *left; // левый потомок в дереве
	struct SYM *right; // правый потомок в дереве
};

long getArr(const char * fileName, int * arr);
int arr2SYM(int * arr, long count, struct SYM ** pSYM);
void sort_pArr(struct SYM ** pSYM, int size);
