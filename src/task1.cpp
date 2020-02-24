#include "task1.h"


PITEM createList(PNAME_REC name_rec) {
	PITEM item = (PITEM)malloc(sizeof(TITEM));
	item->name_rec = name_rec;
	item->prev = NULL;
	item->next = NULL;

	return item;
}

PNAME_REC createName(char* line) {
	int i = 0;
	PNAME_REC rec = (PNAME_REC)malloc(sizeof(TNAME_REC));
	while (*line && *line != ',') {
		rec->reg[i++] = *line++;
	}
	rec->reg[i] = '\0';
	line++;

	i = 0;
	while (*line && *line != ',') {
		rec->code[i++] = *line++;
	}
	rec->code[i] = '\0';
	line++;

	i = 0;
	while (*line) {
		if (*line != '"' && *line != '\n')
			rec->name[i++] = *line++;
		else
			line++;
	}
	rec->name[i] = '\0';

	return rec;
}

PITEM addToTail(PITEM tail, PNAME_REC name_rec) {
	PITEM item = createList(name_rec);
	if (tail != NULL) {
		tail->next = item;
		item->prev = tail;
	}
	return item;
}

int countList(PITEM head) {
	int count = 0;
	while (head) {
		count++;
		head = head->next;
	}
	return count;
}

PITEM findByRegion(PITEM head, char* reg) {
	while (head) {
		if (strcmpi(head->name_rec->reg, reg) == 0) {
			//printItem(head);
			return head;
		}
		head = head->next;
	}
	return NULL;
}

PITEM findByCode(PITEM head, char* code) {
	while (head) {
		if (strcmpi(head->name_rec->code, code) == 0) {
			return head;
		}
		head = head->next;
	}

	return NULL;
}

PITEM findByName(PITEM head, char* name) {
	while (head) {
		if (strcmp(head->name_rec->name, name) == 0) {
			return head;
		}
		head = head->next;
	}

	return NULL;
}

void printRegion(PITEM item) {
	if (item != NULL) {
		printf("%s\n", item->name_rec->reg);
	}
}

void printCode(PITEM item) {
	if (item != NULL) {
		printf("%s\n", item->name_rec->code);
	}
}

void printName(PITEM item) {
	if (item != NULL) {
		printf("%s\n", item->name_rec->name);
	}
}

void printItem(PITEM item) {
	if (item != NULL) {
		printf("%s, %s, %s\n",
			item->name_rec->reg,
			item->name_rec->code,
			item->name_rec->name);
	}
}