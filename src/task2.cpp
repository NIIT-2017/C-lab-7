#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "task2.h"

static Trnode* MakeNode(const Item* item);  //make new_node
static void AddNode(Trnode* new_node, Trnode** root); // installation of a new_node in the tree_word
static bool ToLeft(const char* i1, const char* i2); //if new_node < root
static bool ToRight(const char* i1, const char* i2); //if new_node > root
static int Tree_height(const Trnode*node); //for calculation imbalance the tree
static int MaxHeight(int left, int right); //for calculation  height of tree
static Trnode* RightRotate(Trnode* root); //balance the tree
static Trnode* LeftRotate(Trnode* root); //balance the tree
static void searchTree(const char* word_program, Trnode* root);  //search program word in tree and sum count++
static void DeleteAllNodes(Trnode* root); //for to clear memory

void InitializeTree(Tree* ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
}
void chomp(char* word)
{
	if ((word[strlen(word) - 1] == '\n') || (word[strlen(word) - 1] == EOF))
		word[strlen(word) - 1] = '\0';
}
bool MakeTree(const Item* item, Tree*tree_word)
{
	Trnode* new_node;
	new_node = MakeNode(item); //make the new_node
	tree_word->size++;//coutn nodes in tree_word
	if (tree_word->root == NULL) //the first node is the root
		tree_word->root = new_node;
	else
		AddNode(new_node, &tree_word->root); // installation of a new_node in the tree_word
	
	return true;
}
static void AddNode(Trnode* new_node, Trnode** root)
{

	if (ToLeft(new_node->item.word, ((*root)->item.word))) //if new_value < root
	{
		if ((*root)->left == NULL)
			(*root)->left = new_node;  //node attachment
		else
			AddNode(new_node, &((*root)->left));  //finding a place to join
	}
	else if (ToRight(new_node->item.word, ((*root)->item.word)))  //if new_value > root
	{
		if ((*root)->right == NULL)
			(*root)->right = new_node;  //node attachment
		else
			AddNode(new_node, &((*root)->right));  //if new_value > root
	}
	(*root)->height = MaxHeight(Tree_height((*root)->left), Tree_height((*root)->right)) + 1; //subtree height

	if (Tree_height((*root)->left) - Tree_height((*root)->right) == 2) //imbalance the tree on the left
	{
		*root = RightRotate(*root);  //turn the tree to the right
	}
	else if (Tree_height((*root)->left) - Tree_height((*root)->right) == -2)  //imbalance the tree on the right
	{
		*root = LeftRotate(*root);  //turn the tree to the left
	}

}
static Trnode* RightRotate(Trnode* root)
{
	Trnode* left;

	left = root->left; //resetting pointers
	root->left = left->right;
	left->right = root;

	root->height = MaxHeight(Tree_height(root->left), Tree_height(root->right)) + 1; //recalculation of heights
	left->height = MaxHeight(Tree_height(left->left), root->height) + 1; 

	return left;
}
static int MaxHeight(int left, int right)
{
	return (left >= right) ? left : right;
}
static Trnode* LeftRotate(Trnode* root)
{
	Trnode* right;
	right = root->right;   //resetting pointers
	root->right = right->left;
	right->left = root;
	
	root->height = MaxHeight(Tree_height(root->left), Tree_height(root->right)) + 1; //recalculation of heights
	right->height = MaxHeight(Tree_height(right->right), root->height) + 1; 

	return right;
}
static Trnode* MakeNode(const Item* item)
{
	Trnode* new_node;
	new_node = (Trnode*)malloc(sizeof(Trnode));

	if (new_node != NULL)
	{
		new_node->item = *item;
		new_node->height = 0;   //Tree_height(new_node);
		new_node->left = NULL;
		new_node->right = NULL;
	}

	return new_node;
}
static int Tree_height(const Trnode* new_node)
{
	return (new_node != NULL) ? new_node->height : -1;
}
static bool ToLeft(const char* i1, const char* i2)
{
	int comp1;
	if ((comp1 = strcmp(i1, i2)) < 0)
		return true;
	else
		return false;
}
static bool ToRight(const char* i1, const char* i2)
{
	int comp1;
	if ((comp1 = strcmp(i1, i2)) > 0)
		return true;
	else
		return false;
}
void printOlltree(Trnode* root, int level)
{
	if (root == NULL)
		return;

	for (int i = 0; i < level; i++)
		printf("   ");
	printf("%s\n", root->item.word);

	printOlltree(root->left, level + 1);
	printOlltree(root->right, level + 1);
}
void DeleteAll(Tree* ptree)
{
	if (ptree != NULL)
		DeleteAllNodes(ptree->root);
	ptree->root = NULL;
	ptree->size = 0;
}
static void DeleteAllNodes(Trnode* root)
{
	Trnode* pright;
	if (root != NULL)
	{
		pright = root->right;
		DeleteAllNodes(root->left);
		free(root);
		DeleteAllNodes(pright);
	}
}
void WordProgram(FILE*fp, Tree* ptree)
{
	char ch;
	char word_program[SIZE];
	int i = 0, j=0;

	while ((ch = getc(fp)) != EOF)
	{
		if (((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) && i<SIZE)
		{
			word_program[i] = ch;
			i++;
		}
		else if (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) && i != 0)
		{
			word_program[i] = '\0'; //got the word from the program code
			i = 0;
			j++;
			searchTree(word_program, ptree->root); //looking for this word in the tree_word
		}
	}
}
static void searchTree(const char* word_program, Trnode* root)
{
	while (root != NULL) //traversing the tree_word and searching for word in it
	{
		if (ToLeft(word_program, root->item.word))
			root = root->left;
		
		else if (ToRight(word_program, root->item.word))
			root = root->right;
		
		else if (strcmp(word_program, root->item.word) == 0)
		{
			root->item.count++;
			break;
		}
	}
}

void printTree(const Trnode* root)
{
	if (root != NULL)
	{
		if (root->item.count != 0)
			printf("%s - %d\n", root->item.word, root->item.count);
		printTree(root->left);
		printTree(root->right);
	}
}