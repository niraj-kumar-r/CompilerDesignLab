%{
#include <stdio.h>
#include <stdbool.h>
char token;
bool accept = true;

void E();
void E_prime();
void T();
void T_prime();
void F();
%}

%%
"+"  { return yytext[0]; }
"*"  { return yytext[0]; }
"("  { return yytext[0]; }
")"  { return yytext[0]; }
[a-zA-Z_][a-zA-Z_0-9]*  { return 'i'; }
\n   { return 0; }
[^\n]  {}
%%

void E(){
    if(token == 'i' || token == '('){
        T();
        E_prime();
    }
    else{
        accept = false;
    }
}

void E_prime(){
    if(token == '+'){

        token = yylex();
        T();
        E_prime();
    }
    else if(token == ')' || token == 0){
        return;
    }
    else{
        accept = false;
    }
}

void T(){
    if(token == 'i' || token == '('){
        F();
        T_prime();
    }
    else{
        accept = false;
    }
}

void T_prime(){
    if(token == '*'){

        token = yylex();
        F();
        T_prime();
    }
    else if(token == '+' || token == ')' || token == 0){
        return;
    }
    else {
        accept = false;
    }
}

void F(){
    if(token == 'i'){
        token = yylex();
    }
    else if(token == '('){
        token = yylex();
        E();

        if(token == ')'){
            token = yylex();
            return;
        }
        else{
            accept = false;
        }
    }
    else{
        accept = false;
    }
}

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

    token = yylex();
    while(token != 0){
        E();

        if(accept)
            printf("ACCEPT\n");
        else
            printf("REJECT\n");

        accept = true;
        while(token != 0){
            token = yylex();
        }
        token = yylex();
    }

    fclose(input_file);

    return 0;

}
