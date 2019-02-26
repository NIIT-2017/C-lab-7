#include"task2.h"

struct wordsTree * addWord( struct wordsTree * node, char * buf)
{
	if (!node) //(node == NULL)
	{
		node = (struct wordsTree *) malloc(sizeof(struct wordsTree));
		strcpy(node->word, buf);
		node->count = 0;
		node->left = NULL;
		node->right = NULL;
	}
	else
	{
		if (strcmp(buf, node->word) < 0) // go left
			node->left = addWord(node->left, buf);
		if (strcmp(buf, node->word) > 0) // go right
			node->right = addWord(node->right, buf);
	}
	return node;
}

struct wordsTree * statWord( struct wordsTree * node, char * buf)
{
	if ( !node)
		return node;

	if (!strcmp(buf, node->word))
		node->count = node->count + 1;
		
	else
	{
		if (strcmp(buf, node->word) < 0) // go left
			node->left = statWord(node->left, buf);
		if (strcmp(buf, node->word) > 0) // go right
			node->right = statWord(node->right, buf);
	}
	return node;
}

struct wordsTree * makeTree(
	struct wordsTree * (*pFun)(struct wordsTree * node, char* buf),
	const char * fileName, struct wordsTree * root)
{
	char buf[maxWord] = { 0 };
	FILE *mf;
	mf = fopen(fileName, "r");
	if (mf == NULL) { printf("file open error\n"); return -1; }
	
	char ch=0; int j = 0;
	do
	{
		ch = fgetc(mf);
		if ('a' <= ch && ch <= 'z')
		{
			buf[j] = ch; j++;
		}
		if (j!=0 &&('a' > ch || ch > 'z'))
		{
			buf[j] = '\0';
			j = 0;
			root = pFun(root, buf);//addWord or statWord
		}
	} while (ch!=EOF);

	fclose(mf);
	return root;
}

void printTree(struct wordsTree * node)
{
	if (node != NULL)
	{
		printTree(node->left);
		printf("%20s %d\n", node->word, node->count);
		printTree(node->right);
	}
}

int freeMemTree(struct wordsTree * node)
{
	if (node!=NULL)
	{
		freeMemTree(node->left);
		freeMemTree(node->right);
		free(node);
	}
	return 0;
}
  // another version, word from ' ' to ' ' dont watch comething like " char*"
/*
struct wordsTree * makeTree(
	struct wordsTree * (*pFun)(struct wordsTree * node, char * buf),
	const char * fileName, struct wordsTree * root)
{
	char buf[maxWord] = { 0 };
	FILE *mf;
	mf = fopen(fileName, "r");
	if (mf == NULL) { printf("file open error\n"); return -1; }
	while (fscanf(mf, "%s", buf) != EOF)
		root = pFun(root, buf);//addWord or statWord
	fclose(mf);
	return root;
}
*/