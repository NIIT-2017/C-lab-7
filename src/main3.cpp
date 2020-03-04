#include "task3.h"
#include <stdio.h>

int main()
{
    TSYM data[SIZE];

    initData(data);
    sortData(data);
    printData(data);

    return 0;
}