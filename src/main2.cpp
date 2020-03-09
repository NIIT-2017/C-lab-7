#include "task2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
    if (argc != 3)
    {
        printf("Error, please write 3 arguments\n");
        return 1;
    }
    FILE * keywords; 
    FILE * search; 
    char buf[32];
    PNODE root = NULL;
    if ((keywords = fopen(argv[1], "rt")) == NULL)
    {
        printf("Error, file not open\n");
        return 1;
    }
    while (fgets(buf, 32, keywords))
    {
        chomp(buf);
        root = makeTree(root, buf);
    }
    if ((search = fopen(argv[2], "rt")) == NULL)
    {
        printf("File open error!\n");
        return 1;
    }
    char ch; 
    char currWord[32]; 
    int i = 0, inWord = 0;
    while ((ch = fgetc(search)) != EOF)
    {
        if (((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) && inWord == 0)
        {
            currWord[i] = ch;
            inWord = 1;
            i++;
        }
        else if (((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) && inWord == 1)
        {
            currWord[i] = ch;
            i++;
        }
        else if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) && inWord == 1)
        {
            currWord[i] = '\0';
            inWord = 0;
            i = 0;
            searchTree(root, currWord);
        }
    }
    printTree(root);
    fclose(keywords);
    fclose(search);
    return 0;
}