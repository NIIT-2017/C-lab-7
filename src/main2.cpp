#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "task2.h"

int main()
{
	FILE* fpK = fopen("listOFkeywords.txt", "r");
	if (!fpK) 
	{
		printf("Keywords file not found\n");
		exit(1);
	}
	printf("Welcome to the keyword analysis program!\n\n");
	keyWordST* keyList = makeTree(fpK);
	fclose(fpK);
	
	FILE* fpA = fopen("forAnalisys.txt", "r");
	if (!fpA)
	{
		printf("File for analisys not found\n");
		exit(1);
	}
	sourceCodeAnaliz(fpA, keyList);
	fclose(fpA);
	printTree(keyList);
	deleteTree(keyList);
	return 0;
}