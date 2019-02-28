typedef struct REGCODE
{
    char iso[3];
    char code[3];
    char name[64];
    struct REGCODE *next;
}TREGCODE;
typedef TREGCODE * PREGCODE;

void createList(PREGCODE current, char *buf);
void findByName(PREGCODE head, PREGCODE current, char *name);
void findByIso(PREGCODE head, PREGCODE current, char *iso);
