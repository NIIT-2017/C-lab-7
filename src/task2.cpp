#include "task2.h"

char* chomp(char* str) {
	if (str != NULL && str[strlen(str) - 1] == '\n')
		str[strlen(str) - 1] = '\0';
	return str;
}

PNODE makeTree(PNODE root, char* word) {
	if (root == NULL) {
		root = (PNODE)malloc(sizeof(SNODE));

		strcpy(root->word, word);
		root->count = 0;
		root->left = root->right = NULL;
	}
	else if (strcmp(root->word, word) > 0)
		root->left = makeTree(root->left, word);
	else if (strcmp(root->word, word) < 0)
		root->right = makeTree(root->right, word);

	return root;
}

 void searchTree(PNODE root, char* word) {
	if (!root) 
		return;
	if (strcmp(word, root->word) == 0) {
		root->count++;
		return;
	}
	if (strcmp(root->word, word) > 0)
		searchTree(root->left, word);
	else if((strcmp(root->word, word) < 0))
	 	searchTree(root->right, word);
}

void printTree(PNODE root) {
	if (!root) return;

	if (root->left)
		printTree(root->left);
	if (root->count > 0)
		printf("%s-%lu\n", root->word, root->count); // вывод инф. о корне
	if (root->right)
		printTree(root->right);
}
