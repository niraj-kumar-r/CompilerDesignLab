%{
#include <stdio.h>
#include <string.h>
int yylex();
int yyerror(char *);
int eflag=0;
int label_count=0;
int temp_count=0;
extern FILE * yyin;

struct I_Node{
	struct I_Node *left, *right;
	char token[20];
	char lexeme[20];
	char temp_var[20];
	char true_label[20];
	char false_label[20];
	int ival;
};

void postorder(struct I_Node *root);
void inorder(struct I_Node *root);
void preorder(struct I_Node *root);
void printNode(struct I_Node *root);
char *genTemp();
char *genLabel();

%}


%union{
	int ival;
	char lexeme[20];
	struct I_Node *node;
}

%token ADD SUB MUL DIV INC DEC ASSIGN LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET SEMICOLON IF ELSE LT GT LEQ GEQ EQ NEQ AND OR NOT
%token <ival> INTEGER
%token <lexeme> IDENTIFIER
%type <node> slist assignmentexpression variable additiveexpression multiplicativeexpression unaryexpression postfixexpression primaryexpression constant booleanexpression


%%

prog : slist {
				printf("\nAccepted slist\n");
			} prog 
		| selectionstatement{
			printf("\nAccepted if else statement\n");
		} prog 
		| error{ printf("\nRejected EXPR\n"); } prog 
		| {};

selectionstatement : IF LPAREN booleanexpression RPAREN LBRACE prog RBRACE ELSE LBRACE prog RBRACE 
					| IF LPAREN booleanexpression RPAREN LBRACE prog RBRACE;

slist : 	assignmentexpression SEMICOLON ;

assignmentexpression 	:	variable ASSIGN additiveexpression {
								$$ = malloc(sizeof(struct I_Node));
								if ($$ == NULL) {
									yyerror("no mem");
								}
								strcpy($$->lexeme, $1->lexeme);
								$$->left = $1;
								$$->right = $3;
								$$->ival = $3->ival;
								strcpy($$->token,"ASSIGN");
								strcpy($$->lexeme, "=");
								strcpy($$->temp_var, genTemp());
								printf("%s = %s + %s\n", $$->temp_var, $1->temp_var, $3->temp_var);
							}
							| variable INC{
								$$ = malloc(sizeof(struct I_Node));
								if ($$ == NULL) {
									yyerror("no mem");
								}
								$$->left = $1;
								$$->right = NULL;
								$$->ival = $1->ival + 1;
								strcpy($$->token, "OP");
								strcpy($$->lexeme, "++");
								strcpy($$->temp_var, genTemp());
								printf("%s = %s + 1\n", $$->temp_var, $1->temp_var);
							}
							| variable DEC {
								$$ = malloc(sizeof(struct I_Node));
								if ($$ == NULL) {
									yyerror("no mem");
								}
								$$->left = $1;
								$$->right = NULL;
								$$->ival = $1->ival - 1;
								strcpy($$->token, "OP");
								strcpy($$->lexeme, "--");
								strcpy($$->temp_var, genTemp());
								printf("%s = %s - 1\n", $$->temp_var, $1->temp_var);
							}
							| INC variable {
								$$ = malloc(sizeof(struct I_Node));
								if ($$ == NULL) {
									yyerror("no mem");
								}
								$$->left = NULL;
								$$->right = $2;
								$$->ival = $2->ival + 1;
								strcpy($$->token, "OP");
								strcpy($$->lexeme, "++");
								strcpy($$->temp_var, genTemp());
								printf("%s = %s + 1\n", $$->temp_var, $2->temp_var);
							}
							| DEC variable {
								$$ = malloc(sizeof(struct I_Node));
								if ($$ == NULL) {
									yyerror("no mem");
								}
								$$->left = NULL;
								$$->right = $2;
								$$->ival = $2->ival - 1;
								strcpy($$->token, "OP");
								strcpy($$->lexeme, "--");
								strcpy($$->temp_var, genTemp());
								printf("%s = %s - 1\n", $$->temp_var, $2->temp_var);
							};

