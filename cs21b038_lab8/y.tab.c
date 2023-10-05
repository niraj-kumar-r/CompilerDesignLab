/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20221106

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#undef YYBTYACC
#define YYBTYACC 0
#define YYDEBUGSTR YYPREFIX "debug"
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "prob1.y"
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

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 31 "prob1.y"
typedef union YYSTYPE{
	int ival;
	char lexeme[20];
	struct I_Node *node;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 64 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define ADD 257
#define SUB 258
#define MUL 259
#define DIV 260
#define INC 261
#define DEC 262
#define ASSIGN 263
#define LPAREN 264
#define RPAREN 265
#define LBRACE 266
#define RBRACE 267
#define LBRACKET 268
#define RBRACKET 269
#define SEMICOLON 270
#define IF 271
#define ELSE 272
#define LT 273
#define GT 274
#define LEQ 275
#define GEQ 276
#define EQ 277
#define NEQ 278
#define AND 279
#define OR 280
#define NOT 281
#define INTEGER 282
#define IDENTIFIER 283
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
   11,    0,   13,    0,    0,   12,   12,    1,    2,    2,
    2,    2,    2,    3,    3,   10,   10,   10,   10,   10,
   10,   10,   10,   10,   10,    4,    4,    4,    5,    5,
    5,    6,    6,    6,    6,    6,    7,    7,    7,    8,
    8,    8,    9,
};
static const YYINT yylen[] = {                            2,
    0,    3,    0,    3,    0,   11,    7,    2,    3,    2,
    2,    2,    2,    1,    3,    1,    3,    3,    3,    3,
    3,    3,    3,    3,    2,    1,    3,    3,    1,    3,
    3,    1,    2,    2,    2,    2,    1,    2,    2,    1,
    1,    3,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,   14,    0,    1,    0,    0,    3,
   12,   13,    0,    0,    0,    8,   10,   11,    0,    0,
   15,    0,    0,   43,   41,    0,   40,    0,    2,    0,
    0,    0,    0,    0,    0,   29,    0,   37,    4,    0,
   25,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   35,   36,   33,   34,    0,    0,    0,    0,   38,   39,
   42,   17,   18,   19,   20,   21,   22,   23,   24,    0,
    0,    0,   30,   31,    0,    0,    0,    0,    0,    6,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  261,  262,  264,  271,  283,  285,  286,  287,  288,  297,
  288,  288,  288,  264,  296,  270,  261,  262,  263,  298,
  265,  264,  281,  282,  283,  293,  294,  295,  285,  257,
  258,  261,  262,  289,  290,  291,  292,  293,  285,  289,
  293,  273,  274,  275,  276,  277,  278,  279,  280,  265,
  291,  291,  291,  291,  257,  258,  259,  260,  261,  262,
  265,  293,  293,  293,  293,  293,  293,  293,  293,  266,
  290,  290,  291,  291,  285,  267,  272,  266,  285,  267,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          6,
    7,    8,    9,   34,   35,   36,   37,   38,   27,   28,
   15,   10,   20,
};
static const YYINT yysindex[] = {                      -217,
 -260, -260, -260, -255,    0,    0,    0, -259, -204,    0,
    0,    0, -235, -256, -217,    0,    0,    0, -240, -217,
    0, -240, -254,    0,    0, -189,    0, -226,    0, -240,
 -240, -240, -240, -251, -164,    0, -242,    0,    0, -186,
    0, -254, -254, -254, -254, -254, -254, -254, -254, -220,
    0,    0,    0,    0, -240, -240, -240, -240,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -217,
 -164, -164,    0,    0, -203, -210, -185, -217, -191,    0,
};
static const YYINT yyrindex[] = {                        78,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    2,    0,    0,    0,    0,    2,
    0,    0,    0,    0,    0, -182,    0,    0,    0,    0,
    0,    0,    0, -173, -205,    0, -209,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -169,
 -190, -188,    0,    0,    0,    1,    0, -169,    0,    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                       -15,
    0,    0,   91,   77,   18,  -17,    0,  -11,    0,    0,
    0,    0,    0,
};
#define YYTABLESIZE 284
static const YYINT yytable[] = {                         29,
    7,    5,   26,    3,   39,   55,   56,   22,   14,   22,
   16,   41,   51,   52,   53,   54,   30,   31,   59,   60,
   32,   33,    5,   22,   23,   24,   25,   24,   25,   21,
   62,   63,   64,   65,   66,   67,   68,   69,   50,   73,
   74,   24,   25,    1,    2,   70,    3,   32,   32,   32,
   32,   26,   26,    4,   75,   32,   17,   18,   19,   26,
   32,   77,   79,   76,   26,    5,   27,   27,   28,   28,
   55,   56,   71,   72,   27,   80,   28,    5,   61,   27,
   78,   28,   16,   42,   43,   44,   45,   46,   47,   48,
   49,   11,   12,   13,   57,   58,    9,    5,   40,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    7,    7,    0,    7,    0,    0,    7,    5,    0,
    0,    7,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    7,
};
static const YYINT yycheck[] = {                         15,
    0,    0,   14,  264,   20,  257,  258,  264,  264,  264,
  270,   23,   30,   31,   32,   33,  257,  258,  261,  262,
  261,  262,  283,  264,  281,  282,  283,  282,  283,  265,
   42,   43,   44,   45,   46,   47,   48,   49,  265,   57,
   58,  282,  283,  261,  262,  266,  264,  257,  258,  259,
  260,  257,  258,  271,   70,  265,  261,  262,  263,  265,
  270,  272,   78,  267,  270,  283,  257,  258,  257,  258,
  257,  258,   55,   56,  265,  267,  265,    0,  265,  270,
  266,  270,  265,  273,  274,  275,  276,  277,  278,  279,
  280,    1,    2,    3,  259,  260,  270,  267,   22,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  261,  262,   -1,  264,   -1,   -1,  267,  267,   -1,
   -1,  271,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  283,
};
#if YYBTYACC
static const YYINT yyctable[] = {                        -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,
};
#endif
#define YYFINAL 6
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 283
#define YYUNDFTOKEN 299
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","ADD","SUB","MUL","DIV","INC",
"DEC","ASSIGN","LPAREN","RPAREN","LBRACE","RBRACE","LBRACKET","RBRACKET",
"SEMICOLON","IF","ELSE","LT","GT","LEQ","GEQ","EQ","NEQ","AND","OR","NOT",
"INTEGER","IDENTIFIER","$accept","prog","slist","assignmentexpression",
"variable","additiveexpression","multiplicativeexpression","unaryexpression",
"postfixexpression","primaryexpression","constant","booleanexpression","$$1",
"selectionstatement","$$2","illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : prog",
"$$1 :",
"prog : slist $$1 prog",
"$$2 :",
"prog : selectionstatement $$2 prog",
"prog :",
"selectionstatement : IF LPAREN booleanexpression RPAREN LBRACE prog RBRACE ELSE LBRACE prog RBRACE",
"selectionstatement : IF LPAREN booleanexpression RPAREN LBRACE prog RBRACE",
"slist : assignmentexpression SEMICOLON",
"assignmentexpression : variable ASSIGN additiveexpression",
"assignmentexpression : variable INC",
"assignmentexpression : variable DEC",
"assignmentexpression : INC variable",
"assignmentexpression : DEC variable",
"variable : IDENTIFIER",
"variable : LPAREN variable RPAREN",
"booleanexpression : primaryexpression",
"booleanexpression : primaryexpression LT primaryexpression",
"booleanexpression : primaryexpression GT primaryexpression",
"booleanexpression : primaryexpression LEQ primaryexpression",
"booleanexpression : primaryexpression GEQ primaryexpression",
"booleanexpression : primaryexpression EQ primaryexpression",
"booleanexpression : primaryexpression NEQ primaryexpression",
"booleanexpression : primaryexpression AND primaryexpression",
"booleanexpression : primaryexpression OR primaryexpression",
"booleanexpression : NOT primaryexpression",
"additiveexpression : multiplicativeexpression",
"additiveexpression : additiveexpression ADD multiplicativeexpression",
"additiveexpression : additiveexpression SUB multiplicativeexpression",
"multiplicativeexpression : unaryexpression",
"multiplicativeexpression : multiplicativeexpression MUL unaryexpression",
"multiplicativeexpression : multiplicativeexpression DIV unaryexpression",
"unaryexpression : postfixexpression",
"unaryexpression : INC unaryexpression",
"unaryexpression : DEC unaryexpression",
"unaryexpression : ADD unaryexpression",
"unaryexpression : SUB unaryexpression",
"postfixexpression : primaryexpression",
"postfixexpression : postfixexpression INC",
"postfixexpression : postfixexpression DEC",
"primaryexpression : constant",
"primaryexpression : IDENTIFIER",
"primaryexpression : LPAREN additiveexpression RPAREN",
"constant : INTEGER",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
YYLTYPE  yyloc; /* position returned by actions */
YYLTYPE  yylloc; /* position from the lexer */
#endif

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(loc, rhs, n) \
do \
{ \
    if (n == 0) \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 0).last_line; \
        (loc).first_column = YYRHSLOC(rhs, 0).last_column; \
        (loc).last_line    = YYRHSLOC(rhs, 0).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, 0).last_column; \
    } \
    else \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 1).first_line; \
        (loc).first_column = YYRHSLOC(rhs, 1).first_column; \
        (loc).last_line    = YYRHSLOC(rhs, n).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, n).last_column; \
    } \
} while (0)
#endif /* YYLLOC_DEFAULT */
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#if YYBTYACC

