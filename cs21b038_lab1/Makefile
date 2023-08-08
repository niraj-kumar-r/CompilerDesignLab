CFLAGS=-g -DDEBUG
LINKERFLAG=-lfl
CC=gcc

all:lexer

lexer: lex.yy.c 
	$(CC) $(CFLAGS) lex.yy.c -o lexer $(LINKERFLAG)

lex.yy.c: $(FILE)
	flex $(FILE)

clean: 
	rm -f *.o lex.yy.c
