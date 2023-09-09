%{
#include<stdio.h>
int yylex();
int yyerror(char *);
int eflag=0;
extern FILE * yyin;
%}

%token NUMBER I ADD SUB SCOL
%%

slist : 	stmt SCOL {printf("VALID\n");} slist
            |  error { printf("INVALID\n"); } SCOL slist
            | {printf("\n\nCompleted..!\n");} ;
stmt 	:	real op imag ;
real    :   NUMBER | SUB NUMBER ;
op      :   ADD | SUB ;
imag    :   I NUMBER | NUMBER I ;

%%

int yyerror(char *s){
    return 0;
}

int main(int argc, char* argv[])
{
	if(argc > 1)
	{
		FILE *fp = fopen(argv[1], "r");
		if(fp)
			yyin = fp;
	}
	yyparse();
	return 0;
}