#ifndef YYLVQUEUEGROWTH
#define YYLVQUEUEGROWTH 32
#endif
#endif /* YYBTYACC */

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#ifndef YYINITSTACKSIZE
#define YYINITSTACKSIZE 200
#endif

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  *p_base;
    YYLTYPE  *p_mark;
#endif
} YYSTACKDATA;
#if YYBTYACC

struct YYParseState_s
{
    struct YYParseState_s *save;    /* Previously saved parser state */
    YYSTACKDATA            yystack; /* saved parser stack */
    int                    state;   /* saved parser state */
    int                    errflag; /* saved error recovery status */
    int                    lexeme;  /* saved index of the conflict lexeme in the lexical queue */
    YYINT                  ctry;    /* saved index in yyctable[] for this conflict */
};
typedef struct YYParseState_s YYParseState;
#endif /* YYBTYACC */
/* variables for the parser stack */
static YYSTACKDATA yystack;
#if YYBTYACC

/* Current parser state */
static YYParseState *yyps = 0;

/* yypath != NULL: do the full parse, starting at *yypath parser state. */
static YYParseState *yypath = 0;

/* Base of the lexical value queue */
static YYSTYPE *yylvals = 0;

/* Current position at lexical value queue */
static YYSTYPE *yylvp = 0;

/* End position of lexical value queue */
static YYSTYPE *yylve = 0;

/* The last allocated position at the lexical value queue */
static YYSTYPE *yylvlim = 0;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
/* Base of the lexical position queue */
static YYLTYPE *yylpsns = 0;

/* Current position at lexical position queue */
static YYLTYPE *yylpp = 0;

/* End position of lexical position queue */
static YYLTYPE *yylpe = 0;

/* The last allocated position at the lexical position queue */
static YYLTYPE *yylplim = 0;
#endif

/* Current position at lexical token queue */
static YYINT  *yylexp = 0;

static YYINT  *yylexemes = 0;
#endif /* YYBTYACC */
#line 433 "prob1.y"

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
#line 578 "y.tab.c"

/* For use in generated program */
#define yydepth (int)(yystack.s_mark - yystack.s_base)
#if YYBTYACC
#define yytrial (yyps->save)
#endif /* YYBTYACC */

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE *newps;
#endif

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    newps = (YYLTYPE *)realloc(data->p_base, newsize * sizeof(*newps));
    if (newps == 0)
        return YYENOMEM;

    data->p_base = newps;
    data->p_mark = newps + i;
#endif

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;

#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%sdebug: stack size increased to %d\n", YYPREFIX, newsize);
#endif
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    free(data->p_base);
#endif
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif /* YYPURE || defined(YY_NO_LEAKS) */
#if YYBTYACC

