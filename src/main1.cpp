/*
 Задача №1
 
 Написать программу, создающую связанный список с записями о регионах и их
 кодах в соответствии с содержанием файла данных
 Пояснение
 
 Файл скачивается по адресу: http://introcs.cs.princeton.edu/java/data/fips10_4.csv Программа должна поддерживать следующие функции:
 
 Формирование списка на основе данных файла.
 Поиск и вывод всех данных по буквенному обозначению страны.
 Поиск конкретного региона по названию.
 Состав
 
 Создаются три файла: task1.h,task1.c,main1.c.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"

int main(){
    FILE *fp;
    char userChoice;
    char str[20] = { '\0' }; // массив для слов поиска
    int count=0; // счетчик элементов списка
    char buf[128]; // массив для каждого элемента списка
    PITEM item, head = nullptr, tail = nullptr; // текущий элемент списка, головной, хвостовой
    fp=fopen("fips10_4.csv","rt");
    if(!fp){
        perror("File fips10_4.csv:");
        exit(1);
    }
    fgets(buf, 128, fp);
    while (fgets(buf, 128, fp)) {
        if(count == 0){
            head = creatList(creatCountries(buf));
            tail = head;
        }else{
            tail = addToTail(tail, creatCountries(buf));
        }
        count++;
    }
    fclose(fp);
    printf("Total items: %d\n", countList(head));
    printf("Press C [Enter] if you want to find country by its name\n");
    printf("Press R [Enter] if you want to find country by its code\n");
        printf("What do you whan? ...\t");
    scanf("%c", &userChoice);
    if(userChoice == 'C'){
        scanf("%s", str);
        item = findByCountry(head, str);
        if(item == NULL)
            printf("Not found!\n");
        else
            printCountry(item);
        for(int i = 0; i<20; i++)
            str[i] = '\0';
    }
    if(userChoice == 'R'){
        scanf("%s", str);
        findByCode(head, str);
        
    }
    return 0;
}
