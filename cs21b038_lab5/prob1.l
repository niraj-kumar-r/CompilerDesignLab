%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
%}
digit [0-9]
%%
{digit}+ 							return NUMBER;
"i"         						return I;
"+"      							return ADD;
"-"      							return SUB;
";"									return SCOL;
[ \t\n]+     {};      /* ignore white space */
.           {return yytext[0];}; /* ignore all other characters */

%%