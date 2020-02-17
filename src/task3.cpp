#include "task3.h"

p_SYM create_sym(char ch, float part)
{
    p_SYM sym = (p_SYM)malloc(sizeof(t_SYM));
    sym->symbol = ch;
    sym->frequency = part;
    return sym;
}

p_SYM* sort_syms(p_SYM* buf)
{
    float max_freq = 0;
    p_SYM change = (p_SYM)malloc(sizeof(t_SYM));
    for (int i=0;i<SIZE_OF_BUF;i++)
    {
        for (int j = i; j < SIZE_OF_BUF; j++)
            if (buf[j]!=NULL && buf[j]->frequency > max_freq)
                max_freq = buf[j]->frequency;

        for (int j = i; j < SIZE_OF_BUF; j++)
        {
            if (buf[j] != NULL && buf[j]->frequency == max_freq)
            {
                change=buf[i];
                buf[i] = buf[j];
                buf[j] = change;
            }
        }
        max_freq = 0;
    }
    return buf;
}

void print(p_SYM* buf)
{
    for (int i = 0; i < SIZE_OF_BUF; i++)
        if (buf[i] != NULL)
        {
            if (buf[i]->symbol==' ')
                printf("%f - 'space'\n", buf[i]->frequency);
            else if (buf[i]->symbol == '\n')
                printf("%f - '\\n'\n", buf[i]->frequency);
            else
                printf("%f - %c\n", buf[i]->frequency, buf[i]->symbol);
        }  
}