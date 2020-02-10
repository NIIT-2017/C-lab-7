#include "task1.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main()
{
    RegionInfo* List = NULL;

    List = fillList(List);

    char str[100];

    while (1)
    {
        printf("Enter RegionName or CountryISO for searching. Enter \"END\" to cancel the programm.\n");
        fgets(str, 100, stdin);
        if(str != NULL && (strlen(str) - 1) >= 0)
            str[strlen(str) - 1] = 0;
        if (!strcmp(str, "END"))
            break;
        if (strlen(str) == 2 && isupper(str[0]) && isupper(str[1]))
            CountryISO_SP(List, str);
        else if (strlen(str) >= 2)
            RegionNameSP(List, str);
        else
            printf("You've entered invalid data!\n");
        printf("\n");
    }

    freeList(List);

    return 0;
}