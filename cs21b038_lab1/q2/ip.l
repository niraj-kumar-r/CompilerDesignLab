%{
#include <stdio.h>
void checkIPV4Address(char* str);
%}

DIGIT [0-9]
DOT \.
IPV4 {DIGIT}+{DOT}{DIGIT}+{DOT}{DIGIT}+{DOT}{DIGIT}+

/* IPV4 address */

%%
{IPV4}          { checkIPV4Address(yytext); }
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

void checkIPV4Address(char* str){
    /* split the address into an array of 4 ints with . as delimiter */
    char* token = strtok(str, ".");
    int ip[4];
    int i = 0;
    while (token != NULL){
        ip[i] = atoi(token);
        if (ip[i] < 0 || ip[i] > 255){
            printf("%s is not a valid IPV4 address.\n", str);
            return;
        }
        token = strtok(NULL, ".");
        i++;
    }

    printf("%s is a valid IPV4 address.\n", str);

}