static YYParseState *
yyNewState(unsigned size)
{
    YYParseState *p = (YYParseState *) malloc(sizeof(YYParseState));
    if (p == NULL) return NULL;

    p->yystack.stacksize = size;
    if (size == 0)
    {
        p->yystack.s_base = NULL;
        p->yystack.l_base = NULL;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        p->yystack.p_base = NULL;
#endif
        return p;
    }
    p->yystack.s_base    = (YYINT *) malloc(size * sizeof(YYINT));
    if (p->yystack.s_base == NULL) return NULL;
    p->yystack.l_base    = (YYSTYPE *) malloc(size * sizeof(YYSTYPE));
    if (p->yystack.l_base == NULL) return NULL;
    memset(p->yystack.l_base, 0, size * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    p->yystack.p_base    = (YYLTYPE *) malloc(size * sizeof(YYLTYPE));
    if (p->yystack.p_base == NULL) return NULL;
    memset(p->yystack.p_base, 0, size * sizeof(YYLTYPE));
#endif

    return p;
}

static void
yyFreeState(YYParseState *p)
{
    yyfreestack(&p->yystack);
    free(p);
}
#endif /* YYBTYACC */

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab
#if YYBTYACC
#define YYVALID        do { if (yyps->save)            goto yyvalid; } while(0)
#define YYVALID_NESTED do { if (yyps->save && \
                                yyps->save->save == 0) goto yyvalid; } while(0)
#endif /* YYBTYACC */

int
YYPARSE_DECL()
{
    int yym, yyn, yystate, yyresult;
#if YYBTYACC
    int yynewerrflag;
    YYParseState *yyerrctx = NULL;
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  yyerror_loc_range[3]; /* position of error start/end (0 unused) */
#endif
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
    if (yydebug)
        fprintf(stderr, "%sdebug[<# of symbols on state stack>]\n", YYPREFIX);
#endif
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    memset(yyerror_loc_range, 0, sizeof(yyerror_loc_range));
#endif

#if YYBTYACC
    yyps = yyNewState(0); if (yyps == 0) goto yyenomem;
    yyps->save = 0;
#endif /* YYBTYACC */
    yym = 0;
    /* yyn is set below */
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base;
#endif
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
#if YYBTYACC
        do {
        if (yylvp < yylve)
        {
            /* we're currently re-reading tokens */
            yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc = *yylpp++;
#endif
            yychar = *yylexp++;
            break;
        }
        if (yyps->save)
        {
            /* in trial mode; save scanner results for future parse attempts */
            if (yylvp == yylvlim)
            {   /* Enlarge lexical value queue */
                size_t p = (size_t) (yylvp - yylvals);
                size_t s = (size_t) (yylvlim - yylvals);

                s += YYLVQUEUEGROWTH;
                if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL) goto yyenomem;
                if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL) goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL) goto yyenomem;
#endif
                yylvp   = yylve = yylvals + p;
                yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp   = yylpe = yylpsns + p;
                yylplim = yylpsns + s;
#endif
                yylexp  = yylexemes + p;
            }
            *yylexp = (YYINT) YYLEX;
            *yylvp++ = yylval;
            yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *yylpp++ = yylloc;
            yylpe++;
#endif
            yychar = *yylexp++;
            break;
        }
        /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
        yychar = YYLEX;
#if YYBTYACC
        } while (0);
#endif /* YYBTYACC */
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, " <%s>", YYSTYPE_TOSTRING(yychar, yylval));
#endif
            fputc('\n', stderr);
        }
#endif
    }
#if YYBTYACC

    /* Do we have a conflict? */
    if (((yyn = yycindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        YYINT ctry;

        if (yypath)
        {
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: CONFLICT in state %d: following successful trial parse\n",
                                YYDEBUGSTR, yydepth, yystate);
#endif
            /* Switch to the next conflict context */
            save = yypath;
            yypath = save->save;
            save->save = NULL;
            ctry = save->ctry;
            if (save->state != yystate) YYABORT;
            yyFreeState(save);

        }
        else
        {

            /* Unresolved conflict - start/continue trial parse */
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
            {
                fprintf(stderr, "%s[%d]: CONFLICT in state %d. ", YYDEBUGSTR, yydepth, yystate);
                if (yyps->save)
                    fputs("ALREADY in conflict, continuing trial parse.\n", stderr);
                else
                    fputs("Starting trial parse.\n", stderr);
            }
#endif
            save                  = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (save == NULL) goto yyenomem;
            save->save            = yyps->save;
            save->state           = yystate;
            save->errflag         = yyerrflag;
            save->yystack.s_mark  = save->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (save->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            save->yystack.l_mark  = save->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (save->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            save->yystack.p_mark  = save->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (save->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            ctry                  = yytable[yyn];
            if (yyctable[ctry] == -1)
            {
#if YYDEBUG
                if (yydebug && yychar >= YYEOF)
                    fprintf(stderr, "%s[%d]: backtracking 1 token\n", YYDEBUGSTR, yydepth);
#endif
                ctry++;
            }
            save->ctry = ctry;
            if (yyps->save == NULL)
            {
                /* If this is a first conflict in the stack, start saving lexemes */
                if (!yylexemes)
                {
                    yylexemes = (YYINT *) malloc((YYLVQUEUEGROWTH) * sizeof(YYINT));
                    if (yylexemes == NULL) goto yyenomem;
                    yylvals   = (YYSTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYSTYPE));
                    if (yylvals == NULL) goto yyenomem;
                    yylvlim   = yylvals + YYLVQUEUEGROWTH;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpsns   = (YYLTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYLTYPE));
                    if (yylpsns == NULL) goto yyenomem;
                    yylplim   = yylpsns + YYLVQUEUEGROWTH;
#endif
                }
                if (yylvp == yylve)
                {
                    yylvp  = yylve = yylvals;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp  = yylpe = yylpsns;
#endif
                    yylexp = yylexemes;
                    if (yychar >= YYEOF)
                    {
                        *yylve++ = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        *yylpe++ = yylloc;
#endif
                        *yylexp  = (YYINT) yychar;
                        yychar   = YYEMPTY;
                    }
                }
            }
            if (yychar >= YYEOF)
            {
                yylvp--;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp--;
#endif
                yylexp--;
                yychar = YYEMPTY;
            }
            save->lexeme = (int) (yylvp - yylvals);
            yyps->save   = save;
        }
        if (yytable[yyn] == ctry)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                                YYDEBUGSTR, yydepth, yystate, yyctable[ctry]);
#endif
            if (yychar < 0)
            {
                yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp++;
#endif
                yylexp++;
            }
            if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                goto yyoverflow;
            yystate = yyctable[ctry];
            *++yystack.s_mark = (YYINT) yystate;
            *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *++yystack.p_mark = yylloc;
#endif
            yychar  = YYEMPTY;
            if (yyerrflag > 0) --yyerrflag;
            goto yyloop;
        }
        else
        {
            yyn = yyctable[ctry];
            goto yyreduce;
        }
    } /* End of code dealing with conflicts */
