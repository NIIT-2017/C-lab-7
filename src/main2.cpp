#include "task2.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#define SIZEOFWORD 50


int main(int argc, char * argv[])		// we are getting names of the both files from command line
{
	if (argc != 3)
	{
		printf("Wrong format of arguments in the command string\n");
		return -1;
	}
	
	FILE * fr = fopen(argv[1], "rt");//checking file for reading
	if (!fr)
	{
		perror("Cannot read file with keywords");
		exit(-2);
	}

	FILE * fch = fopen(argv[2], "rt");	//checking file for checking
	if (!fch)
	{
		perror("Cannot read file for checking");
		exit(-3);
	}

	PKEYWORD root = NULL;
	char keyWord[SIZEOFWORD] = { 0 };
	
	while (!feof(fr))					//getting keywords from the file with C-keywords and creating a tree
	{
		fgets(keyWord, SIZEOFWORD, fr);
		chomp(keyWord);					//deleting \n and \r
		root = makeTree(root, keyWord);	//creating a tree with keywords
	}


	char tmpWord[SIZEOFWORD] = { 0 };	//creating temp. array for words from the checking document
	int chTemp = 0;	//temporary char for reading from the checking file	
	int inWord = 0;
	int i = 0;
	while (!feof(fch))
	{
		chTemp = fgetc(fch);
		if (isalpha(chTemp))		//checking if we are in the word now
		{
			if (!inWord)// if it is first letter of the word (we was not in the word previously)
			{
				inWord = 1;
				tmpWord[0] = chTemp;
				i++;
			}
			else			//if it's letter, but not the first letter of the word
			{
				tmpWord[i] = chTemp;
				i++;
			}
		}
		else				//if it's not a letter
		{
			inWord = 0;
			i = 0;
			searchTree(root, tmpWord);

			for (int j = 0; j < SIZEOFWORD; j++)
			{
				tmpWord[j] = '\0';
			}
			
		}
	}

	printTree(root);
	
	fclose(fr);
	fclose(fch);
	return 0;
}