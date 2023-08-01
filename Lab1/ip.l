%{
#include <stdio.h>
int count = 0;
%}

DIGIT       [0-9]

%%

{DIGIT}+    printf("NUMBER: %s", yytext); count++;

%%
int yywrap(){}
int main() {
    yylex();
    printf("\nTotal numbers: %d\n", count);
    return 0;
}


