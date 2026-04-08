#include <stdio.h>
#include "../include/parser.tab.h"

// These are defined in the generated lexer and parser files
extern int yyparse();
extern FILE* yyin;

int main(int argc, char** argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Could not open %s\n", argv[1]);
            return 1;
        }
        yyin = file;
    }

    printf("Starting Mini-C Compilation...\n");
    
    // yyparse() starts the syntax analysis, which calls the lexer automatically
    int result = yyparse();

    if (result == 0) {
        printf("Compilation Successful!\n");
    } else {
        printf("Compilation Failed.\n");
    }

    return 0;
}