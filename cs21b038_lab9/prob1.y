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

typedef struct ASTNode {
    enum { 
        NODETYPE_CONSTANT_INT, 
        NODETYPE_IDENTIFIER, 
        NODETYPE_OPERATOR,
        NODETYPE_IF_ELSE,
        NODETYPE_WHILE
    } token;

    int intValue;
    char lexeme[20];
	char temp_var[20];

    union {
        struct {
            char op[20];
            struct ASTNode* left;
            struct ASTNode* right;
        } opInfo;
        struct {
            struct ASTNode* condition;
			char condition_label[20];
            struct ASTNode* trueBranch;
			char true_label[20];
            struct ASTNode* falseBranch;
			char false_label[20];
            struct ASTNode* nextBranch;
			char next_label[20];
        } flowControlInfo;
    } info;

} ASTNode;

%}

%union{
	int intValue;
	char lexeme[20];
	struct ASTNode *node;
}

%token ADD SUB MUL DIV INC DEC ASSIGN LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET SEMICOLON IF ELSE WHILE LT GT LEQ GEQ EQ NEQ AND OR NOT
%token <intValue> INTEGER
%token <lexeme> IDENTIFIER
%type <node> slist assignmentExpression conditionalExpression logicalOrExpression logicalAndExpression equalityExpression relationalExpression additiveExpression multiplicativeExpression unaryExpression postfixExpression primaryExpression selectionStatement iterationStatement

%%

program : slist {printf("\n\nCompleted\n");};

slist : slist assignmentExpression SEMICOLON {printf("\nAccepted assignment Expression");}
		| slist selectionStatement {printf("\nAccepted selection statement");}
		| slist iterationStatement {printf("\nAccepted iteration statement");}
		| slist error {printf("\nRejected");}
		| {printf("\n");};

assignmentExpression :	conditionalExpression { $$ = $1; }
						| unaryExpression ASSIGN assignmentExpression {
							$$ = malloc(sizeof(struct ASTNode));
							if($$ == NULL){
								printf("Out of memory\n");
								exit(0);
							}
							$$->token = NODETYPE_OPERATOR;
							$$->info.opInfo.left = $1;
							$$->info.opInfo.right = $3;
							strcpy($$->info.opInfo.op, "=");
							genTemp();
							strcpy($$->temp_var, temp_var_g);
							$$->intValue = $3->intValue;
							printf("\n%s = %s", $$->temp_var, $$->info.opInfo.right->temp_var);
						};

conditionalExpression : logicalOrExpression { $$ = $1; };

logicalOrExpression :	logicalAndExpression {
							$$ = $1;
						}
						| logicalOrExpression OR logicalAndExpression {
							$$ = malloc(sizeof(struct ASTNode));
							if($$ == NULL){
								printf("Out of memory\n");
								exit(0);
							}
							$$->token = NODETYPE_OPERATOR;
							$$->info.opInfo.left = $1;
							$$->info.opInfo.right = $3;
							strcpy($$->info.opInfo.op, "||");
							genTemp();
							strcpy($$->temp_var, temp_var_g);
							$$->intValue = $1->intValue || $3->intValue;
							printf("\n%s = %s || %s", $$->temp_var, $$->info.opInfo.left->temp_var, $$->info.opInfo.right->temp_var);
						};

logicalAndExpression :	equalityExpression {
							$$ = $1;
						}
						| logicalAndExpression AND equalityExpression {
							$$ = malloc(sizeof(struct ASTNode));
							if($$ == NULL){
								printf("Out of memory\n");
								exit(0);
							}
							$$->token = NODETYPE_OPERATOR;
							$$->info.opInfo.left = $1;
							$$->info.opInfo.right = $3;
							strcpy($$->info.opInfo.op, "&&");
							genTemp();
							strcpy($$->temp_var, temp_var_g);
							$$->intValue = $1->intValue && $3->intValue;
							printf("\n%s = %s && %s", $$->temp_var, $$->info.opInfo.left->temp_var, $$->info.opInfo.right->temp_var);
						};

