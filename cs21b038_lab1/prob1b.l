%{
#include <stdio.h>
void check(char *s) {
    // in w the number of xs modulo 2 is equal to the number of ys modulo 3

    int x = 0;
    int y = 0;
    int z = 0;
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == 'x') {
            x++;
        } else if (s[i] == 'y') {
            y++;
        } else if (s[i] == 'z') {
            z++;
        }
        i++;
    }

    if (x % 2 == y % 3) {
        printf("Accepted %s", s);
    } else {
        printf("Rejected %s", s);
    }
}
%}

%%
("x"|"y"|"z")* {check(yytext);}
.+       {printf("Rejected %s", yytext);}
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
