typedef struct {
    char name[50];
    char type[10];   // "int", "float"
} Symbol;

void insert(char *name, char *type);
int lookup(char *name);