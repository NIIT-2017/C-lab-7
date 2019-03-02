//
//  task1.cpp
//  C-lab-7
//
//  Created by Антон Петров on 17/02/2019.
//  Copyright © 2019 Антон Петров. All rights reserved.
///Users/antonpetrov/Desktop/C-lab-7/C-lab-7/task1.h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "task1.h"

//функция содает связанный лист. Возвращает указатель на item (т.е. на 1 элемент связанного списка)
PITEM creatList(PCOUNTRIES countries){
    //создаем динамический массив под элемент списка
    PITEM item=(PITEM)malloc(sizeof(TITEM));
    //заполняем структуру последовательно обращаясь к кажому ее элементу
    item->countries = countries; // первый элемент заполняется структурой struct countries
    item->next = NULL; // указатели оставляем
    item->prev = NULL; // пустыми
    return item; // возвращаем готовый элемент списка
}

//функция записывает данные из файла в формате нашей структуры
PCOUNTRIES creatCountries(char *line){
    int i = 0; // счетчик символов вводимых в каждую структуру
    //объявляем динамичный массив типа countries
    PCOUNTRIES rec = (PCOUNTRIES)malloc(sizeof(TCOUNTRIES));
    //внутри цикла идем до запятой и записываем каждый символ
    //в массив в соответствии с типом структуры
    while(*line && *line != ',')
        rec->country[i++] = *line++;
    rec->country[i] = 0;
    line++;
    i=0;
    while(*line && *line != ',')
        rec->region_code[i++] = *line++;
    rec->region_code[i] = 0;
    line++;
    line++;
    i=0;
    while (*line && *line != '\n' && *line != '\"')
        rec->name[i++] = *line++;
    rec->name[i] = 0;
    return rec;
}

/*функция использует указатель на последний элемент структуры ITEM.
 Сначала по указателю next присваевается адрес текущего элемента списка, а в prev передаем значение текущего хвоста
*/
PITEM addToTail(PITEM tail, PCOUNTRIES countries){
    PITEM item = creatList(countries);
    if (tail!=NULL) {
        tail->next = item;
        item->prev = tail;
    }
    return item;
}
//функция считает количесво элементов в списке
int countList(PITEM head){
    int count = 0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}
//функция поиска по буквенному обозначению страны с последующим выводом всех данных о стране
PITEM findByCode(PITEM head, char * country){
    while(head){
            if(strcasecmp(head->countries->country, country)==0) // новая безопасная функция, сравнивающая строки без учета регистра (вместо strcmpi)
                printf("Country - %s / Code - %s / region - %s\n",
                       head->countries->name,
                       head->countries->country,
                       head->countries->region_code);
        head=head->next;
    }
    return NULL;
}
//функция поиска страны по ее названию
PITEM findByCountry(PITEM head, char * name){
    while(head){
            if(strncasecmp(head->countries->name, name, 5)==0) // новая безопасная функция, сравнивающая строки без учета регистра (вместо strcmpi)
                return head;
        head=head->next;
    }
    return NULL;
}

void printCountry(PITEM item){
    if(item!=NULL){
        puts(item->countries->country);
        puts(item->countries->region_code);
        puts(item->countries->name);
    }
}





