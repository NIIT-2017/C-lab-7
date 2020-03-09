#include "task1.h"

p_ITEM create_list(p_DATA p_data)
{
    p_ITEM item = (p_ITEM)malloc(sizeof(t_ITEM));
    item->point_of_data = p_data;
    item->point_of_next_item = NULL;
    item->point_of_prev_item = NULL;
    return item;
}

p_DATA create_data(char* line)
{
    int i = 0;
    p_DATA data = (p_DATA)malloc(sizeof(t_DATA));
    while (*line != NULL && *line != SYMBOL_1)
        data->data_country[i++] = *line++;
    data->data_country[i] = '\0';
    
    i = 0;
    line++;
    while (*line != NULL && *line != SYMBOL_1)
        data->data_number[i++] = *line++;
    data->data_number[i] = '\0';

    i = 0;
    line++;
    while (*line != NULL)
        data->data_region[i++] = *line++;

    if (data->data_region[i - 1] == '\n')
        data->data_region[i - 1] = '\0';
    else
        data->data_region[i] = '\0';
    
    return data;
}

p_ITEM add_tail(p_ITEM tail, p_DATA data)
{
    p_ITEM item = create_list(data);
    if (tail != NULL)
    {
        tail->point_of_next_item = item;
        item->point_of_prev_item = tail;
    }
    return item;
}

void print_data(p_ITEM item)
{
    printf("%s %s %s\n", item->point_of_data->data_country,
                         item->point_of_data->data_number,
                         item->point_of_data->data_region);
}

void find_by_country(p_ITEM item, char* line)
{
    int count = 0;
    if (line[strlen(line) - 1] == '\n')
        line[strlen(line) - 1] = '\0';

    while (item != NULL)
    {
        if (strcmpi(item->point_of_data->data_country, line) == 0)
        {
            count++;
            print_data(item);
        }

        item = item->point_of_next_item;
    }
    if (item == NULL && count==0)
        printf("Not found\n");
}

void find_by_region(p_ITEM item, char* line)
{
    int count = 0;
    while (item != NULL)
    {
        if (strcmpi(item->point_of_data->data_region, line) == 0)
        {
            count++;
            print_data(item);
        }
        item = item->point_of_next_item;
    }
    if (item == NULL && count == 0)
        printf("Not found");
}

char* region_in_format(char* line)
{
    int size = strlen(line);
    line[size + 1] = '\0';
    line[size] = SYMBOL_2;
    for (int i = size - 2; i >= 0; i--)
        line[i + 1] = line[i];
    line[0] = SYMBOL_2;
    return line;
}

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}