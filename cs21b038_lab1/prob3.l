%{
#include <stdio.h>
%}

SCHEME "ftp"|"http"|"https"
SEP1 ":\/\/"
SEP2 "@"
SEP3 ":"
SEP4 "\/"
SEP5 "?"
SEP6 "&"
SEP7 "#"
UsernameAndPasswd [\w.-]+{SEP3}[^\n]+{SEP2}
Host [a-zA-Z_0-9.-]+
Port [0-9]+
Path [a-zA-Z_0-9./-]+
QueryParam [a-zA-Z_0-9%.-]+=([a-zA-Z_0-9%.-]+)
Fragment [a-zA-Z_0-9-]+

URL {SCHEME}{SEP1}{UsernameAndPasswd}?{Host}({SEP3}{Port})?({SEP4}{Path})?(({SEP5}{QueryParam})({SEP6}{QueryParam})*)?({SEP7}{Fragment})?
MAILTOURL "mailto:"[a-zA-Z_0-9.-]+@([a-zA-Z_0-9.-]+)
FILEURL  "file:\/\/"{UsernameAndPasswd}?{Host}?({SEP3}{Port})?({SEP4}{Path})(({SEP5}{QueryParam})({SEP6}{QueryParam})*)?({SEP7}{Fragment})?

%%

{URL} {printf("Accepted %s", yytext);}
{MAILTOURL} {printf("Accepted %s", yytext);}
{FILEURL} {printf("Accepted %s", yytext);}
.+    {printf("Rejected %s", yytext);}

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
