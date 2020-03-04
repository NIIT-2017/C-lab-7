#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10
struct  Node
{
    Node* left, * right;
    char word[SIZE];
    unsigned int number;
    int heightLeft, heightRight;
};
Node *makeTree(const char*);
void computeHeight(Node* head);
Node* balanceSubTree(Node* head);
Node* balanceAllTree(Node* head);
void printTree(Node* head);
void searchTree(Node* head, char* word);