equalityExpression :	relationalExpression {
							$$ = $1;
						}
						| equalityExpression EQ relationalExpression {
							$$ = malloc(sizeof(struct ASTNode));
							if($$ == NULL){
								printf("Out of memory\n");
								exit(0);
							}
							$$->token = NODETYPE_OPERATOR;
							$$->info.opInfo.left = $1;
							$$->info.opInfo.right = $3;
							strcpy($$->info.opInfo.op, "==");
							genTemp();
							strcpy($$->temp_var, temp_var_g);
							$$->intValue = $1->intValue == $3->intValue;
							printf("\n%s = %s == %s", $$->temp_var, $$->info.opInfo.left->temp_var, $$->info.opInfo.right->temp_var);
						}
						| equalityExpression NEQ relationalExpression {
							$$ = malloc(sizeof(struct ASTNode));
							if($$ == NULL){
								printf("Out of memory\n");
								exit(0);
							}
							$$->token = NODETYPE_OPERATOR;
							$$->info.opInfo.left = $1;
							$$->info.opInfo.right = $3;
							strcpy($$->info.opInfo.op, "!=");
							genTemp();
							strcpy($$->temp_var, temp_var_g);
							$$->intValue = $1->intValue != $3->intValue;
							printf("\n%s = %s != %s", $$->temp_var, $$->info.opInfo.left->temp_var, $$->info.opInfo.right->temp_var);
						};

relationalExpression :	additiveExpression {
							$$ = $1;
						}
						| relationalExpression LT additiveExpression {
							$$ = malloc(sizeof(struct ASTNode));
							if($$ == NULL){
								printf("Out of memory\n");
								exit(0);
							}
							$$->token = NODETYPE_OPERATOR;
							$$->info.opInfo.left = $1;
							$$->info.opInfo.right = $3;
							strcpy($$->info.opInfo.op, "<");
							genTemp();
							strcpy($$->temp_var, temp_var_g);
							$$->intValue = $1->intValue < $3->intValue;
							printf("\n%s = %s < %s", $$->temp_var, $$->info.opInfo.left->temp_var, $$->info.opInfo.right->temp_var);
						}
						| relationalExpression GT additiveExpression {
							$$ = malloc(sizeof(struct ASTNode));
							if($$ == NULL){
								printf("Out of memory\n");
								exit(0);
							}
							$$->token = NODETYPE_OPERATOR;
							$$->info.opInfo.left = $1;
							$$->info.opInfo.right = $3;
							strcpy($$->info.opInfo.op, ">");
							genTemp();
							strcpy($$->temp_var, temp_var_g);
							$$->intValue = $1->intValue > $3->intValue;
							printf("\n%s = %s > %s", $$->temp_var, $$->info.opInfo.left->temp_var, $$->info.opInfo.right->temp_var);
						}
						| relationalExpression LEQ additiveExpression {
							$$ = malloc(sizeof(struct ASTNode));
							if($$ == NULL){
								printf("Out of memory\n");
								exit(0);
							}
							$$->token = NODETYPE_OPERATOR;
							$$->info.opInfo.left = $1;
							$$->info.opInfo.right = $3;
							strcpy($$->info.opInfo.op, "<=");
							genTemp();
							strcpy($$->temp_var, temp_var_g);
							$$->intValue = $1->intValue <= $3->intValue;
							printf("\n%s = %s <= %s", $$->temp_var, $$->info.opInfo.left->temp_var, $$->info.opInfo.right->temp_var);
						}
						| relationalExpression GEQ additiveExpression {
							$$ = malloc(sizeof(struct ASTNode));
							if($$ == NULL){
								printf("Out of memory\n");
								exit(0);
							}
							$$->token = NODETYPE_OPERATOR;
							$$->info.opInfo.left = $1;
							$$->info.opInfo.right = $3;
							strcpy($$->info.opInfo.op, ">=");
							genTemp();
							strcpy($$->temp_var, temp_var_g);
							$$->intValue = $1->intValue >= $3->intValue;
							printf("\n%s = %s >= %s", $$->temp_var, $$->info.opInfo.left->temp_var, $$->info.opInfo.right->temp_var);
						};

