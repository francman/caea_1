#Compiler
CC = gcc
CFLAGS = -Wall -ansi -std=c11 -pedantic-errors

monteCarloIntegration: monteCarloIntegration.o
	$(CC) -o monteCarloIntegration monteCarloIntegration.o

monteCarloIntegration.o : monteCarloIntegration.c
	$(CC) $(CFLAGS) -c monteCarloIntegration.c

clean :
	rm monteCarloIntegration *.o *.dat *.png