variable : 	IDENTIFIER {
				$$ = malloc(sizeof(struct I_Node));
				if ($$ == NULL) {
					yyerror("no mem");
				}
				strcpy($$->lexeme, $1);
				strcpy($$->token,"ID");
				$$->left = NULL;
				$$->right = NULL;
				strcpy($$->temp_var, genTemp());
				printf("%s = %s\n", $$->temp_var, $$->lexeme);
			};
			| LPAREN variable RPAREN {
				$$ = $2;
			};

booleanexpression	:	primaryexpression {
							$$ = $1;
						}
						| primaryexpression LT primaryexpression{
							$$ = malloc(sizeof(struct I_Node));
							if ($$ == NULL) {
								yyerror("no mem");
							}
							$$->left = $1;
							$$->right = $3;
							$$->ival = $1->ival < $3->ival;
							strcpy($$->token, "OP");
							strcpy($$->lexeme, "<");
							strcpy($$->temp_var, genTemp());
							printf("%s = %s < %s\n", $$->temp_var, $1->temp_var, $3->temp_var);
						}
						| primaryexpression GT primaryexpression{
							$$ = malloc(sizeof(struct I_Node));
							if ($$ == NULL) {
								yyerror("no mem");
							}
							$$->left = $1;
							$$->right = $3;
							$$->ival = $1->ival > $3->ival;
							strcpy($$->token, "OP");
							strcpy($$->lexeme, ">");
							strcpy($$->temp_var, genTemp());
							printf("%s = %s > %s\n", $$->temp_var, $1->temp_var, $3->temp_var);
						}
						| primaryexpression LEQ primaryexpression{
							$$ = malloc(sizeof(struct I_Node));
							if ($$ == NULL) {
								yyerror("no mem");
							}
							$$->left = $1;
							$$->right = $3;
							$$->ival = $1->ival <= $3->ival;
							strcpy($$->token, "OP");
							strcpy($$->lexeme, "<=");
							strcpy($$->temp_var, genTemp());
							printf("%s = %s <= %s\n", $$->temp_var, $1->temp_var, $3->temp_var);
						}
						| primaryexpression GEQ primaryexpression{
							$$ = malloc(sizeof(struct I_Node));
							if ($$ == NULL) {
								yyerror("no mem");
							}
							$$->left = $1;
							$$->right = $3;
							$$->ival = $1->ival >= $3->ival;
							strcpy($$->token, "OP");
							strcpy($$->lexeme, ">=");
							strcpy($$->temp_var, genTemp());
							printf("%s = %s >= %s\n", $$->temp_var, $1->temp_var, $3->temp_var);
						}
						| primaryexpression EQ primaryexpression{
							$$ = malloc(sizeof(struct I_Node));
							if ($$ == NULL) {
								yyerror("no mem");
							}
							$$->left = $1;
							$$->right = $3;
							$$->ival = $1->ival == $3->ival;
							strcpy($$->token, "OP");
							strcpy($$->lexeme, "==");
							strcpy($$->temp_var, genTemp());
							printf("%s = %s == %s\n", $$->temp_var, $1->temp_var, $3->temp_var);
						}
						| primaryexpression NEQ primaryexpression{
							$$ = malloc(sizeof(struct I_Node));
							if ($$ == NULL) {
								yyerror("no mem");
							}
							$$->left = $1;
							$$->right = $3;
							$$->ival = $1->ival != $3->ival;
							strcpy($$->token, "OP");
							strcpy($$->lexeme, "!=");
							strcpy($$->temp_var, genTemp());
							printf("%s = %s != %s\n", $$->temp_var, $1->temp_var, $3->temp_var);
						}
						| primaryexpression AND primaryexpression{
							$$ = malloc(sizeof(struct I_Node));
							if ($$ == NULL) {
								yyerror("no mem");
							}
							$$->ival = $1->ival && $3->ival;
							$$->left = $1;
							$$->right = $3;
							strcpy($$->token, "OP");
							strcpy($$->lexeme, "&&");
							strcpy($$->temp_var, genTemp());
							printf("%s = %s && %s\n", $$->temp_var, $1->temp_var, $3->temp_var);
						}
						| primaryexpression OR primaryexpression{
							$$ = malloc(sizeof(struct I_Node));
							if ($$ == NULL) {
								yyerror("no mem");
							}
							$$->ival = $1->ival || $3->ival;
							$$->left = $1;
							$$->right = $3;
							strcpy($$->token, "OP");
							strcpy($$->lexeme, "||");
							strcpy($$->temp_var, genTemp());
							printf("%s = %s || %s\n", $$->temp_var, $1->temp_var, $3->temp_var);

						}
						| NOT primaryexpression{
							$$ = malloc(sizeof(struct I_Node));
							if ($$ == NULL) {
								yyerror("no mem");
							}
							$$->ival = !$2->ival;
							$$->left = NULL;
							$$->right = $2;
							strcpy($$->token, "OP");
							strcpy($$->lexeme, "!");
							strcpy($$->temp_var, genTemp());
							printf("%s = !%s\n", $$->temp_var, $2->temp_var);
						};

