#include <stdlib.h>
#include "task3.h"

struct SYM *buildTree(struct SYM *psym[],int N)                     //рeкурсивная функция создания дерева Хаффмана
{
    struct SYM *temp=(struct SYM*)malloc(sizeof(struct SYM));
    temp->freq=psym[N-2]->freq+psym[N-1]->freq;
    temp->left=psym[N-1];
    temp->right=psym[N-2];
    temp->code[0]=0;
    if(N==2)
        return temp;
    else                                                             //внесение в массив в нужное место элемента дерева Хаффмана
    {
        for(int i=0;i<N;i++)
            if (temp->freq>psym[i]->freq)
            {
                for(int j=N-1;j>i;j--)
                    psym[j]=psym[j-1];
                    psym[i]=temp;
                break;
            }
    }
    return buildTree(psym,N-1);
}
