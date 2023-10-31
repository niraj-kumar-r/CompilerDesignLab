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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE{
	int ival;
	char lexeme[20];
	struct I_Node *node;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
