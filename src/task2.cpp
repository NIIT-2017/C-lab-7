#include "task2.h"

char* chomp(char* buf)
{
    if (buf != NULL && strlen(buf) >= 1 && buf[strlen(buf) - 1] == '\n')
        buf[strlen(buf) - 1] = NULL;

    return buf;
}

p_TREE makeTREE(p_TREE root, char* word)
{
    if (root == NULL)
    {
        root = (p_TREE)malloc(sizeof(t_TREE));
        strcpy(root->word, chomp(word));
        root->count = 0;
        root->left = root->right = NULL;
    }
    else if (strcmp(root->word, chomp(word)) > 0)
        root->left = makeTREE(root->left, chomp(word));
    else if (strcmp(root->word, chomp(word)) < 0)
        root->right = makeTREE(root->right, chomp(word));

    return root;
}

int check_ch(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return LETTER;
    else
        return NOTLETTER;
}

void clean_buf(char* buf, int size)
{
    for (int i = 0; i < size; i++)
        buf[i] = NULL;
}

void searchTREE(p_TREE root, char* word)
{
    if (strcmp(root->word, word) == 0)
        (root->count)++;
    else if (strcmp(root->word, word) > 0 && root->left != NULL)
        searchTREE(root->left, word);
    else if (strcmp(root->word, word) < 0 && root->right != NULL)
        searchTREE(root->right, word);
}

void printTree(p_TREE root)
{
    if (root->left)
        printTree(root->left);
    if (root->count > 0)
        printf("%s-%d\n", root->word, root->count);
    if (root->right)
        printTree(root->right);
}

