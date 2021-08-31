# Makefile
VERSION=1
CC     = gcc
CFLAGS = -c -O2

all: main.o
	@echo linking application
	$(CC) -o main main.o avld.o

main.o: main.c avld.o
	$(CC) $(CFLAGS) main.c -o main.o

avld.o: avld.h avld.c
	@echo compiling application
	$(CC) $(CFLAGS) avld.c -o avld.o

clean:
	@echo clean all
	rm -f *.o main
