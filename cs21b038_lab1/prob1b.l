%{
#include <stdio.h>
%}

%%
.*00.*  { printf("Rejected %s", yytext); }
.*111.* { printf("Accepted %s", yytext); }
(1|0)*  { printf("Rejected %s", yytext); }
.       { }
%%

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s input_file\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("Error opening input file");
        return 1;
    }

    yyin = input_file;

    yylex();

    fclose(input_file);

    return 0;

}
