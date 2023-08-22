#include "symbol_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 5000
static SymbolEntry symbolTable[MAX_ENTRIES];
static int numEntries = 0;

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
        // Print more fields as needed
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
