%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
void yyerror(const char *s);
%}

/* Define the tokens (must match what you use in lexer.l) */
%token INT FLOAT IF ELSE WHILE PRINT
%token ID INT_LITERAL FLOAT_LITERAL
%token PLUS MINUS MULT DIV ASSIGN SEMICOLON

%%

/* The Grammar Rules */
program:
    /* empty */
    | program statement
    ;

statement:
    PRINT SEMICOLON { printf("Parsed a print statement!\n"); }
    ;

%%

/* C Code Section */
void yyerror(const char *s) {
    fprintf(stderr, "Parse Error: %s\n", s);
}