additiveExpression : multiplicativeExpression {
						$$ = $1;
					}
					| additiveExpression ADD multiplicativeExpression {
						$$ = malloc(sizeof(struct ASTNode));
						if($$ == NULL){
							printf("Out of memory\n");
							exit(0);
						}

						$$->token = NODETYPE_OPERATOR;
						$$->info.opInfo.left = $1;
						$$->info.opInfo.right = $3;
						strcpy($$->info.opInfo.op, "+");
						genTemp();
						strcpy($$->temp_var, temp_var_g);
						$$->intValue = $1->intValue + $3->intValue;
						printf("\n%s = %s + %s", $$->temp_var, $$->info.opInfo.left->temp_var, $$->info.opInfo.right->temp_var);
					}
					| additiveExpression SUB multiplicativeExpression {
						$$ = malloc(sizeof(struct ASTNode));
						if($$ == NULL){
							printf("Out of memory\n");
							exit(0);
						}
						$$->token = NODETYPE_OPERATOR;
						$$->info.opInfo.left = $1;
						$$->info.opInfo.right = $3;
						strcpy($$->info.opInfo.op, "-");
						genTemp();
						strcpy($$->temp_var, temp_var_g);
						$$->intValue = $1->intValue - $3->intValue;
						printf("\n%s = %s - %s", $$->temp_var, $$->info.opInfo.left->temp_var, $$->info.opInfo.right->temp_var);
					};

multiplicativeExpression :	unaryExpression {
								$$ = $1;
							}
							| multiplicativeExpression MUL unaryExpression {
								$$ = malloc(sizeof(struct ASTNode));
								if($$ == NULL){
									printf("Out of memory\n");
									exit(0);
								}
								$$->token = NODETYPE_OPERATOR;
								$$->info.opInfo.left = $1;
								$$->info.opInfo.right = $3;
								strcpy($$->info.opInfo.op, "*");
								genTemp();
								strcpy($$->temp_var, temp_var_g);
								$$->intValue = $1->intValue * $3->intValue;
								printf("\n%s = %s * %s", $$->temp_var, $$->info.opInfo.left->temp_var, $$->info.opInfo.right->temp_var);
							}
							| multiplicativeExpression DIV unaryExpression {
								$$ = malloc(sizeof(struct ASTNode));
								if($$ == NULL){
									printf("Out of memory\n");
									exit(0);
								}
								$$->token = NODETYPE_OPERATOR;
								$$->info.opInfo.left = $1;
								$$->info.opInfo.right = $3;
								strcpy($$->info.opInfo.op, "/");
								genTemp();
								strcpy($$->temp_var, temp_var_g);
								$$->intValue = $1->intValue / $3->intValue;
								printf("\n%s = %s / %s", $$->temp_var, $$->info.opInfo.left->temp_var, $$->info.opInfo.right->temp_var);
							};

