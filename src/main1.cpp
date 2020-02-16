#include "task1.h"


int main() {
	setlocale(LC_ALL, "russian");

	FILE* fp;
	int count = 0;
	char buf[BUF];
	PITEM head, tail, item;
	fp = fopen("fips10_4.csv", "rt");
	if (!fp) {
		perror("Файл fips10_4.csv: ");
		exit(1);
	}
	fgets(buf, BUF, fp);
	while (fgets(buf, BUF, fp)) {
		if (count == 0) {
			head = createList(createName(buf));
			tail = head;
		}
		else {
			tail = addToTail(tail, createName(buf));
		}
		count++;
	}
	fclose(fp);

	printf("Всего записей: %d\n\n", countList(head));

	item = findByCode(head, (char*)"83");
	if (item == NULL)
		printf("Код региона не найден!\n");
	else {
		printf("Код региона: ");
		printCode(item);
		printItem(item);
		printf("\n");
	}

	item = findByName(head, (char*)"Nizhniy Novgorod");
	if (item == NULL)
		printf("Название города не найдено!\n");
	else {
		printf("Название города: ");
		printName(item);
		printItem(item);
		printf("\n");
	}

	item = findByRegion(head, (char*)"RU");
	printf("\n");

	return 0;
}