%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
%}

%%
"+"     { return ADD; }
"-"     { return SUB; }
"*"     { return MUL; }
"/"     { return DIV; }
"("     { return LPAREN; }
")"     { return RPAREN; }
"="     { return ASSIGN; }
"--"    { return DEC; }
"++"    { return INC; }
";"     { return SEMICOLON; }
[a-zA-Z][a-zA-Z0-9]*   { return IDENTIFIER; }
[0-9]+\.[0-9]+  { return FLOAT; }
[0-9]+  { return INTEGER; }
[ \t\n]+     {};      /* ignore white space */
.           {return yytext[0];}; /* ignore all other characters */

%%