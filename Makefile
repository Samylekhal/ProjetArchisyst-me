CC=gcc
CFLAGS=-Wall -Wextra -std=c99

all: projet 

projet: projet.o
	$(CC) -o projet projet.o 

projet.o: projet.c 
	$(CC) -c $(CFLAGS) projet.c


clean:
	rm -f projet