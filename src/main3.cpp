#include "task3.h"
#include <stdlib.h>
int main(int argc, char* argv[])
{
	printf("Do it: Run cmd -> C:\labsss\L7T3\Debug\L7T3.exe  ''file name''\n");
	printf("I use C:\labsss\KeyWords.txt\n");
	FILE* fp = fopen(argv[1], "rt");
	SYM top[256];
	if (!fp)
	{
		printf("file lost\n");
		return 1;
	}
	loadingChart(top);
	letterCount(top, fp);
	fclose(fp);
	qsort(top, 256, sizeof(SYM), sopostavl);
	printChart(top);
	return 0;
}