#ifndef TASK2_H
#define TASK2_H

typedef struct KEYWORD		//determine structure for storing of kewords and their frequencies
{
	char word[150];
	int freq;
	struct KEYWORD* left;
	struct KEYWORD* right;
}KEYWORD;

typedef KEYWORD* PKEYWORD;

PKEYWORD makeTree(PKEYWORD root, char * word);		//building tree on the basis of C-keywords file
void printTree(PKEYWORD root);						//printing of keywords and their quantity - symmetric
void chomp(char * string);							//deleting \n (for the document with keywords)
PKEYWORD searchTree(PKEYWORD root, char * word);	//finding the keyword in the text and counting the frequency

#endif