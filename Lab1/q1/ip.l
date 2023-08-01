%{
#include <stdio.h>
%}

DIGIT [0-9]
HEX_DIGIT [0-9A-Fa-f]
OCT_DIGIT [0-7]

%%
[01]+           { printf("%s is a binary number.\n", yytext); }
{OCT_DIGIT}+    { printf("%s is an octal number.\n", yytext); }
{DIGIT}+        { printf("%s is a decimal number.\n", yytext); }
{HEX_DIGIT}+    { printf("%s is a hexadecimal number.\n", yytext); }
.+              { printf("%s is not a valid number.\n", yytext); }
%%

int yywrap() {}
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s input_file\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Error opening input file");
        return 1;
    }

    yylex();

    fclose(yyin);

    return 0;
}
