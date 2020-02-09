#include "task2.h"
bool compare(char* a, char* b)
{
    int len = strlen(a);
    if (strlen(b) < len)
    {
        len = strlen(b);
    }
    for (int i = 0; i < len; i++)
    {
        if (a[i] < b[i])
            return true;
        if (a[i] > b[i])
            return false;
    }
    return true;
}
Node* createNode( char* word)
{
    Node *head = (Node*)malloc(sizeof(Node));
    head->left = 0;
    head->right = 0;
    head->number = 0;
    sprintf(head->word, "%s", word);
    return head;
}
void addNode(Node* head, char* word)
{
    if (compare(head->word, word))
    {
        if (head->left)
            addNode(head->left, word);
        else
            head->left = createNode(word);
    }
    else
    {
        if (head->right)
            addNode(head->right, word);
        else
        head->right = createNode(word);
    }
}
Node* makeTree(const char* fileName)
{
    FILE* wordsFile = fopen(fileName, "r");
    char buf[SIZE];
    fscanf(wordsFile,"%s",buf);
    Node* head = createNode(buf);
    while (!feof(wordsFile))
    {
        fscanf(wordsFile, "%s", buf);
        addNode(head, buf);
    }
    return head;
}
int getMaxHeight(Node* head)
{
    int maxHeight = head->heightLeft;
    if (head->heightRight > maxHeight)
        maxHeight = head->heightRight;
    return maxHeight;
}
void computeHeight(Node* head)
{
    if (!head->left)
        head->heightLeft = 0;
    else
    {
        computeHeight(head->left);
        head->heightLeft = getMaxHeight(head->left)+1;
    }
    if (!head->right)
        head->heightRight = 0;
    else
    {
        computeHeight(head->right);
        head->heightRight = getMaxHeight(head->right) + 1;
    }
}
Node* findRightLowest(Node* head)
{
    while (head->right)
    {
        head = head->right;
    }
    return head;
}
Node* findLeftLowest(Node* head)
{
    while (head->left)
    {
        head = head->left;
    }
    return head;
}
Node* balanceSubTree(Node* head)
{
    if (head->heightLeft - head->heightRight > 1)
    {
        findRightLowest(head->left)->right = head;
        Node* top = head->left;
        head->left = 0;
        return top;
    }
    if (head->heightRight - head->heightLeft > 1)
    {
        findLeftLowest(head->right)->left = head;
        Node* top = head->right;
        head->right = 0;
        return top;
    }
   return head;
}
Node* balanceAllTree(Node* head)
{
    while (abs(head->heightLeft - head->heightRight) > 1)
    {
        head = balanceSubTree(head);
        computeHeight(head);
    }
    if (head->left)
        head->left = balanceAllTree(head->left);
    if (head->right)
        head->right = balanceAllTree(head->right);
    return head;
}
void printTree(Node* head)
{
    printf("\n %s : %d", head->word, head->number);
    if (head->left)
        printTree(head->left);
    if (head->right)
        printTree(head->right);
}
void searchTree(Node* head, char* word)
{
    if (!strcmp(word, head->word))
    {
        head->number++;
        return;
    }
    if (compare(word, head->word))
    {
        if(head->right)
        searchTree(head->right, word);
    }
    else
    {
        if(head->left)
        searchTree(head->left, word);
    }
}