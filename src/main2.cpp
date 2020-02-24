#include "task2.h"

int main(int argc, char** argv) {
	setlocale(LC_ALL, "russian");

	char words[MAX_LEN] = { 0 };
	char buf[Q] = { NULL };
	PNODE head = NULL;
	char ch = '\0';

	FILE* fp;
	fp = fopen("keywords.txt", "rt");
	if (fp == NULL) {
		puts("Ошибка открытия файла!");
		return 1;
	}

	while (fscanf(fp, "%s", buf) == 1) {
		chomp(buf);
		head = makeTree(head, buf);
	}

	fclose(fp);

	fp = fopen("main.c", "rt");
	if (fp == NULL) {
		puts("Ошибка открытия исходного файла!");
		return 1;
	}

	while (fgets(words, MAX_LEN, fp) != NULL) {
		int i = 0;
		int inWord = 0;
		int n = 0;
		char tmp[BUF] = { NULL };

		while ((ch = words[i]) != EOF) {

			if (((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) && inWord == 0) {
				inWord = 1;
				tmp[n] = ch;
				n++;
			}
			else if (((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) && inWord == 1) {
				tmp[n] = ch;
				n++;
			}
			else if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) && inWord == 1) {
				inWord = 0;
				tmp[n] = '\0';
				n = 0;
				searchTree(head, tmp);
			}
			i++;
		}
		if (inWord == 1) {
			inWord = 0;
			tmp[n] = '\0';
			n = 0;
			searchTree(head, tmp);
		}
	}
	
	printTree(head);
	fclose(fp);

	return 0;
}


//	char words[MAX_LEN];
//	PKEYWORD node = NULL;
//	while (fgets(words, 256, fp) != NULL)
//	{
//		chomp(words);
//
//		int i = 0;
//		int inWord = 0;
//		int count = 0;
//		char temp[256];
//		PKEYWORD tnode = NULL;
//		while (words[i])
//		{
//			if (words[i] != ' ' && inWord == 0)
//			{
//				temp[count] = words[i];
//				count++;
//				inWord = 1;
//			}
//			else if (words[i] != ' ' && inWord == 1)
//			{
//				temp[count] = words[i];
//				count++;
//			}
//			else if (words[i] == ' ' && inWord == 1)
//			{
//				inWord = 0;
//				temp[count] = '\0';
//				tnode = (PKEYWORD)malloc(sizeof(TKEYWORD));
//				strcpy(tnode->word, temp);
//				tnode->count = 0;
//				node = rbInsert(node, tnode);
//				count = 0;
//			}
//			i++;
//		}
//	}
//	fclose(fp);
//	node = getRoot(node);
//	fp = fopen("task8.cpp", "r");
//	if (fp == NULL)
//	{
//		puts("File cpp open error!");
//		return 1;
//	}
//	while (fgets(words, 256, fp) != NULL)
//	{
//		chomp(words);
//
//		int i = 0;
//		int inWord = 0;
//		int count = 0;
//		char temp[256];
//		while (words[i])
//		{
//			if (words[i] < 'A' || words[i] > 'Z' && words[i] < 'a' || words[i] > 'z')
//				words[i] = ' ';
//			i++;
//		}
//		i = 0;
//		while (words[i])
//		{
//			if (words[i] != ' ' && inWord == 0)
//			{
//				temp[count] = words[i];
//				count++;
//				inWord = 1;
//			}
//			else if (words[i] != ' ' && inWord == 1)
//			{
//				temp[count] = words[i];
//				count++;
//			}
//			else if (words[i] == ' ' && inWord == 1)
//			{
//				inWord = 0;
//				temp[count] = '\0';
//				searchTree(node, temp);
//				count = 0;
//			}
//			i++;
//		}
//	}
//	printTree(node);
//
//	return 0;
//
//}