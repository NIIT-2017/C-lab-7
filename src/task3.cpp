//
//  C-task3.cpp
//  C-lab-7
//
//  Created by Антон Петров on 23/02/2019.
//  Copyright © 2019 Антон Петров. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task3.h"

/*функция считывает данные из файла,
 считает количество введенных символов и считает частоту встречаемости
 */
void fillBuf(struct SYM buf[256], char *fileName){
    FILE * fp;
    char ch;
    int count = 0;
    fp = fopen(fileName, "rt");
    //считываем символы из файла и считаем, сколько раз встретился каждый символ
    while((ch=fgetc(fp)) != EOF){
        buf[(int)ch].count++; // счетчик для каждого символа (необходимо использовать явное приведение типов для ch)
        count++; // общий счетчик символов
    }
    //считаем частоту для каждого символа
    for(int i = 0; i < 256; i++){
        buf[i].ch = (char)i;
        buf[i].freq = (float)(buf[i].count) / count;
    }
    fclose(fp);
    return;
}

/*
 Функция добавляет листья на дерево
 */
struct SYM * addNode (struct SYM * root, struct SYM node) {
    //сначала создаем корень, который примет значения первого символа
    if (root == NULL){
        root = (struct SYM*)malloc(sizeof(struct SYM)); // выделяем память под структуру SYM
        root->ch = node.ch;
        root->count = node.count;
        root->freq = node.freq;
        root->left = nullptr;
        root->right = nullptr;
    }
    //далее раскидываем листья:меньшие влево, большие вправо
    else if(root->freq > node.freq)
        root->left = addNode(root->left, node);
    else
        root->right = addNode(root->right, node);
    
    return root;
}
/*
 функция для построения дерева
 */
struct SYM * buildTree (struct SYM buf[256]){
    struct SYM * root = NULL; // указатель на корень
    //для каждого обнаруженного символа (находится в структуре buf) вызываем функцию добавления листьев addNode
    for(int i = 0; i<256; i++){
        root = addNode(root, buf[i]);
    }
    return root;
}
/*
 функция печатает дерево
 */
void printTree (struct SYM * root){
    if(root){
        printTree(root->right);
        if(root->freq > 0)
            printf("Char '%c' has frequency: %7.5f and quantity: %4d\n", root->ch, root->freq, root->count);
        printTree(root->left);
        return;
    }
}



