#include "task1.h"

Node* makeList(const char* name)
{
    FILE* input = fopen(name, "r");
    Node* head=0,*current=0;
    char buf[BUFSIZE];
    fgets(buf, BUFSIZE, input);
    while (!feof(input))
    {
        if (current)
        {
            current->next = (Node*)malloc(sizeof(Node));
            current = current->next;
            current->next = 0;
        }
        else
            current = (Node*)malloc(sizeof(Node));
        if (!head)
            head = current;
        fgets(buf, BUFSIZE, input);
        for (int i = 0; i < 2; i++)
        {
            current->ISO[i] = buf[i + 1];
            current->code[i] = buf[i + 4];
        }
        current->ISO[2] = '\0';
        int i = 9;
        while (buf[i] != '\n' && buf[i] != '\0'&&buf[i]!='"')
        {
            current->name[i - 9] = buf[i];
            i++;
        }
        current->name[i-9] = '\0';
    } 
    return head;
}
void searchByISO(const char* iso,Node *head)
{
    while (head)
    {
        if (!strcmp(head->ISO, iso))
            printf("\n%s %d %s", iso, head->code, head->name);
        head = head->next;
    }
}
void searchByName(const char* name, Node* head)
{
    while (head)
    {
        if (!strcmp(head->name, name))
            printf("\n%s %d %s", head->ISO, head->code, head->name);
        head = head->next;
    }
}