additiveexpression : 	multiplicativeexpression {
							$$ = $1;
						}
						| additiveexpression ADD multiplicativeexpression {
							$$ = malloc(sizeof(struct I_Node));
							if ($$ == NULL) {
								yyerror("no mem");
							}
							$$->left = $1;
							$$->right = $3;
							$$->ival = $1->ival + $3->ival;
							strcpy($$->token, "OP");
							strcpy($$->lexeme, "+");
							strcpy($$->temp_var, genTemp());
							printf("%s = %s + %s\n", $$->temp_var, $1->temp_var, $3->temp_var);
						}
						| additiveexpression SUB multiplicativeexpression {
							$$ = malloc(sizeof(struct I_Node));
							if ($$ == NULL) {
								yyerror("no mem");
							}
							$$->left = $1;
							$$->right = $3;
							$$->ival = $1->ival - $3->ival;
							strcpy($$->token, "OP");
							strcpy($$->lexeme, "-");
							strcpy($$->temp_var, genTemp());
							printf("%s = %s - %s\n", $$->temp_var, $1->temp_var, $3->temp_var);
						};

multiplicativeexpression : 	unaryexpression {
								$$ = $1;
							}
							| multiplicativeexpression MUL unaryexpression {
								$$ = malloc(sizeof(struct I_Node));
								if ($$ == NULL) {
									yyerror("no mem");
								}
								$$->left = $1;
								$$->right = $3;
								$$->ival = $1->ival * $3->ival;
								strcpy($$->token, "OP");
								strcpy($$->lexeme, "*");
								strcpy($$->temp_var, genTemp());
								printf("%s = %s * %s\n", $$->temp_var, $1->temp_var, $3->temp_var);
							}
							| multiplicativeexpression DIV unaryexpression {
								$$ = malloc(sizeof(struct I_Node));
								if ($$ == NULL) {
									yyerror("no mem");
								}
								$$->left = $1;
								$$->right = $3;
								$$->ival = $1->ival / $3->ival;
								strcpy($$->token, "OP");
								strcpy($$->lexeme, "/");
								strcpy($$->temp_var, genTemp());
								printf("%s = %s / %s\n", $$->temp_var, $1->temp_var, $3->temp_var);
							};

