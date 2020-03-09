#include "task2.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	FILE* fp;
	FILE* out;
	char buf[512] = {0};
	char word[512] = {0};
	char word2[256] = { 0 };
	struct NODE* root = NULL;
	fp = fopen("Key_words.txt", "rt");
	out = fopen(argv[1], "rt");
	if (!fp || !out)
	{
		perror("File names.txt:");
		exit(1);
	}

	while (fgets(buf, 512, fp))
		root = makeTree(root, buf);
	fclose(fp);
	chomp(root);
	
	while (fgets(word, 512, out)!=NULL)
	{
		int inWord = 0, i = 0, j = 0;
		while (word[i])
		{
			if (((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z')) && inWord == 0)
			{
				word2[j] = word[i];
				j++;
				inWord = 1;
			}
			else if (((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z')) && inWord == 1)
			{
				word2[j] = word[i];
				j++;
			}
			else if ((word[i] == ' '|| word[i] == '\n') && inWord == 1)
			{
				inWord = 0;
				word2[j] = '\0';
				searchTree(root, word2);
				j = 0;
			}
			i++;
		}
	}
	fclose(out);
	printTree(root);
	return 0;
}