unaryExpression :	postfixExpression {
						$$ = $1;
					}
					| INC unaryExpression {
						$$ = malloc(sizeof(struct ASTNode));
						if($$ == NULL){
							printf("Out of memory\n");
							exit(0);
						}
						$$->token = NODETYPE_OPERATOR;
						$$->info.opInfo.right = $2;
						strcpy($$->info.opInfo.op, "++");
						genTemp();
						strcpy($$->temp_var, temp_var_g);
						$2->intValue = $2->intValue + 1;
						printf("\n%s = %s + 1", $2->temp_var, $2->temp_var);
						$$->intValue = $2->intValue;
						printf("\n%s = %s", $$->temp_var, $$->info.opInfo.right->temp_var);
					}
					| DEC unaryExpression {
						$$ = malloc(sizeof(struct ASTNode));
						if($$ == NULL){
							printf("Out of memory\n");
							exit(0);
						}
						$$->token = NODETYPE_OPERATOR;
						$$->info.opInfo.right = $2;
						strcpy($$->info.opInfo.op, "--");
						genTemp();
						strcpy($$->temp_var, temp_var_g);
						$2->intValue = $2->intValue - 1;
						printf("\n%s = %s - 1", $2->temp_var, $2->temp_var);
						$$->intValue = $2->intValue;
						printf("\n%s = %s", $$->temp_var, $$->info.opInfo.right->temp_var);
					}
					| ADD unaryExpression {
						$$ = $2;
					}
					| SUB unaryExpression {
						$$ = malloc(sizeof(struct ASTNode));
						if($$ == NULL){
							printf("Out of memory\n");
							exit(0);
						}
						$$->token = NODETYPE_OPERATOR;
						$$->info.opInfo.right = $2;
						strcpy($$->info.opInfo.op, "minus");
						genTemp();
						strcpy($$->temp_var, temp_var_g);
						$$->intValue = -1 * $2->intValue;
						printf("\n%s = -1 * %s", $$->temp_var, $$->info.opInfo.right->temp_var);
					}
					| NOT unaryExpression {
						$$ = malloc(sizeof(struct ASTNode));
						if($$ == NULL){
							printf("Out of memory\n");
							exit(0);
						}
						$$->token = NODETYPE_OPERATOR;
						$$->info.opInfo.right = $2;
						strcpy($$->info.opInfo.op, "!");
						genTemp();
						strcpy($$->temp_var, temp_var_g);
						$$->intValue = !$2->intValue;
						printf("\n%s = !%s", $$->temp_var, $$->info.opInfo.right->temp_var);
					};

postfixExpression : primaryExpression {
						$$ = $1;
					}
					| postfixExpression INC {
						$$ = malloc(sizeof(struct ASTNode));
						if ($$ == NULL) {
							yyerror("no mem");
						}
						$$->token = NODETYPE_OPERATOR;
						$$->info.opInfo.left = $1;
						$$->intValue = $1->intValue;
						strcpy($$->info.opInfo.op, "++");
						genTemp();
						strcpy($$->temp_var, temp_var_g);
						printf("\n%s = %s", $$->temp_var, $$->info.opInfo.left->temp_var);
						$1->intValue = $1->intValue + 1;
						printf("\n%s = %s + 1", $1->temp_var, $1->temp_var);
					}
					| postfixExpression DEC {
						$$ = malloc(sizeof(struct ASTNode));
						if ($$ == NULL) {
							yyerror("no mem");
						}
						$$->token = NODETYPE_OPERATOR;
						$$->info.opInfo.left = $1;
						strcpy($$->info.opInfo.op, "--");
						$$->intValue = $1->intValue;
						genTemp();
						strcpy($$->temp_var, temp_var_g);
						printf("\n%s = %s", $$->temp_var, $$->info.opInfo.left->temp_var);
						$1->intValue = $1->intValue - 1;
						printf("\n%s = %s - 1", $1->temp_var, $1->temp_var);
					};

primaryExpression : INTEGER {
						$$ = malloc(sizeof(ASTNode));
						if($$ == NULL){
							printf("Out of memory\n");
							exit(0);
						}
						$$->token = NODETYPE_CONSTANT_INT;
						$$->intValue = $1;
						genTemp();
						strcpy($$->temp_var, temp_var_g);
						printf("\n%s = %d", $$->temp_var, $$->intValue);
					} 
					| IDENTIFIER {
						$$ = malloc(sizeof(ASTNode));
						if($$ == NULL){
							printf("Out of memory\n");
							exit(0);
						}
						$$->token = NODETYPE_IDENTIFIER;
						strcpy($$->lexeme, $1);
						genTemp();
						strcpy($$->temp_var, temp_var_g);
						printf("\n%s = %s", $$->temp_var, $$->lexeme);
					}
					| LPAREN assignmentExpression RPAREN {
						$$ = $2;
					};

selectionStatement :	IF LPAREN assignmentExpression RPAREN LBRACE slist RBRACE
						| IF LPAREN assignmentExpression RPAREN LBRACE slist RBRACE ELSE LBRACE slist RBRACE;

iterationStatement : WHILE LPAREN assignmentExpression RPAREN LBRACE slist RBRACE;


%%

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