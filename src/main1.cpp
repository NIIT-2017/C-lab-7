#include "task1.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
int main()
{
	RegionInfo* List = NULL;
	List = loadingList(List);
	char str[100];
	while (1)
	{
		printf("Enter RegionName or ISO-two letter.\n");
		printf("For go out - write 'out'.\n");
		fgets(str, 100, stdin);
		if (str != NULL && (strlen(str) - 1) >= 0)
			str[strlen(str) - 1] = 0;
		if (!strcmp(str, "out")) // exit, if you write this text
			break;
		if ((strlen(str) == 2) && (isupper(str[0]) && isupper(str[1]))) //isupper - true if OJNSDV, false if fnsjfn
			searchISOResult(List, str);
		else if (strlen(str) >= 2)
			searchNameResult(List, str);
		else
			printf("You have enter invalid data!\n");
		printf("\n");
	}
	clearList(List);
	return 0;
}