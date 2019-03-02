/*
Написать программу, которая строит таблицу встречаемости символов
для произвольного файла, имя которого задаётся в командной строке.
Программа должна выводить на экран таблицу встречаемости,
отсортированную по убыванию частоты
Пояснение

В программе необходимо определить структурный тип SYM, в котором нужно хранить код символа и частоту встречаемости (вещественное число от 0 до 1). После анализа файла, массив структур SYM должен быть отсортирован по частоте.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "task3.h"

int main (int argc, char * argv[]){
    SYM buf[256]; // массив из 256 элементов (по элементу на каждый символ ASCII)
    struct SYM * root = nullptr; // указатель на корень
    char * fileName; // массив под имя файла
    if (argc < 1){
        printf("Error! Restart programm and enter name of file!\n");
        return 1;
    }
    else
        fileName = argv[1];
    fillBuf(buf, fileName);
    root = buildTree(buf);
    printTree(root);
    
    return 0;
    
}


