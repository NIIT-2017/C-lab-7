#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define SIZE_OF_BUF 256

struct SYM
{
    char symbol;
    float frequency;
};

typedef struct SYM t_SYM;
typedef t_SYM* p_SYM;

p_SYM create_sym(char ch, float part);
p_SYM* sort_syms(p_SYM* buf);
void print(p_SYM* buf);