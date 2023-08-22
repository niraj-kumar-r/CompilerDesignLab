// symbol_table.h
#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

typedef struct
{
    char lexeme[100];
    char tokenType[20];
    // int size;
    // int usage;
} SymbolEntry;

void addToSymbolTable(const char *lexeme, const char *tokenType);
void writeSymbolTableToFile(const char *filename);
void printSymbolTable();

#endif
