C=gcc
CFLAGS=-I. -ansi -pedantic -Wall -std=c99 -D_XOPEN_SOURCE
ALL_OBJS=setup.o prompt.o parse.o read.o execute.o memmy.o

.PHONY : compile clean run tar
compile : cloysta

cloysta : main.o $(ALL_OBJS)
	$(CC) $(CFLAGS) main.o $(ALL_OBJS) -o cloysta
	rm -f *.o

memmy.o : UTILS/memmy.*
	$(CC) $(CFLAGS) -o memmy.o -c ./UTILS/memmy.c
util.o : UTILS/util.c
	$(CC) $(CFLAGS) -o util.o -c ./UTILS/util.c
setup.o: REPL/setup.c
	$(CC) $(CFLAGS) -o setup.o -c ./REPL/setup.c	
prompt.o: REPL/prompt.c
	$(CC) $(CFLAGS) -o prompt.o -c ./REPL/prompt.c	
parse.o: REPL/parse.c
	$(CC) $(CFLAGS) -o parse.o -c ./REPL/parse.c	
read.o: REPL/read.c
	$(CC) $(CFLAGS) -o read.o -c ./REPL/read.c	
execute.o: REPL/execute.c
	$(CC) $(CFLAGS) -o execute.o -c ./REPL/execute.c	
main.o : main.c
	$(CC) $(CFLAGS) -o main.o -c main.c

clean :
	rm -f *.o *.x

tar :
	tar -cvf cloysta.tar *
