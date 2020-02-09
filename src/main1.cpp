#include "task1.h"
int main1()
{
    Node* head = makeList("Input.csv");
    printf("Enter two symbols : ");
    char iso[3];
    scanf("%s", iso);
    searchByISO(iso, head);
    printf("\nEnter name : ");
    char name[30];
    scanf("%s", name);
    searchByName(name, head);
    return 0;
}