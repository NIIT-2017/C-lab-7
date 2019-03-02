
//создаем структуру для данных из файла names.csv
struct countries {
    char country [3]; // буквенное обозначение
    char region_code [3]; // код региона
    char name[30]; // название страны
};

typedef struct countries TCOUNTRIES; // создаем псевдоним TCOUNTRIES для типа данных struct countries
typedef TCOUNTRIES * PCOUNTRIES; // создаем указатель на структуру struct countries или на TCOUNTRIES
//создаем структуру для элемента списка

struct ITEM {
    PCOUNTRIES countries; // указатель на структуру countries
    struct ITEM * next; // указатель на следующий элемент списка
    struct ITEM * prev; // указатель на предыдущий элемент списка
};

typedef ITEM TITEM; // псевдоним для структуры ITEM
typedef TITEM * PITEM; // псевдоним для указателя на псевдоним структуры ITEM - TITEM

//прототип функции, создающей один элемент списка
PITEM creatList (PCOUNTRIES countries);

//прототип функции, которая записывает данные в виде структуры countries: возвращает указатель на структуру countries, принимает указатель на массив line
PCOUNTRIES creatCountries(char *line);

//прототип функции, которая записывает в хвостовой элемент списка данные в соответствии со структурой coutries
PITEM addToTail(PITEM tail, PCOUNTRIES countries);
//
int countList(PITEM head);
PITEM findByCountry(PITEM head, char*county);
PITEM findByCode(PITEM head, char*name);
void printCountry(PITEM item);

