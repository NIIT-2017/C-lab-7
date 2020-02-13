#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "task3.h"

int main()
{
	struct SYM data[LEN];
	char words[MAX_LEN];
	FILE* f;
	f = fopen("test.txt", "r");
	int count = 0; 
	int i,j;
	int ns = 0; 
	while (fgets(words, 256, f) != NULL)
	{
		chomp(words);
		i = 0;
		while (words[i])
		{
			count++;
			i++;
		}
	}
	printf("Number of characters in the file = %d\n", count);
	rewind(f); 
	struct SYM * node;
	int found;

	while (fgets(words, 256, f) != NULL)
	{
		chomp(words);
		i = 0;
		while (words[i])
		{
			found = 0;
			for (j = 0; j < ns; j++)
			{
				if (words[i] == data[j].ch)
				{
					data[j].freq++;
					found = 1;
					break;
				}
			}
			if (found == 0)
			{
				data[ns].ch = words[i];
				data[ns].freq = 1;
				ns++;
			}
			i++;
		}
	}
	for (i = 0; i < ns; i++)
		data[i].freq = data[i].freq/count;
	qsort(data, ns, sizeof(data[0]), cmp);
	for (i = 0; i < ns; i++)
		printf("%c %f\n", data[i].ch, data[i].freq);

	return 0;
}