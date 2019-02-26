#include "task3.h"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("wrong name of the file\n");
		return 1;
	}
	else
	{
		long count=0;
		int arr[256] = { 0 };
		struct SYM * pSYM;
		count = getArr(argv[1], arr);
		int size = arr2SYM(arr, count, &pSYM);
		for (int i = 0; i < size; i++)
			printf(" \'%c\' =%f\n", pSYM[i].ch, pSYM[i].freq);
		free(pSYM);
		return 0;
	}
}
