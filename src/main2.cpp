#include "task2.h"
int main2()
{
    Node* head = makeTree("Input2.txt");
    computeHeight(head);
    head=balanceAllTree(head);
    FILE* codeFIle = fopen("task2.txt", "r");
    char buf[40];
    while (!feof(codeFIle))
    {
        fscanf(codeFIle, "%s", buf);
        searchTree(head, buf);
    }
    printTree(head);
    return 0;
}