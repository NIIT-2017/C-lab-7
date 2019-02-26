#include "task2.h"

int main()
{
	struct wordsTree * root;
	root = NULL;
	root = makeTree(addWord,"keyWords.txt", root);
	printf("key words are:\n");
	printTree(root);
	printf("press enter to scan the file");
	getchar();
	/*root =*/ makeTree(statWord, "task2.cpp", root);//name of the file we want to analyze
	printTree(root);
	printf("freeMem returned %d",freeMemTree(root));
return 0;
}