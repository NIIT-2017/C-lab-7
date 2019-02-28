#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task2.h"

int main()
{
    struct NODE *root=NULL, *word=NULL;
    FILE *fp=fopen("keyW.txt","rt");
    FILE *fp2 = fopen("task8.cpp","r");        // открываем проверяемый файл с кодом С

    if(fp == NULL)                              // исключение ошибки чтения/нахождения файла
    {
        puts("File fp not found!");
        return 1;
    }

    if(fp2 == NULL)                             // исключение ошибки чтения/нахождения файла
    {
        puts("File fp2 not found!");
        return 1;
    }


    char buf[SIZE];
    while(!feof(fp))
    {
        fscanf(fp,"%s",buf);
        root=makeTree(root,buf);
    }

    printf("Таблица ключевых слов языка Си в контрольном файле keyW.txt \n");
    printTree(root);


    fclose(fp);

    while(fscanf(fp2,"%s",buf) == 1)
    {
        word = searchTree(root, buf);
        if(word != NULL)
            word->count++;
    }
    fclose(fp2);
    printf("\nТаблица встречаемости ключевых слов языка Си в файле task8.cpp \n");
    printTree(root);

    return 0;
}
