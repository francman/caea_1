#Compiler
CC = gcc
CFLAGS = -Wall -ansi -std=c11 -pedantic-errors

#Directories


histogram : probability.o
	$(CC) -o histogram probability.o

probability.o : probability.c
	$(CC) $(CFLAGS) -c probability.c

clean :
	rm histogram probability.o *.txt
