//Clab 7 task3

#include "task3.h"

int main(int argc, char* argv[])
{
	char symbol;
	node* arr[255] = { NULL };

	FILE* fp;
	fp = fopen(argv[1], "r");
	if (NULL == fp)
	{
		puts("FILE ERROR!");
		return 1;
	}
	
	node* pointer = NULL;

	while ((symbol = fgetc(fp)) != EOF)
	{
		pointer = add(pointer, symbol);
	}

	fclose(fp);
	
	createArr(pointer, arr);
	
	sort(arr);

	printTree(arr);

	return 0;
}