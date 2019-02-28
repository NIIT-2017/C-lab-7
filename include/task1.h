struct regions
{
	char country[3];
	char code[3];
	char reg[50];
	struct regions *next;
};

void str(struct regions *current, char buf[]);
void region(struct regions * head, struct regions * current, char *qwerty);
void country(struct regions * head, struct regions * current, char *qwerty);