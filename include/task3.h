#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SYM                    //представление символа
{
        unsigned char ch;     //ASCII-код
        float freq;           //частота встречаетмости
        char code[256];       //массив для нового кода
        SYM *left;            //левый потомок в дереве
        SYM *right;           //правый потомок в дереве
};

struct SYM *buildTree(struct SYM *psym[],int N);    //рeкурсивная функция создания дерева Хаффмана
