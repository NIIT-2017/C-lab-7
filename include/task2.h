#include <stdio.h>
#define LEN 256

enum color_node { BLACK, RED };

struct KEYWORD {
	char word[LEN]; //key
	int count = 0;
	enum color_node color;
	struct KEYWORD* p; //указатель на родителя
	struct KEYWORD* left;
	struct KEYWORD* right;
};

typedef struct KEYWORD TKEYWORD;
typedef TKEYWORD* PKEYWORD;

void printTree(PKEYWORD node);
PKEYWORD getRoot(PKEYWORD x);
void leftRotate(PKEYWORD x);
void rightRotate(PKEYWORD x);
PKEYWORD rbInsert(PKEYWORD t, PKEYWORD x);
void rbInsertFixup(PKEYWORD t, PKEYWORD x);
char* chomp(char* str);
void searchTree(struct KEYWORD* node, char* word);