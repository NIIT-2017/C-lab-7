#include "task3.h"
#include <stdlib.h>

//int main()
//{
//    FILE* fp = fopen("programm.txt", "rt");
int main(int argc, char* argv[])
{
    FILE* fp = fopen(argv[1], "rt");
    SYM chart[256];
    if (fp == NULL)
    {
        printf("openning file error\n");
        return 1;
    }

    fillChart(chart);
    findOut(chart, fp);
    fclose(fp);
    qsort(chart, 256, sizeof(SYM), compar);
    printChart(chart);

    return 0;
}