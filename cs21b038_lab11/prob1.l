%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
%}

%%
"+"     { return ADD; }
"-"     { return SUB; }
"*"     { return MUL; }
"/"     { return DIV; }
"--"    { return DEC; }
"++"    { return INC; }
"="     { return ASSIGN; }
"("     { return LPAREN; }
")"     { return RPAREN; }
"{"     { return LBRACE; }
"}"     { return RBRACE; }
"["     { return LBRACKET; }
"]"     { return RBRACKET; }
";"     { return SEMICOLON; }
":"     {return COLON;}
","     {return COMMA;}
"if"    { return IF; }
"else"  { return ELSE; }
"while" { return WHILE; }
"switch"    {return SWITCH;}
"case"  {return CASE;}
"break" {return BREAK;}
"continue"  {return CONTINUE;}
"return"    {return RETURN;}
"goto"  {return GOTO;}
"default"   {return DEFAULT;}
"int"   {return INT_TYPE;}
"float" {return FLOAT_TYPE;}
"char"  {return CHAR_TYPE;}
"<"     { return LT; }
">"     { return GT; }
"<="    { return LEQ; }
">="    { return GEQ; }
"=="    { return EQ; }
"!="    { return NEQ; }
"&&"    { return AND; }
"||"    { return OR; }
"!"     { return NOT; }
[a-zA-Z][a-zA-Z0-9]*   { strcpy(yylval.lexeme, yytext) ; return IDENTIFIER; }
[0-9]+  { yylval.intValue = atoi(yytext) ;return INTEGER; }
[ \t\n]+     {};      /* ignore white space */
.           {return yytext[0];}; /* ignore all other characters */
<<EOF>>     { return 0; }

%%