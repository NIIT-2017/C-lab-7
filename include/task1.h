#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#define BUFSIZE 70
struct Node {
    Node* next;
    char ISO[3],name[30],code[3];
};
Node* makeList(const char* name);
void searchByISO(const char* iso, Node* head);
void searchByName(const char* name, Node* head);