#endif /* YYBTYACC */
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                            YYDEBUGSTR, yydepth, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yylloc;
#endif
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;
#if YYBTYACC

    yynewerrflag = 1;
    goto yyerrhandler;
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */

yyerrlab:
    /* explicit YYERROR from an action -- pop the rhs of the rule reduced
     * before looking for error recovery */
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif

    yynewerrflag = 0;
yyerrhandler:
    while (yyps->save)
    {
        int ctry;
        YYParseState *save = yyps->save;
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
                            YYDEBUGSTR, yydepth, yystate, yyps->save->state,
                    (int)(yylvp - yylvals - yyps->save->lexeme));
#endif
        /* Memorize most forward-looking error state in case it's really an error. */
        if (yyerrctx == NULL || yyerrctx->lexeme < yylvp - yylvals)
        {
            /* Free old saved error context state */
            if (yyerrctx) yyFreeState(yyerrctx);
            /* Create and fill out new saved error context state */
            yyerrctx                 = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (yyerrctx == NULL) goto yyenomem;
            yyerrctx->save           = yyps->save;
            yyerrctx->state          = yystate;
            yyerrctx->errflag        = yyerrflag;
            yyerrctx->yystack.s_mark = yyerrctx->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (yyerrctx->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yyerrctx->yystack.l_mark = yyerrctx->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (yyerrctx->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yyerrctx->yystack.p_mark = yyerrctx->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (yyerrctx->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yyerrctx->lexeme         = (int) (yylvp - yylvals);
        }
        yylvp          = yylvals   + save->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yylpp          = yylpsns   + save->lexeme;
#endif
        yylexp         = yylexemes + save->lexeme;
        yychar         = YYEMPTY;
        yystack.s_mark = yystack.s_base + (save->yystack.s_mark - save->yystack.s_base);
        memcpy (yystack.s_base, save->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
        yystack.l_mark = yystack.l_base + (save->yystack.l_mark - save->yystack.l_base);
        memcpy (yystack.l_base, save->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yystack.p_mark = yystack.p_base + (save->yystack.p_mark - save->yystack.p_base);
        memcpy (yystack.p_base, save->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
        ctry           = ++save->ctry;
        yystate        = save->state;
        /* We tried shift, try reduce now */
        if ((yyn = yyctable[ctry]) >= 0) goto yyreduce;
        yyps->save     = save->save;
        save->save     = NULL;
        yyFreeState(save);

        /* Nothing left on the stack -- error */
        if (!yyps->save)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%sdebug[%d,trial]: trial parse FAILED, entering ERROR mode\n",
                                YYPREFIX, yydepth);
#endif
            /* Restore state as it was in the most forward-advanced error */
            yylvp          = yylvals   + yyerrctx->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylpp          = yylpsns   + yyerrctx->lexeme;
#endif
            yylexp         = yylexemes + yyerrctx->lexeme;
            yychar         = yylexp[-1];
            yylval         = yylvp[-1];
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc         = yylpp[-1];
#endif
            yystack.s_mark = yystack.s_base + (yyerrctx->yystack.s_mark - yyerrctx->yystack.s_base);
            memcpy (yystack.s_base, yyerrctx->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yystack.l_mark = yystack.l_base + (yyerrctx->yystack.l_mark - yyerrctx->yystack.l_base);
            memcpy (yystack.l_base, yyerrctx->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yystack.p_mark = yystack.p_base + (yyerrctx->yystack.p_mark - yyerrctx->yystack.p_base);
            memcpy (yystack.p_base, yyerrctx->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yystate        = yyerrctx->state;
            yyFreeState(yyerrctx);
            yyerrctx       = NULL;
        }
        yynewerrflag = 1;
    }
    if (yynewerrflag == 0) goto yyinrecovery;
#endif /* YYBTYACC */

    YYERROR_CALL("syntax error");
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yyerror_loc_range[1] = yylloc; /* lookahead position is error start position */
#endif

#if !YYBTYACC
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
#endif
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: state %d, error recovery shifting to state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* lookahead position is error end position */
                yyerror_loc_range[2] = yylloc;
                YYLLOC_DEFAULT(yyloc, yyerror_loc_range, 2); /* position of error span */
                *++yystack.p_mark = yyloc;
#endif
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: error recovery discarding state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* the current TOS position is the error start position */
                yyerror_loc_range[1] = *yystack.p_mark;
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
                if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark, yystack.p_mark);
#else
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
                --yystack.s_mark;
                --yystack.l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                --yystack.p_mark;
#endif
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, error recovery discarding token %d (%s)\n",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
        }
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval, &yylloc);
#else
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
    yym = yylen[yyn];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: state %d, reducing by rule %d (%s)",
                        YYDEBUGSTR, yydepth, yystate, yyn, yyrule[yyn]);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            if (yym > 0)
            {
                int i;
                fputc('<', stderr);
                for (i = yym; i > 0; i--)
                {
                    if (i != yym) fputs(", ", stderr);
                    fputs(YYSTYPE_TOSTRING(yystos[yystack.s_mark[1-i]],
                                           yystack.l_mark[1-i]), stderr);
                }
                fputc('>', stderr);
            }
#endif
        fputc('\n', stderr);
    }
#endif
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)

    /* Perform position reduction */
    memset(&yyloc, 0, sizeof(yyloc));
#if YYBTYACC
    if (!yytrial)
#endif /* YYBTYACC */
    {
        YYLLOC_DEFAULT(yyloc, &yystack.p_mark[-yym], yym);
        /* just in case YYERROR is invoked within the action, save
           the start of the rhs as the error start position */
        yyerror_loc_range[1] = yystack.p_mark[1-yym];
    }
