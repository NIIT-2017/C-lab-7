#include "task1.h"

int main()
{
    FILE* fp;
    int count = 0;
    char info[SIZE_OF_INFO];
    char buf[SIZE_OF_BUF];
    char country[SIZE_OF_COUNTRY] = { 0 };
    char region[SIZE_OF_REGION] = { 0 };
    p_ITEM head, tail, item;

    fp = fopen("fips10_4.csv", "rt");
    if (!fp)
    {
        perror("File fips10_4.csv:");
        exit(1);
    }
    fgets(info, SIZE_OF_INFO, fp);
    while (fgets(buf, SIZE_OF_BUF, fp))
    {
        if (count == 0)
        {
            head = create_list(create_data(buf));
            tail = head;
        }
        else
            tail = add_tail(tail, create_data(buf));

        count++;
    }
    fclose(fp);
    printf("Number of data %d\n", count);

    printf("If you want to find all data by country, input code of country\n");
    fgets(country, SIZE_OF_COUNTRY, stdin);
    if (strcmpi(country, "\n") != 0)
    {
        find_by_country(head, country);
        puts("");
        clean_stdin();
    }

    printf("If you want to find data by region, input name of region\n");
    fgets(region, SIZE_OF_REGION, stdin);
    if (strcmpi(region, "\n") != 0)
    {
        find_by_region(head, region_in_format(region));
        clean_stdin();
    }

    return 0;
}