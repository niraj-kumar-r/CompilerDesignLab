%{
#include <stdio.h>
#include <string.h>
int yylex();
int yyerror(char *);
int eflag=0;
int label_count=0;
int temp_count=0;
char temp_var_g[20];
char label_g[20];
extern FILE * yyin;

%}

%%

%%

int yyerror(char *s){
    return 0;
}

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		printf("Usage: ./parser <filename>\n");
		return 1;
	}
	FILE *fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
		printf("File not found\n");
		return 1;
	}
	yyin = fp;
	yyparse();
	return 0;
}

char *genTemp()
{
	sprintf(temp_var_g, "t%d", temp_count);
	temp_count++;
}

char *genLabel()
{
	sprintf(label_g, "L%d", label_count);
	label_count++;
}