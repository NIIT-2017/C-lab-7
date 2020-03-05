//Clab 7 task2

#include "task2.h"

int main()
{
	char anyWord[SIZE];
	char nextWord[SIZE];
	
	char strCpp[SIZE] = {'\0'};
		
	FILE* fp;

	fp = fopen("Words.txt", "r");
	if (NULL == fp)
	{
		puts("FILE ERROR!");
		return 1;
	}

	fgets(anyWord, SIZE, fp);

	if ((anyWord[strlen(anyWord)-1]) == '\n')
		anyWord[strlen(anyWord) - 1] = '\0';

	node* pointer = NULL;

	while (fgets(nextWord, SIZE, fp)!=0)
	{
		if ((nextWord[strlen(nextWord) - 1]) == '\n')
			nextWord[strlen(nextWord) - 1] = '\0';
		
		pointer = add(pointer, nextWord);
	}

	fclose(fp);
	
	//

	FILE* fpcpp;
	fpcpp = fopen("Ex.cpp", "r");
	if (NULL == fpcpp)
	{
		puts("FILE ERROR!");
		return 1;
	}
	
	while (fgets(strCpp, SIZE_C, fpcpp))
	{
		int flag = 0; // в слове
		char newStr[SIZE_C][SIZE] = { '\0' };

		if ((strCpp[strlen(strCpp) - 1]) == '\n')
			strCpp[strlen(strCpp) - 1] = '\0';

		int i = 0;
		int j = 0;
		int k = 0;
		int nStr = 0;

		for (; k <= strlen(strCpp); k++)
		{
			if (strCpp[k] != ' ' && flag == 0)
			{
				newStr[i][j] = strCpp[k];
				j++;
			}

			else if (strCpp[k] == ' ' && flag == 0)
			{
				flag = 1;
				i++;
				j = 0;
			}
			
			else if (strCpp[k] != ' ' && flag == 1)
			{
				newStr[i][j] = strCpp[k];
				flag = 0;
				j++;
			}

			else if (strCpp[k] == '\0')
				break;
		}

		for (nStr; nStr <= i; nStr++)
		{
			search(pointer, newStr[nStr]);
		}
	}

	printTree(pointer);

	fclose(fpcpp);
	return 0;
}
