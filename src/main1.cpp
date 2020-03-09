//Clab 7 task1

#include "task1.h"

int main()
{
	int i = 0, j = 0;
	char strFile[SIZE];
	char strCode[SIZE];
	char strName[SIZE];
	
	FILE* fp;

	fp = fopen("Regions.txt", "r");
	if (NULL == fp)
	{
		puts("FILE ERROR!");
		return 1;
	}

	char code[SIZE] = { '\0' };
	char number[SIZE] = { '\0' };
	char name[SIZE] = { '\0' };
	
	region any;

	fgets(strFile, SIZE, fp);
	
	while (strFile[i] != '\t')
	{
		code[i] = strFile[i];
		i++;
	}

	i++;

	while (strFile[i] != '\t')
	{
		number [j] = strFile[i];
		i++;
		j++;
	}

	i++;
	j = 0;

	while (strFile[i] != '\0' && strFile[i] != '\n')
	{
		name[j] = strFile[i];
		i++;
		j++;
	}
			
	strcpy(any.code, code);
	strcpy(any.number, number);
	strcpy(any.name, name);
	
	note* pointer = create(&any);

	while (fgets(strFile, SIZE, fp))
	{
		int i = 0, j = 0;

		char code[SIZE] = { '\0' };
		char number[SIZE] = { '\0' };
		char name[SIZE] = { '\0' };

		while (strFile[i] != '\t')
		{
			code[i] = strFile[i];
			i++;
		}

		i++;

		while (strFile[i] != '\t')
		{
			number[j] = strFile[i];
			i++;
			j++;
		}

		i++;
		j = 0;

		while (strFile[i] != '\0' && strFile[i] != '\n')
		{
			name[j] = strFile[i];
			i++;
			j++;
		}

		strcpy(any.code, code);
		strcpy(any.number, number);
		strcpy(any.name, name);

		add(pointer, &any);
	}
	
	fclose(fp);

	puts("Enter code to find country.");
	fgets(strCode, SIZE, stdin);

	if (strCode[strlen(strCode) - 1] == '\n')
		strCode[strlen(strCode) - 1] = '\0';
	
	CodeSearch(strCode, pointer);
	
	puts("Enter name to find country.");
	fgets(strName, SIZE, stdin);
			
	if (strName[strlen(strName)-1] == '\n')
		strName[strlen(strName) - 1] = '\0';

	NameSearch(strName, pointer);

	return 0;
}