#endif

    switch (yyn)
    {
case 1:
#line 45 "prob1.y"
	{
				printf("\nAccepted slist\n");
			}
#line 1253 "y.tab.c"
break;
case 3:
#line 48 "prob1.y"
	{
			printf("\nAccepted if else statement\n");
		}
#line 1260 "y.tab.c"
break;
case 5:
#line 51 "prob1.y"
	{}
#line 1265 "y.tab.c"
break;
case 9:
#line 58 "prob1.y"
	{
								yyval.node = malloc(sizeof(struct I_Node));
								if (yyval.node == NULL) {
									yyerror("no mem");
								}
								strcpy(yyval.node->lexeme, yystack.l_mark[-2].node->lexeme);
								yyval.node->left = yystack.l_mark[-2].node;
								yyval.node->right = yystack.l_mark[0].node;
								yyval.node->ival = yystack.l_mark[0].node->ival;
								strcpy(yyval.node->token,"ASSIGN");
								strcpy(yyval.node->lexeme, "=");
								strcpy(yyval.node->temp_var, genTemp());
								printf("%s = %s + %s\n", yyval.node->temp_var, yystack.l_mark[-2].node->temp_var, yystack.l_mark[0].node->temp_var);
							}
#line 1283 "y.tab.c"
break;
case 10:
#line 72 "prob1.y"
	{
								yyval.node = malloc(sizeof(struct I_Node));
								if (yyval.node == NULL) {
									yyerror("no mem");
								}
								yyval.node->left = yystack.l_mark[-1].node;
								yyval.node->right = NULL;
								yyval.node->ival = yystack.l_mark[-1].node->ival + 1;
								strcpy(yyval.node->token, "OP");
								strcpy(yyval.node->lexeme, "++");
								strcpy(yyval.node->temp_var, genTemp());
								printf("%s = %s + 1\n", yyval.node->temp_var, yystack.l_mark[-1].node->temp_var);
							}
#line 1300 "y.tab.c"
break;
case 11:
#line 85 "prob1.y"
	{
								yyval.node = malloc(sizeof(struct I_Node));
								if (yyval.node == NULL) {
									yyerror("no mem");
								}
								yyval.node->left = yystack.l_mark[-1].node;
								yyval.node->right = NULL;
								yyval.node->ival = yystack.l_mark[-1].node->ival - 1;
								strcpy(yyval.node->token, "OP");
								strcpy(yyval.node->lexeme, "--");
								strcpy(yyval.node->temp_var, genTemp());
								printf("%s = %s - 1\n", yyval.node->temp_var, yystack.l_mark[-1].node->temp_var);
							}
#line 1317 "y.tab.c"
break;
case 12:
#line 98 "prob1.y"
	{
								yyval.node = malloc(sizeof(struct I_Node));
								if (yyval.node == NULL) {
									yyerror("no mem");
								}
								yyval.node->left = NULL;
								yyval.node->right = yystack.l_mark[0].node;
								yyval.node->ival = yystack.l_mark[0].node->ival + 1;
								strcpy(yyval.node->token, "OP");
								strcpy(yyval.node->lexeme, "++");
								strcpy(yyval.node->temp_var, genTemp());
								printf("%s = %s + 1\n", yyval.node->temp_var, yystack.l_mark[0].node->temp_var);
							}
#line 1334 "y.tab.c"
break;
case 13:
#line 111 "prob1.y"
	{
								yyval.node = malloc(sizeof(struct I_Node));
								if (yyval.node == NULL) {
									yyerror("no mem");
								}
								yyval.node->left = NULL;
								yyval.node->right = yystack.l_mark[0].node;
								yyval.node->ival = yystack.l_mark[0].node->ival - 1;
								strcpy(yyval.node->token, "OP");
								strcpy(yyval.node->lexeme, "--");
								strcpy(yyval.node->temp_var, genTemp());
								printf("%s = %s - 1\n", yyval.node->temp_var, yystack.l_mark[0].node->temp_var);
							}
#line 1351 "y.tab.c"
break;
case 14:
#line 125 "prob1.y"
	{
				yyval.node = malloc(sizeof(struct I_Node));
				if (yyval.node == NULL) {
					yyerror("no mem");
				}
				strcpy(yyval.node->lexeme, yystack.l_mark[0].lexeme);
				strcpy(yyval.node->token,"ID");
				yyval.node->left = NULL;
				yyval.node->right = NULL;
				strcpy(yyval.node->temp_var, genTemp());
				printf("%s = %s\n", yyval.node->temp_var, yyval.node->lexeme);
			}
#line 1367 "y.tab.c"
break;
case 15:
#line 137 "prob1.y"
	{
				yyval.node = yystack.l_mark[-1].node;
			}
#line 1374 "y.tab.c"
break;
case 16:
#line 141 "prob1.y"
	{
							yyval.node = yystack.l_mark[0].node;
						}
#line 1381 "y.tab.c"
break;
case 17:
#line 144 "prob1.y"
	{
							yyval.node = malloc(sizeof(struct I_Node));
							if (yyval.node == NULL) {
								yyerror("no mem");
							}
							yyval.node->left = yystack.l_mark[-2].node;
							yyval.node->right = yystack.l_mark[0].node;
							yyval.node->ival = yystack.l_mark[-2].node->ival < yystack.l_mark[0].node->ival;
							strcpy(yyval.node->token, "OP");
							strcpy(yyval.node->lexeme, "<");
							strcpy(yyval.node->temp_var, genTemp());
							printf("%s = %s < %s\n", yyval.node->temp_var, yystack.l_mark[-2].node->temp_var, yystack.l_mark[0].node->temp_var);
						}
#line 1398 "y.tab.c"
break;
case 18:
#line 157 "prob1.y"
	{
							yyval.node = malloc(sizeof(struct I_Node));
							if (yyval.node == NULL) {
								yyerror("no mem");
							}
							yyval.node->left = yystack.l_mark[-2].node;
							yyval.node->right = yystack.l_mark[0].node;
							yyval.node->ival = yystack.l_mark[-2].node->ival > yystack.l_mark[0].node->ival;
							strcpy(yyval.node->token, "OP");
							strcpy(yyval.node->lexeme, ">");
							strcpy(yyval.node->temp_var, genTemp());
							printf("%s = %s > %s\n", yyval.node->temp_var, yystack.l_mark[-2].node->temp_var, yystack.l_mark[0].node->temp_var);
						}
#line 1415 "y.tab.c"
break;
case 19:
#line 170 "prob1.y"
	{
							yyval.node = malloc(sizeof(struct I_Node));
							if (yyval.node == NULL) {
								yyerror("no mem");
							}
							yyval.node->left = yystack.l_mark[-2].node;
							yyval.node->right = yystack.l_mark[0].node;
							yyval.node->ival = yystack.l_mark[-2].node->ival <= yystack.l_mark[0].node->ival;
							strcpy(yyval.node->token, "OP");
							strcpy(yyval.node->lexeme, "<=");
							strcpy(yyval.node->temp_var, genTemp());
							printf("%s = %s <= %s\n", yyval.node->temp_var, yystack.l_mark[-2].node->temp_var, yystack.l_mark[0].node->temp_var);
						}
#line 1432 "y.tab.c"
break;
case 20:
#line 183 "prob1.y"
	{
							yyval.node = malloc(sizeof(struct I_Node));
							if (yyval.node == NULL) {
								yyerror("no mem");
							}
							yyval.node->left = yystack.l_mark[-2].node;
							yyval.node->right = yystack.l_mark[0].node;
							yyval.node->ival = yystack.l_mark[-2].node->ival >= yystack.l_mark[0].node->ival;
							strcpy(yyval.node->token, "OP");
							strcpy(yyval.node->lexeme, ">=");
							strcpy(yyval.node->temp_var, genTemp());
							printf("%s = %s >= %s\n", yyval.node->temp_var, yystack.l_mark[-2].node->temp_var, yystack.l_mark[0].node->temp_var);
						}
#line 1449 "y.tab.c"
break;
case 21:
#line 196 "prob1.y"
	{
							yyval.node = malloc(sizeof(struct I_Node));
							if (yyval.node == NULL) {
								yyerror("no mem");
							}
							yyval.node->left = yystack.l_mark[-2].node;
							yyval.node->right = yystack.l_mark[0].node;
							yyval.node->ival = yystack.l_mark[-2].node->ival == yystack.l_mark[0].node->ival;
							strcpy(yyval.node->token, "OP");
							strcpy(yyval.node->lexeme, "==");
							strcpy(yyval.node->temp_var, genTemp());
							printf("%s = %s == %s\n", yyval.node->temp_var, yystack.l_mark[-2].node->temp_var, yystack.l_mark[0].node->temp_var);
						}
#line 1466 "y.tab.c"
break;
case 22:
#line 209 "prob1.y"
	{
							yyval.node = malloc(sizeof(struct I_Node));
							if (yyval.node == NULL) {
								yyerror("no mem");
							}
							yyval.node->left = yystack.l_mark[-2].node;
							yyval.node->right = yystack.l_mark[0].node;
							yyval.node->ival = yystack.l_mark[-2].node->ival != yystack.l_mark[0].node->ival;
							strcpy(yyval.node->token, "OP");
							strcpy(yyval.node->lexeme, "!=");
							strcpy(yyval.node->temp_var, genTemp());
							printf("%s = %s != %s\n", yyval.node->temp_var, yystack.l_mark[-2].node->temp_var, yystack.l_mark[0].node->temp_var);
						}
#line 1483 "y.tab.c"
break;
case 23:
#line 222 "prob1.y"
	{
							yyval.node = malloc(sizeof(struct I_Node));
							if (yyval.node == NULL) {
								yyerror("no mem");
							}
							yyval.node->ival = yystack.l_mark[-2].node->ival && yystack.l_mark[0].node->ival;
							yyval.node->left = yystack.l_mark[-2].node;
							yyval.node->right = yystack.l_mark[0].node;
							strcpy(yyval.node->token, "OP");
							strcpy(yyval.node->lexeme, "&&");
							strcpy(yyval.node->temp_var, genTemp());
							printf("%s = %s && %s\n", yyval.node->temp_var, yystack.l_mark[-2].node->temp_var, yystack.l_mark[0].node->temp_var);
						}
#line 1500 "y.tab.c"
break;
case 24:
#line 235 "prob1.y"
	{
							yyval.node = malloc(sizeof(struct I_Node));
							if (yyval.node == NULL) {
								yyerror("no mem");
							}
							yyval.node->ival = yystack.l_mark[-2].node->ival || yystack.l_mark[0].node->ival;
							yyval.node->left = yystack.l_mark[-2].node;
							yyval.node->right = yystack.l_mark[0].node;
							strcpy(yyval.node->token, "OP");
							strcpy(yyval.node->lexeme, "||");
							strcpy(yyval.node->temp_var, genTemp());
							printf("%s = %s || %s\n", yyval.node->temp_var, yystack.l_mark[-2].node->temp_var, yystack.l_mark[0].node->temp_var);

						}
#line 1518 "y.tab.c"
break;
case 25:
#line 249 "prob1.y"
	{
							yyval.node = malloc(sizeof(struct I_Node));
							if (yyval.node == NULL) {
								yyerror("no mem");
							}
							yyval.node->ival = !yystack.l_mark[0].node->ival;
							yyval.node->left = NULL;
							yyval.node->right = yystack.l_mark[0].node;
							strcpy(yyval.node->token, "OP");
							strcpy(yyval.node->lexeme, "!");
							strcpy(yyval.node->temp_var, genTemp());
							printf("%s = !%s\n", yyval.node->temp_var, yystack.l_mark[0].node->temp_var);
						}
#line 1535 "y.tab.c"
break;
case 26:
#line 263 "prob1.y"
	{
							yyval.node = yystack.l_mark[0].node;
						}
#line 1542 "y.tab.c"
break;
case 27:
#line 266 "prob1.y"
	{
							yyval.node = malloc(sizeof(struct I_Node));
							if (yyval.node == NULL) {
								yyerror("no mem");
							}
							yyval.node->left = yystack.l_mark[-2].node;
							yyval.node->right = yystack.l_mark[0].node;
							yyval.node->ival = yystack.l_mark[-2].node->ival + yystack.l_mark[0].node->ival;
							strcpy(yyval.node->token, "OP");
							strcpy(yyval.node->lexeme, "+");
							strcpy(yyval.node->temp_var, genTemp());
							printf("%s = %s + %s\n", yyval.node->temp_var, yystack.l_mark[-2].node->temp_var, yystack.l_mark[0].node->temp_var);
						}
#line 1559 "y.tab.c"
break;
case 28:
#line 279 "prob1.y"
	{
							yyval.node = malloc(sizeof(struct I_Node));
							if (yyval.node == NULL) {
								yyerror("no mem");
							}
							yyval.node->left = yystack.l_mark[-2].node;
							yyval.node->right = yystack.l_mark[0].node;
							yyval.node->ival = yystack.l_mark[-2].node->ival - yystack.l_mark[0].node->ival;
							strcpy(yyval.node->token, "OP");
							strcpy(yyval.node->lexeme, "-");
							strcpy(yyval.node->temp_var, genTemp());
							printf("%s = %s - %s\n", yyval.node->temp_var, yystack.l_mark[-2].node->temp_var, yystack.l_mark[0].node->temp_var);
						}
#line 1576 "y.tab.c"
break;
case 29:
#line 293 "prob1.y"
	{
								yyval.node = yystack.l_mark[0].node;
							}
#line 1583 "y.tab.c"
break;
case 30:
#line 296 "prob1.y"
	{
								yyval.node = malloc(sizeof(struct I_Node));
								if (yyval.node == NULL) {
									yyerror("no mem");
								}
								yyval.node->left = yystack.l_mark[-2].node;
								yyval.node->right = yystack.l_mark[0].node;
								yyval.node->ival = yystack.l_mark[-2].node->ival * yystack.l_mark[0].node->ival;
								strcpy(yyval.node->token, "OP");
								strcpy(yyval.node->lexeme, "*");
								strcpy(yyval.node->temp_var, genTemp());
								printf("%s = %s * %s\n", yyval.node->temp_var, yystack.l_mark[-2].node->temp_var, yystack.l_mark[0].node->temp_var);
							}
#line 1600 "y.tab.c"
break;
case 31:
#line 309 "prob1.y"
	{
								yyval.node = malloc(sizeof(struct I_Node));
								if (yyval.node == NULL) {
									yyerror("no mem");
								}
								yyval.node->left = yystack.l_mark[-2].node;
								yyval.node->right = yystack.l_mark[0].node;
								yyval.node->ival = yystack.l_mark[-2].node->ival / yystack.l_mark[0].node->ival;
								strcpy(yyval.node->token, "OP");
								strcpy(yyval.node->lexeme, "/");
								strcpy(yyval.node->temp_var, genTemp());
								printf("%s = %s / %s\n", yyval.node->temp_var, yystack.l_mark[-2].node->temp_var, yystack.l_mark[0].node->temp_var);
							}
#line 1617 "y.tab.c"
break;
case 32:
#line 323 "prob1.y"
	{
						yyval.node = yystack.l_mark[0].node;
					}
#line 1624 "y.tab.c"
break;
case 33:
#line 326 "prob1.y"
	{
						yyval.node = malloc(sizeof(struct I_Node));
						if (yyval.node == NULL) {
							yyerror("no mem");
						}
						yyval.node->left = NULL;
						yyval.node->right = yystack.l_mark[0].node;
						yyval.node->ival = yystack.l_mark[0].node->ival + 1;
						strcpy(yyval.node->token, "OP");
						strcpy(yyval.node->lexeme, "++");
						strcpy(yyval.node->temp_var, genTemp());
						printf("%s = %s + 1\n", yyval.node->temp_var, yystack.l_mark[0].node->temp_var);
					}
#line 1641 "y.tab.c"
break;
case 34:
#line 339 "prob1.y"
	{
						yyval.node = malloc(sizeof(struct I_Node));
						if (yyval.node == NULL) {
							yyerror("no mem");
						}
						yyval.node->left = NULL;
						yyval.node->right = yystack.l_mark[0].node;
						yyval.node->ival = yystack.l_mark[0].node->ival - 1;
						strcpy(yyval.node->token, "OP");
						strcpy(yyval.node->lexeme, "--");
						strcpy(yyval.node->temp_var, genTemp());
						printf("%s = %s - 1\n", yyval.node->temp_var, yystack.l_mark[0].node->temp_var);
					}
#line 1658 "y.tab.c"
break;
case 35:
#line 352 "prob1.y"
	{
						yyval.node = yystack.l_mark[0].node;
					}
#line 1665 "y.tab.c"
break;
case 36:
#line 355 "prob1.y"
	{
						yyval.node = malloc(sizeof(struct I_Node));
						if (yyval.node == NULL) {
							yyerror("no mem");
						}
						yyval.node->left = yystack.l_mark[0].node;
						yyval.node->right = NULL;
						yyval.node->ival = -1 * yystack.l_mark[0].node->ival;
						strcpy(yyval.node->token, "OP");
						strcpy(yyval.node->lexeme, "negative");
						strcpy(yyval.node->temp_var, genTemp());
						printf("%s = -1 * %s\n", yyval.node->temp_var, yystack.l_mark[0].node->temp_var);
					}
#line 1682 "y.tab.c"
break;
case 37:
#line 369 "prob1.y"
	{
							yyval.node = yystack.l_mark[0].node;
						}
#line 1689 "y.tab.c"
break;
case 38:
#line 372 "prob1.y"
	{
							yyval.node = malloc(sizeof(struct I_Node));
							if (yyval.node == NULL) {
								yyerror("no mem");
							}
							yyval.node->left = yystack.l_mark[-1].node;
							yyval.node->right = NULL;
							yyval.node->ival = yystack.l_mark[-1].node->ival + 1;
							strcpy(yyval.node->token, "OP");
							strcpy(yyval.node->lexeme, "++");
							strcpy(yyval.node->temp_var, genTemp());
							printf("%s = %s + 1\n", yyval.node->temp_var, yystack.l_mark[-1].node->temp_var);
						}
#line 1706 "y.tab.c"
break;
case 39:
#line 385 "prob1.y"
	{
							yyval.node = malloc(sizeof(struct I_Node));
							if (yyval.node == NULL) {
								yyerror("no mem");
							}
							yyval.node->left = yystack.l_mark[-1].node;
							yyval.node->right = NULL;
							yyval.node->ival = yystack.l_mark[-1].node->ival - 1;
							strcpy(yyval.node->token, "OP");
							strcpy(yyval.node->lexeme, "--");
							strcpy(yyval.node->temp_var, genTemp());
							printf("%s = %s - 1\n", yyval.node->temp_var, yystack.l_mark[-1].node->temp_var);
						}
#line 1723 "y.tab.c"
break;
case 40:
#line 399 "prob1.y"
	{
							yyval.node = yystack.l_mark[0].node;
						}
#line 1730 "y.tab.c"
break;
case 41:
#line 402 "prob1.y"
	{
							yyval.node = malloc(sizeof(struct I_Node));
							if (yyval.node == NULL) {
								yyerror("no mem");
							}
							strcpy(yyval.node->lexeme, yystack.l_mark[0].lexeme);
							yyval.node->left = NULL;
							yyval.node->right = NULL;
							strcpy(yyval.node->token, "ID");
							strcpy(yyval.node->temp_var, genTemp());
							printf("%s = %s\n", yyval.node->temp_var, yyval.node->lexeme);
					}
#line 1746 "y.tab.c"
break;
case 42:
#line 414 "prob1.y"
	{
							yyval.node = yystack.l_mark[-1].node;
					}
#line 1753 "y.tab.c"
break;
case 43:
#line 418 "prob1.y"
	{
				yyval.node = malloc(sizeof(struct I_Node));
				if (yyval.node == NULL) {
					yyerror("no mem");
				}
				yyval.node->ival = yystack.l_mark[0].ival;
				yyval.node->left = NULL;
				yyval.node->right = NULL;
				strcpy(yyval.node->token, "CONST");
				strcpy(yyval.node->lexeme, "INT");
				strcpy(yyval.node->temp_var, genTemp());
				printf("%s = %i\n", yyval.node->temp_var, yyval.node->ival);
			}
#line 1770 "y.tab.c"
break;
#line 1772 "y.tab.c"
    default:
        break;
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
        {
            fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[YYFINAL], yyval));
