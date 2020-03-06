#define MAXNAME 128
#define MAXPREFICS 3

typedef struct region // обьявляем новый тип структуру
{
	char countryCode[MAXPREFICS];
	char regionCode[MAXNAME];
	char name[MAXNAME];
	struct region* next;
}regionST;

regionST* createList(FILE* fp); // создание списка
regionST* createStruct(char bufer[]); // создание и заполнение структуры
void parsing(char buf[256], char prefics[MAXPREFICS], char code[MAXPREFICS], char name[MAXNAME]); //разбивание строки из файла на параметры
void clean_stdin(void); // очистка потока ввода
void searchBYcountryCode(regionST* headOflist, char tempChar[]); //поиск
void searchBYname(regionST* headOflist, char tempChar[]);//поиск
void searchBYregionCode( regionST* headOflist,  char tempChar[]);//поиск
void printRegion(const regionST* pointOflist); // распечатка структуры
void deleteList(regionST* pointOflist); // освобождение выделенной памяти