unaryexpression : 	postfixexpression {
						$$ = $1;
					}
					| INC unaryexpression {
						$$ = malloc(sizeof(struct I_Node));
						if ($$ == NULL) {
							yyerror("no mem");
						}
						$$->left = NULL;
						$$->right = $2;
						$$->ival = $2->ival + 1;
						strcpy($$->token, "OP");
						strcpy($$->lexeme, "++");
						strcpy($$->temp_var, genTemp());
						printf("%s = %s + 1\n", $$->temp_var, $2->temp_var);
					}
					| DEC unaryexpression {
						$$ = malloc(sizeof(struct I_Node));
						if ($$ == NULL) {
							yyerror("no mem");
						}
						$$->left = NULL;
						$$->right = $2;
						$$->ival = $2->ival - 1;
						strcpy($$->token, "OP");
						strcpy($$->lexeme, "--");
						strcpy($$->temp_var, genTemp());
						printf("%s = %s - 1\n", $$->temp_var, $2->temp_var);
					}
					| ADD unaryexpression {
						$$ = $2;
					}
					| SUB unaryexpression {
						$$ = malloc(sizeof(struct I_Node));
						if ($$ == NULL) {
							yyerror("no mem");
						}
						$$->left = $2;
						$$->right = NULL;
						$$->ival = -1 * $2->ival;
						strcpy($$->token, "OP");
						strcpy($$->lexeme, "negative");
						strcpy($$->temp_var, genTemp());
						printf("%s = -1 * %s\n", $$->temp_var, $2->temp_var);
					};

postfixexpression : 	primaryexpression {
							$$ = $1;
						}
						| postfixexpression INC {
							$$ = malloc(sizeof(struct I_Node));
							if ($$ == NULL) {
								yyerror("no mem");
							}
							$$->left = $1;
							$$->right = NULL;
							$$->ival = $1->ival + 1;
							strcpy($$->token, "OP");
							strcpy($$->lexeme, "++");
							strcpy($$->temp_var, genTemp());
							printf("%s = %s + 1\n", $$->temp_var, $1->temp_var);
						};
						| postfixexpression DEC {
							$$ = malloc(sizeof(struct I_Node));
							if ($$ == NULL) {
								yyerror("no mem");
							}
							$$->left = $1;
							$$->right = NULL;
							$$->ival = $1->ival - 1;
							strcpy($$->token, "OP");
							strcpy($$->lexeme, "--");
							strcpy($$->temp_var, genTemp());
							printf("%s = %s - 1\n", $$->temp_var, $1->temp_var);
						};

primaryexpression : 	constant {
							$$ = $1;
						}
					| 	IDENTIFIER {
							$$ = malloc(sizeof(struct I_Node));
							if ($$ == NULL) {
								yyerror("no mem");
							}
							strcpy($$->lexeme, $1);
							$$->left = NULL;
							$$->right = NULL;
							strcpy($$->token, "ID");
							strcpy($$->temp_var, genTemp());
							printf("%s = %s\n", $$->temp_var, $$->lexeme);
					}
					| 	LPAREN additiveexpression RPAREN {
							$$ = $2;
					};

constant : 	INTEGER {
				$$ = malloc(sizeof(struct I_Node));
				if ($$ == NULL) {
					yyerror("no mem");
				}
				$$->ival = $1;
				$$->left = NULL;
				$$->right = NULL;
				strcpy($$->token, "CONST");
				strcpy($$->lexeme, "INT");
				strcpy($$->temp_var, genTemp());
				printf("%s = %i\n", $$->temp_var, $$->ival);
			};

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

void postorder(struct I_Node *root)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printNode(root);
	}
}

void inorder(struct I_Node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printNode(root);
		inorder(root->right);
	}
}

void preorder(struct I_Node *root)
{
	if(root != NULL)
	{
		printNode(root);
		preorder(root->left);
		preorder(root->right);
	}
}

void printNode(struct I_Node *root)
{
	if(root != NULL)
	{
		if(strcmp(root->token, "ID") == 0 || strcmp(root->token, "OP")==0 || strcmp(root->token, "ASSIGN") == 0){
			printf("%s \t %s \n", root->token, root->lexeme);
		}
		else{
			printf("%s \t %i\n", root->lexeme, root->ival);
		}
	}
}

char *genTemp()
{
	char temp[20];
	sprintf(temp, "t%d", temp_count);
	temp_count++;
	return temp;
}

char *genLabel()
{
	char label[20];
	sprintf(label, "L%d", label_count);
	label_count++;
	return label;
}
