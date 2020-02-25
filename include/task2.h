#include<stdbool.h>

#define SIZE 10

typedef struct item {
	char word[SIZE];   //"word"
	int count;    // for sum program words
} Item;

typedef struct trnode {
	Item item;
	int height;  //for ABL-tree
	struct trnode* left;
	struct trnode* right;
} Trnode;

typedef struct tree {
	Trnode* root;
	int size;
} Tree;

void InitializeTree(Tree* ptree); //initializing the tree with empty content
void chomp(char* word);
bool MakeTree(const Item* pi, Tree* ptree);
void WordProgram(FILE*fp, Tree* ptree); //selection of words from program code
void printTree(const Trnode* root); 
void printOlltree(Trnode* root, int level); //for to look at tree_words
void DeleteAll(Tree* ptree); //for to clear memory
