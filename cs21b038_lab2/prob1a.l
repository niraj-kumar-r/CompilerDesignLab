%{
#include <stdio.h>
#include <stdbool.h>

bool accepted = false;

void check() {
    if (accepted) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }
    accepted = false;
}
%}

%%
.*111.* { accepted = true; }
.*00.*  { accepted = false; }
\n      { check(); }
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


