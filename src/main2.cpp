/*
 Задача №2
 
 Написать программу, которая анализирует исходный код файла на языке Си и
 выводит таблицу встречаемости ключевых слов языка. Ключевые слова хранятся в отдельном файле.
 Пояснение
 
 Работа программы осуществляется в несколько этапов:
 
 Вручную создается файл с ключевыми словами языка С.
 Открывается файл с ключевыми словами и строится бинарное дерево с упорядоченными данными для всех слов.
 Открывается анализируемый файл с текстом программы и читается по словами (или символам);
 Полученные строки (слова) ищутся в бинарном дереве;
 Еслисловосовпадает с хранящимсявдереве, увеличиваем счётчиквстречаемости данного слова;
 Состав
 
 Программа должна включать в себя следующие функции:
 
 chomp - удаление символа конца строки.
 makeTree - создание дерева ключевых слов.
 searchTree - поиск в дереве текущей комбинации символов.
 printTree - печать списка ключевых слов и их количества.
 main - главная функция программы.
 Создаются три файла: task2.h,task2.c,main2.c.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "task2.h"

int main (int argc, char * argv[]){
    char buf [256];
    struct KEYWORD * root = nullptr;
    struct KEYWORD * item = nullptr;
    FILE * fp;
    fp = fopen("keywords.txt", "rt");
    while (fgets(buf, 256, fp)) {
        chomp(buf);
        root = buildTree(root, buf);
        
    }
    fclose(fp);
    
    char * fileName; // имя для файла пользователя
    if (argc < 1){
        printf("Error! Restart programm and enter name of file!\n");
        return 1;
    }
    else
    fileName = argv[1];
    fp = fopen(fileName, "rt");
    
    while(fscanf(fp, "%s", buf)==1){
        item = searchTree(root, buf);
        if(item != NULL)
            item->count++;
    }
    printTree(root);
    return 0;
}
