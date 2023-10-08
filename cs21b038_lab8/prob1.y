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

struct I_Node{
	struct I_Node *left, *right;
	char token[20];
	char lexeme[20];
	char temp_var[20];
	char true_label[20];
	char false_label[20];
	char next_label[20];
	int ival;
};

void postorder(struct I_Node *root);
void inorder(struct I_Node *root);
void preorder(struct I_Node *root);
void printNode(struct I_Node *root);
void freeTree(struct I_Node *root);
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

slist : 	assignmentexpression SEMICOLON {
				$$ = malloc(sizeof(struct I_Node));
				if ($$ == NULL) {
					yyerror("no mem");
				}
				$$ = $1;
			} slist
			| IF LPAREN booleanexpression RPAREN LBRACE {
				$$ = malloc(sizeof(struct I_Node));
				if ($$ == NULL) {
					yyerror("no mem");
				}
				strcpy($$->token, "KEYWORD");
				strcpy($$->lexeme, "if else");
				genLabel();
				strcpy($$->true_label, label_g);
				strcpy($3->true_label, label_g);
				genLabel();
				strcpy($$->false_label, label_g);
				strcpy($3->false_label, label_g);
				genLabel();
				strcpy($$->next_label, label_g);
				strcpy($3->next_label, label_g);

				printf("if %s goto %s\n", $3->temp_var, $$->true_label);
				printf("goto %s\n\n", $$->false_label);
				printf("\n\n%s:\n\n", $3->true_label);
			} slist {
				printf("goto %s\n\n", $3->next_label);
			} RBRACE ELSE LBRACE {
				printf("\n\n%s:\n\n", $3->false_label);
			} slist RBRACE {
				printf("\n\n%s:\n\n", $3->next_label);
			} slist
			| error{ printf("\nRejected EXPR\n"); } SEMICOLON  slist
			| {freeTree($$);} ;
			

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
								genTemp();
								strcpy($$->temp_var, temp_var_g);
								printf("%s = %s\n", $1->temp_var, $3->temp_var);
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
								strcpy($$->temp_var, $1->temp_var);
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
								strcpy($$->temp_var, $1->temp_var);
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
								strcpy($$->temp_var, $2->temp_var);
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
								strcpy($$->temp_var, $2->temp_var);
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
				genTemp();
				strcpy($$->temp_var, temp_var_g);
				printf("%s = %s\n", $$->temp_var, $$->lexeme);
			};
			| LPAREN variable RPAREN {
				$$ = malloc(sizeof(struct I_Node));
				if ($$ == NULL) {
					yyerror("no mem");
				}
				$$ = $2;
			};

booleanexpression	:	primaryexpression {
							$$ = malloc(sizeof(struct I_Node));
							if ($$ == NULL) {
								yyerror("no mem");
							}
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
							genTemp();
							strcpy($$->temp_var, temp_var_g);
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
							genTemp();
							strcpy($$->temp_var, temp_var_g);
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
							genTemp();
							strcpy($$->temp_var, temp_var_g);
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
							genTemp();
							strcpy($$->temp_var, temp_var_g);
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
							genTemp();
							strcpy($$->temp_var, temp_var_g);
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
							genTemp();
							strcpy($$->temp_var, temp_var_g);
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
							genTemp();
							strcpy($$->temp_var, temp_var_g);
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
							genTemp();
							strcpy($$->temp_var, temp_var_g);
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
							genTemp();
							strcpy($$->temp_var, temp_var_g);
							printf("%s = !%s\n", $$->temp_var, $2->temp_var);
						};

additiveexpression : 	multiplicativeexpression {
							$$ = malloc(sizeof(struct I_Node));
							if ($$ == NULL) {
								yyerror("no mem");
							}
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
							genTemp();
							strcpy($$->temp_var, temp_var_g);
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
							genTemp();
							strcpy($$->temp_var, temp_var_g);
							printf("%s = %s - %s\n", $$->temp_var, $1->temp_var, $3->temp_var);
						};

multiplicativeexpression : 	unaryexpression {
								$$ = malloc(sizeof(struct I_Node));
								if ($$ == NULL) {
									yyerror("no mem");
								}
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
								genTemp();
								strcpy($$->temp_var, temp_var_g);
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
								genTemp();
								strcpy($$->temp_var, temp_var_g);
								printf("%s = %s / %s\n", $$->temp_var, $1->temp_var, $3->temp_var);
							};

unaryexpression : 	postfixexpression {
						$$ = malloc(sizeof(struct I_Node));
						if ($$ == NULL) {
							yyerror("no mem");
						}
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
						strcpy($$->temp_var, $2->temp_var);
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
						strcpy($$->temp_var, $2->temp_var);
						printf("%s = %s - 1\n", $$->temp_var, $2->temp_var);
					}
					| ADD unaryexpression {
						$$ = malloc(sizeof(struct I_Node));
						if ($$ == NULL) {
							yyerror("no mem");
						}
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
						genTemp();
						strcpy($$->temp_var, temp_var_g);
						printf("%s = -1 * %s\n", $$->temp_var, $2->temp_var);
					};

postfixexpression : 	primaryexpression {
							$$ = malloc(sizeof(struct I_Node));
							if ($$ == NULL) {
								yyerror("no mem");
							}
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
							strcpy($$->temp_var, $1->temp_var);
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
							strcpy($$->temp_var, $1->temp_var);
							printf("%s = %s - 1\n", $$->temp_var, $1->temp_var);
						};

primaryexpression : 	constant {
							$$ = malloc(sizeof(struct I_Node));
							if ($$ == NULL) {
								yyerror("no mem");
							}
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
							genTemp();
							strcpy($$->temp_var, temp_var_g);
							printf("%s = %s\n", $$->temp_var, $$->lexeme);
					}
					| 	LPAREN additiveexpression RPAREN {
							$$ = malloc(sizeof(struct I_Node));
							if ($$ == NULL) {
								yyerror("no mem");
							}
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
				genTemp();
				strcpy($$->temp_var, temp_var_g);
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

void freeTree(struct I_Node *root){
	if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
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
