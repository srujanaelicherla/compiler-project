#include <stdio.h>
#include <string.h>
#include "../include/symbol_table.h"

#define SIZE 100

Symbol table[SIZE];
int count = 0;

void insert(char *name) {
    for(int i=0; i<count; i++) {
        if(strcmp(table[i].name, name) == 0) {
            printf("Error: Variable '%s' already declared\n", name);
            return;
        }
    }

    strcpy(table[count].name, name);
    table[count].value = 0;
    count++;
}

int lookup(char *name) {
    for(int i=0; i<count; i++) {
        if(strcmp(table[i].name, name) == 0)
            return i;
    }
    return -1;
}

void display() {
    printf("\nSymbol Table:\n");
    for(int i=0; i<count; i++) {
        printf("%s = %d\n", table[i].name, table[i].value);
    }
}