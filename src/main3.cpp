#include "task3.h"

int main()
{
    FILE* fp;
    p_SYM buf[SIZE_OF_BUF] = { NULL };
    char ch;
    float count = 0;
    float part = 0;

    fp = fopen("symbols.txt", "rt");
    if (!fp)
    {
        perror("symbols.txt:");
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF)
        count++;
    part = (1 / count);
    rewind(fp);
    while ((ch = fgetc(fp)) != EOF)
    {
        if (buf[ch] == NULL)
            buf[ch] = create_sym(ch, part);
        else
            buf[ch]->frequency += part;
    }
    fclose(fp);
    print(sort_syms(buf));
    return 0;
}