#endif
            fprintf(stderr, "shifting from state 0 to final state %d\n", YYFINAL);
        }
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yyloc;
#endif
        if (yychar < 0)
        {
#if YYBTYACC
            do {
            if (yylvp < yylve)
            {
                /* we're currently re-reading tokens */
                yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylloc = *yylpp++;
#endif
                yychar = *yylexp++;
                break;
            }
            if (yyps->save)
            {
                /* in trial mode; save scanner results for future parse attempts */
                if (yylvp == yylvlim)
                {   /* Enlarge lexical value queue */
                    size_t p = (size_t) (yylvp - yylvals);
                    size_t s = (size_t) (yylvlim - yylvals);

                    s += YYLVQUEUEGROWTH;
                    if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL)
                        goto yyenomem;
                    if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)
                        goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)
                        goto yyenomem;
#endif
                    yylvp   = yylve = yylvals + p;
                    yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp   = yylpe = yylpsns + p;
                    yylplim = yylpsns + s;
#endif
                    yylexp  = yylexemes + p;
                }
                *yylexp = (YYINT) YYLEX;
                *yylvp++ = yylval;
                yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                *yylpp++ = yylloc;
                yylpe++;
#endif
                yychar = *yylexp++;
                break;
            }
            /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
            yychar = YYLEX;
