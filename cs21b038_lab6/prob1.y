%{
#include<stdio.h>
int yylex();
int yyerror(char *);
int eflag=0;
extern FILE * yyin;
%}

%token ADD SUB MUL DIV INC DEC ASSIGN LPAREN RPAREN SEMICOLON INTEGER FLOAT IDENTIFIER

%%

slist : 	stmt SEMICOLON {printf("VALID\n");} slist
            |  error { printf("INVALID\n"); } SEMICOLON slist
            | {printf("\n\nCompleted..!\n");} ;

stmt 	:	variable ASSIGN additiveexpression ;

variable : 	IDENTIFIER
			| LPAREN variable RPAREN;

additiveexpression : 	multiplicativeexpression
						| additiveexpression ADD multiplicativeexpression
						| additiveexpression SUB multiplicativeexpression;

multiplicativeexpression : 	unaryexpression
							| multiplicativeexpression MUL unaryexpression
							| multiplicativeexpression DIV unaryexpression;

unaryexpression : 	postfixexpression
					| INC unaryexpression
					| DEC unaryexpression
					| unaryoperator unaryexpression;

unaryoperator : 	ADD
				| SUB;

postfixexpression : 	primaryexpression
						| postfixexpression INC;
						| postfixexpression DEC;

primaryexpression : 	constant
					| 	IDENTIFIER
					| 	LPAREN additiveexpression RPAREN;

constant : 	INTEGER
			| FLOAT;

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
