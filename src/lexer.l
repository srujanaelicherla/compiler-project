%{
#include "../include/parser.tab.h"
#include <stdio.h>
%}

%%

"int"       { return INT; }
"float"     { return FLOAT; }
"print"     { return PRINT; }
[0-9]+      { return INT_LITERAL; }
[a-zA-Z_][a-zA-Z0-9_]* { return ID; }
";"         { return SEMICOLON; }
[ \t\n]     ; /* skip whitespace */
.           { printf("Unknown: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}