#if YYBTYACC
            } while (0);
#endif /* YYBTYACC */
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)\n",
                                YYDEBUGSTR, yydepth, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[yystate], yyval));
#endif
        fprintf(stderr, "shifting from state %d to state %d\n", *yystack.s_mark, yystate);
    }
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    *++yystack.p_mark = yyloc;
#endif
    goto yyloop;
#if YYBTYACC

    /* Reduction declares that this path is valid. Set yypath and do a full parse */
yyvalid:
    if (yypath) YYABORT;
    while (yyps->save)
    {
        YYParseState *save = yyps->save;
        yyps->save = save->save;
        save->save = yypath;
        yypath = save;
    }
#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%s[%d]: state %d, CONFLICT trial successful, backtracking to state %d, %d tokens\n",
                        YYDEBUGSTR, yydepth, yystate, yypath->state, (int)(yylvp - yylvals - yypath->lexeme));
#endif
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    yylvp          = yylvals + yypath->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yylpp          = yylpsns + yypath->lexeme;
#endif
    yylexp         = yylexemes + yypath->lexeme;
    yychar         = YYEMPTY;
    yystack.s_mark = yystack.s_base + (yypath->yystack.s_mark - yypath->yystack.s_base);
    memcpy (yystack.s_base, yypath->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
    yystack.l_mark = yystack.l_base + (yypath->yystack.l_mark - yypath->yystack.l_base);
    memcpy (yystack.l_base, yypath->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base + (yypath->yystack.p_mark - yypath->yystack.p_base);
    memcpy (yystack.p_base, yypath->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
    yystate        = yypath->state;
    goto yyloop;
#endif /* YYBTYACC */

yyoverflow:
    YYERROR_CALL("yacc stack overflow");
#if YYBTYACC
    goto yyabort_nomem;
yyenomem:
    YYERROR_CALL("memory exhausted");
yyabort_nomem:
#endif /* YYBTYACC */
    yyresult = 2;
    goto yyreturn;

yyabort:
    yyresult = 1;
    goto yyreturn;

yyaccept:
#if YYBTYACC
    if (yyps->save) goto yyvalid;
#endif /* YYBTYACC */
    yyresult = 0;

yyreturn:
#if defined(YYDESTRUCT_CALL)
    if (yychar != YYEOF && yychar != YYEMPTY)
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval, &yylloc);
#else
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */

    {
        YYSTYPE *pv;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYLTYPE *pp;

        for (pv = yystack.l_base, pp = yystack.p_base; pv <= yystack.l_mark; ++pv, ++pp)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv, pp);
#else
        for (pv = yystack.l_base; pv <= yystack.l_mark; ++pv)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
    }
#endif /* defined(YYDESTRUCT_CALL) */

#if YYBTYACC
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    while (yyps)
    {
        YYParseState *save = yyps;
        yyps = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
    while (yypath)
    {
        YYParseState *save = yypath;
        yypath = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
#endif /* YYBTYACC */
    yyfreestack(&yystack);
    return (yyresult);
}
