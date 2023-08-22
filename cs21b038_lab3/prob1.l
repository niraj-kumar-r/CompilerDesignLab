%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char lexeme[100];
    char tokenType[20];
    // int size;
    // int usage;
} SymbolEntry;

#define MAX_ENTRIES 5000
static SymbolEntry symbolTable[MAX_ENTRIES];
static int numEntries = 0;

void addToSymbolTable(const char *lexeme, const char *tokenType);
void writeSymbolTableToFile(const char *filename);
void printSymbolTable();
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
\n                {}


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


void addToSymbolTable(const char *lexeme, const char *tokenType)
{
    if (numEntries < MAX_ENTRIES)
    {
        SymbolEntry entry;
        strncpy(entry.lexeme, lexeme, sizeof(entry.lexeme));
        strncpy(entry.tokenType, tokenType, sizeof(entry.tokenType));
        symbolTable[numEntries++] = entry;
    }
}

void writeSymbolTableToFile(const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        printf("Error opening file for writing symbol table\n");
        return;
    }

    fprintf(file, "Symbol Table:\n");
    fprintf(file, "----------------\n");

    for (int i = 0; i < numEntries; i++)
    {
        fprintf(file, "Lexeme: %s, Token Type: %s\n", symbolTable[i].lexeme, symbolTable[i].tokenType);
    }

    fclose(file);
}

void printSymbolTable()
{
    printf("Symbol Table:\n");
    printf("-------------\n");

    for (int i = 0; i < numEntries; i++)
    {
        printf("Lexeme: %s, Token Type: %s\n", symbolTable[i].lexeme, symbolTable[i].tokenType);
    }
}

