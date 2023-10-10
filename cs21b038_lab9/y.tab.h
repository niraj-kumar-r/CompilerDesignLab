#ifndef _yy_defines_h_
#define _yy_defines_h_

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
#define WHILE 273
#define LT 274
#define GT 275
#define LEQ 276
#define GEQ 277
#define EQ 278
#define NEQ 279
#define AND 280
#define OR 281
#define NOT 282
#define INTEGER 283
#define IDENTIFIER 284
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE{
	int intValue;
	char lexeme[20];
	struct ASTNode *node;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
