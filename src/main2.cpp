#include "task2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
    if (argc != 3)
    {
        printf("Enter 3 arguments!\n");
        return 1;
    }
    
    FILE * fkeywords; // file with keywords
    FILE * fsearch; // file for searching keywords
    char buf[32];

    PNODE root = NULL;

    if ((fkeywords = fopen(argv[1], "rt")) == NULL)
    {
        printf("File open error!\n");
        return 1;
    }

    while (fgets(buf, 32, fkeywords))
    {
        chomp(buf);
        root = makeTree(root, buf);
    }
    
    if ((fsearch = fopen(argv[2], "rt")) == NULL)
    {
        printf("File open error!\n");
        return 1;
    }

    char ch; // current symbol
    char currWord[32]; // current word
    int i = 0, inWord = 0;

    while ((ch = fgetc(fsearch)) != EOF)
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

    fclose(fkeywords);
    fclose(fsearch);

    return 0;
}