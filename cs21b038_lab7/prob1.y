%{
#include <stdio.h>
#include <string.h>
int yylex();
int yyerror(char *);
int eflag=0;
extern FILE * yyin;

struct I_Node{
	struct I_Node *left, *right;
	char token[20];
	char lexeme[20];
	int ival;
};

void postorder(struct I_Node *root);
void inorder(struct I_Node *root);
void preorder(struct I_Node *root);
void printNode(struct I_Node *root);

%}


%union{
	int ival;
	char lexeme[20];
	struct I_Node *node;
}

%token ADD SUB MUL DIV INC DEC ASSIGN LPAREN RPAREN SEMICOLON
%token <ival> INTEGER
%token <lexeme> IDENTIFIER
%type <node> slist stmt variable additiveexpression multiplicativeexpression unaryexpression postfixexpression primaryexpression constant


%%

slist : 	stmt SEMICOLON {
				printf("\nAccepted EXPR\n");
				printf("Preorder traversal\n");
				preorder($1);
				printf("\nPostorder traversal\n");
				postorder($1);
				printf("\n\n");
			} slist
            |  error { printf("\nRejected EXPR\n"); } SEMICOLON slist
            | {printf("\n\nCompleted..!\n");} ;

stmt 	:	variable ASSIGN additiveexpression {
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
			}
			| LPAREN variable RPAREN {
				$$ = $2;
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
