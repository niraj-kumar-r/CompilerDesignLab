%{
#include <stdio.h>
#include <string.h>
#include "symbol_table.h"
%}

KEYWORDS "auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"

%%
[\t\r ]+          {};
\/\/[^\n]*        {};
\/\*([^*]|\*+[^*/])*\*+\/  {};
[0-9]+            { addToSymbolTable(yytext, "integer"); }
[0-9]+"."[0-9]+   { addToSymbolTable(yytext, "float"); }
\"([^\\\"]|\\.)*\" { addToSymbolTable(yytext, "string"); }
\'([^\\\']|\\.)\' { addToSymbolTable(yytext, "char"); }
{KEYWORDS}        { addToSymbolTable(yytext, "keyword"); }
[a-zA-Z_][a-zA-Z_0-9]* { addToSymbolTable(yytext, "identifier"); }
[-+*/%]          { addToSymbolTable(yytext, "arithmetic_operator"); }
[&|]              { addToSymbolTable(yytext, "logical_operator"); }
\<                 { addToSymbolTable(yytext, "less_than"); }
\>                 { addToSymbolTable(yytext, "greater_than"); }
\=                { addToSymbolTable(yytext, "assign"); }
[=!<>]=           { addToSymbolTable(yytext, "relational_operator"); }
\;                { addToSymbolTable(yytext, "semicolon"); }
\{                { addToSymbolTable(yytext, "left_brace"); }
\}                { addToSymbolTable(yytext, "right_brace"); }
\(                { addToSymbolTable(yytext, "left_parenthesis"); }
\)                { addToSymbolTable(yytext, "right_parenthesis"); }


%%

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        printf("Error opening file\n");
        return 1;
    }

    yyin = input_file;
    yylex();

    fclose(input_file);

    writeSymbolTableToFile("symbol_table.txt");
    printSymbolTable();
    
    return 0;
}
