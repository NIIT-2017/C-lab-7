#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"task2.h"

int main()
{
	Tree tree_word;
	Item item;
	FILE* f_wordsC;   //file with main words of C
	FILE* f_program;  //file with text of program
	InitializeTree(&tree_word);
	if ((f_wordsC = fopen("wordsC.txt", "r")) == NULL)    //open file for tree
	{
		puts("File open ERROR!");
		exit(1);
	}

	while (fgets(item.word, SIZE, f_wordsC))   
	{
		chomp(item.word);
		item.count = 0; //counter is empty
		MakeTree(&item, &tree_word);
	}
	//puts("TREE:");
	//printOlltree((tree_word.root), 0);  //if the user wants to look at the tree_word

	if ((f_program = fopen("programC.txt", "r")) == NULL)    //open program's file
	{
		puts("File open ERROR!");
		exit(1);
	}

	WordProgram(f_program, &tree_word);
	printTree(tree_word.root);

	if (fclose(f_wordsC) != 0)
		puts("Error closing the file \"wordsC.txt\"!");
	if (fclose(f_program) != 0)
		puts("Error closing the file \"programC.txt\"!");

	DeleteAll(&tree_word);

	return 0;
}