C=gcc
<<<<<<< HEAD
CFLAGS=-I. -ansi -pedantic -Wall -std=c99 -D_XOPEN_SOURCE
ALL_OBJS=setup.o prompt.o parse.o read.o execute.o memmy.o
=======
CFLAGS=-I. -ansi -pedantic -Wall -std=c99
ALL_OBJS=setup.o prompt.o parse.o read.o echo.o execute.o memmy.o
>>>>>>> 1caa3fd6721c42b3151a6dc0b69fc11aef5f522b

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
echo.o: REPL/echo.c
	$(CC) $(CFLAGS) -o echo.o -c ./REPL/echo.c
execute.o: REPL/execute.c REPL/echo.o
	$(CC) $(CFLAGS) -o execute.o -c ./REPL/execute.c
main.o : main.c
	$(CC) $(CFLAGS) -o main.o -c main.c

clean :
	rm -f *.o *.x

tar :
	tar -cvf cloysta.tar *
