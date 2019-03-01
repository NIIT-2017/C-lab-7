#define M 20
struct WordsTable
{
	char word[M];
	int count;
	struct  WordsTable*left;
	struct WordsTable*right;
};

typedef struct WordsTable TWT;
typedef TWT * PWT;

PWT makeTree(PWT root, char *word);
void searchTree(PWT root, char *word);
void printTree(PWT root);
