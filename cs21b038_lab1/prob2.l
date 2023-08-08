%{
#include <stdio.h>
void check(char *s, int n) {
    
    for(int i =0; i<n-2; i++){
        if(s[i] < 'a' || s[i] > 'd'){
            if(s[i-1]==s[n-1]){
                printf("Matched: %s", s);
                return;
            }
            else{
                printf("Unmatched: %s", s);
                return;
            }
        }
    }

}
%}

SIGMA [a-d]
UNSIGMA [^a-d\n]

%%
{SIGMA}+{SIGMA}{UNSIGMA}{SIGMA}+{SIGMA} { check(yytext,yyleng); }
.+ { printf("Unmatched: %s", yytext); }
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
