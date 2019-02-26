#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define M 256
struct SYM 
{
	unsigned char ch; 
	float freq; 
};

typedef struct SYM TSYM;
typedef TSYM* PSYM;

//PSYM createTree(PSYM root, unsigned char ch, int count);
//void printTree(PSYM root);
//void copyMass(PSYM root, PSYM buf, int m)
void createBuf(PSYM root, unsigned char ch, int count, int *word);
void printBuf(PSYM buf, int word);
void bufSort(PSYM str, int size);