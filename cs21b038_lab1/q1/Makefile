CFLAGS=-g -DDEBUG
CC=gcc

all:mylexer

mylexer: lex.yy.c 
	$(CC) $(CFLAGS) lex.yy.c -o mylexer

lex.yy.c:ip.l
	flex ip.l

clean: 
	rm -f *.o lex.yy.c
