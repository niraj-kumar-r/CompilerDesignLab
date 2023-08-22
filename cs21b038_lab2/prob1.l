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
void printNextToken(const char *lexeme, const char *tokenType);
%}

KEYWORDS "auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"

%%
[\t\r ]+          {};
\/\/[^\n]*        {};
\/\*([^*]|\*+[^*/])*\*+\/  {};
\#include[^\n]+   {};
\#define[^\n]+    {};
[0-9]+            { printNextToken(yytext, "integer"); }
[0-9]+"."[0-9]+   { printNextToken(yytext, "float"); }
\"([^\\\"]|\\.)*\" { printNextToken(yytext, "string"); }
\'([^\\\']|\\.)\' { printNextToken(yytext, "char"); }
{KEYWORDS}        { printNextToken(yytext, "keyword"); }
[a-zA-Z_][a-zA-Z_0-9]* { printNextToken(yytext, "identifier"); addToSymbolTable(yytext, "identifier"); }
[-+*/%]          { printNextToken(yytext, "arithmetic_operator"); }
[&|]              { printNextToken(yytext, "logical_operator"); }
\<                 { printNextToken(yytext, "less_than"); }
\>                 { printNextToken(yytext, "greater_than"); }
\=                { printNextToken(yytext, "assign"); }
[=!<>]=           { printNextToken(yytext, "relational_operator"); }
\;                { printNextToken(yytext, "semicolon"); }
\{                { printNextToken(yytext, "left_brace"); }
\}                { printNextToken(yytext, "right_brace"); }
\(                { printNextToken(yytext, "left_parenthesis"); }
\)                { printNextToken(yytext, "right_parenthesis"); }
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
    printf("Lexeme\t Token Type\n");
    printf("-------------\n");
    yylex();

    fclose(input_file);

    writeSymbolTableToFile("symbol_table.txt");
    
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

    fprintf(file, "Lexeme\t Token Type\n");
    fprintf(file, "----------------\n");

    for (int i = 0; i < numEntries; i++)
    {
        fprintf(file, "%s\t %s\n", symbolTable[i].lexeme, symbolTable[i].tokenType);
    }

    fclose(file);
}

void printSymbolTable()
{
    printf("Lexeme\t Token Type\n");
    printf("-------------\n");

    for (int i = 0; i < numEntries; i++)
    {
        printf("%s\t %s\n", symbolTable[i].lexeme, symbolTable[i].tokenType);
    }
}

void printNextToken(const char *lexeme, const char *tokenType)
{
    printf("%s\t %s\n", lexeme, tokenType);
}