#include "task3.h"

long getArr( const char * fileName, int * arr)
{
	long count = 0;
	FILE *mf;
	mf = fopen(fileName, "rb");		
	if (mf == NULL) { printf("file open error\n"); return -1; }
	int i = 0;
	while ((i = fgetc(mf)) != EOF)
		arr[i]++, count++;
	fclose(mf);
	return count;
}

int compare(void * pArr1, const void * pArr2)
{
	if (((struct SYM *)pArr1)->freq < ((struct SYM *)pArr2)->freq)
		return -1;

	if (((struct SYM *)pArr1)->freq > ((struct SYM *)pArr2)->freq)
		return 1;

	if (((struct SYM *)pArr1)->freq = ((struct SYM *)pArr2)->freq)
		return 0;
}

int arr2SYM(int * arr, long count, struct SYM ** pSYM)
{
	int size = 0;
	for (int i = 0; i < 256; i++)		// это будет количество ненулевых символов
		arr[i] ? size++ : 0;

	*pSYM = (struct SYM *) malloc(size * sizeof(struct SYM));//массив сруктур только под существующие буквы

	for (int i = 0, j = 0; i < 256; i++)
	{
		if (arr[i])
		{
			(*pSYM)[j].ch = i;
			(*pSYM)[j].freq = (float)arr[i] / count;
			(*pSYM)[j].code[0] = "";
			(*pSYM)[j].left = NULL;
			(*pSYM)[j].right = NULL;
			j++;
		}
	}

	qsort(*pSYM, size, sizeof(struct SYM), compare);
	return size;
}