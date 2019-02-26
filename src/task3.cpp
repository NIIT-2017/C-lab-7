#include "task3.h"

static int index = 0;

void createBuf(PSYM buf, unsigned char ch, int count, int *word)
{
	int rep = 0;
	if (index == 0)
	{
		buf[index].ch = ch;
		buf[index].freq = buf[index].freq + ((float)1) / ((float)count);
		(*word)++;
		index++;
		return;
	}
	for (int i = 0; i < index; i++)
	{
		if (buf[i].ch == ch)
			rep++;
	}
	for (int i = 0; i < index; i++)
	{
		if (buf[i].ch != ch && rep != 1)
		{
			buf[index].ch = ch;
			buf[index].freq = buf[index].freq + ((float)1) / ((float)count);
			index++;
			(*word)++;
			break;
		}
		else if (buf[i].ch == ch && rep == 1)
			buf[i].freq = buf[i].freq + ((float)1) / ((float)count);
	}
}

void printBuf(PSYM buf, int word)
{
	for (int i = 0; i < word; i++)
		printf("%c %f\n", buf[i].ch, buf[i].freq);
}

static int compar(const void* p1, const void* p2)
{
	if (((PSYM)p2)->freq > ((PSYM)p1)->freq)
		return 1;
	if (((PSYM)p2)->freq < ((PSYM)p1)->freq)
		return -1;
	if (((PSYM)p2)->freq == ((PSYM)p1)->freq)
		return 0;
}

void bufSort(PSYM str, int size)
{
	qsort(str, size, sizeof(TSYM), compar);
}

/*PSYM createTree(PSYM root, unsigned char ch, int count)
{
	if (root == NULL)
	{
		root = (PSYM)malloc(sizeof(TSYM));
		root->ch = ch;
		root->freq =((float)1)/((float)count);
		root->left = root->right = NULL;
	}
	else if (root->ch > ch)
		root->left = createTree(root->left, ch, count);
	else if (root->ch < ch)
		root->right = createTree(root->right, ch, count);
	else
		root->freq = root->freq + ((float)1) / ((float)count);
	return root;
}*/

/*void printTree(PSYM root)
{
	if (root->left)
		printTree(root->left);
	printf("%c %f\n", root->ch, root->freq);
	if (root->right)
		printTree(root->right);
}*/
