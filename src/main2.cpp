#include "task2.h"

int main()
{
    char buf[WORD_SIZE] = { NULL };
    char word[WORD_SIZE] = { NULL };
    p_TREE root=NULL;
    FILE* kw;
    FILE* fp;
    char ch;
    int flag = OUTWORD;
    int ch_count = 0;

    kw = fopen("keywords.txt", "rt");
    if (!kw)
    {
        perror("keywords.txt:");
        exit(1);
    }
    while (fscanf(kw, "%s", buf) == 1)
        root = makeTREE(root, buf);
    fclose(kw);

    fp = fopen("file.txt", "rt");
    if (!fp)
    {
        perror("file.txt:");
        exit(2);
    }
    while ((ch = fgetc(fp)) != EOF)
    {
        if (flag == OUTWORD && check_ch(ch) == LETTER)
        {
            flag = INTOWORD;
            word[ch_count] = ch;
            ch_count++;
        }
        else if (flag == INTOWORD && check_ch(ch) == LETTER)
        {
            word[ch_count] = ch;
            ch_count++;
        }
        else if (flag == INTOWORD && check_ch(ch) == NOTLETTER)
        {
            flag = OUTWORD;
            ch_count = 0;
            searchTREE(root, word);
            clean_buf(word, WORD_SIZE);
        }
    }
    fclose(fp);

    printTree(root);

    return 0;
}