#include "task3.h"
int comparetor(const void* a, const void* b)
{
    if (((SYM*)a)->frequency > ((SYM*)b)->frequency)
        return-1;
    return 1;
}