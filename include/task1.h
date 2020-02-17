#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_OF_INFO 512
#define SIZE_OF_BUF 512
#define SIZE_OF_COUNTRY 3
#define SIZE_OF_NUMBER 3
#define SIZE_OF_REGION 256
#define SYMBOL_1 ','
#define SYMBOL_2 '"'

struct DATA
{
    char data_country[SIZE_OF_COUNTRY];
    char data_number[SIZE_OF_NUMBER];
    char data_region[SIZE_OF_REGION];
};

typedef struct DATA t_DATA;
typedef t_DATA* p_DATA;

struct ITEM
{
    p_DATA point_of_data;
    struct ITEM* point_of_next_item;
    struct ITEM* point_of_prev_item;
};

typedef struct ITEM t_ITEM;
typedef t_ITEM* p_ITEM;

p_ITEM create_list(p_DATA p_data);
p_DATA create_data(char* line);
p_ITEM add_tail(p_ITEM tail, p_DATA data);
void print_data(p_ITEM item);
void find_by_country(p_ITEM item, char* line);
void find_by_region(p_ITEM item, char* line);
char* region_in_format(char* line);
void clean_stdin(void);