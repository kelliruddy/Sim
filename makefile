CC = gcc -pthread
DEBUG = -g
CFLAGS = -Wall -std=c99 -c $(DEBUG)
LFLAGS = -Wall -std=c99 $(DEBUG)

sim03 : mainprog.o parMethods.o PCB.o scheduler.o
	$(CC) $(LFLAGS) mainprog.o parMethods.o PCB.o scheduler.o -o sim03

mainprog.o : mainprog.c mainprog.h parMethods.h scheduler.h PCB.h
	$(CC) $(CFLAGS) mainprog.c

parMethods.o : parMethods.c parMethods.h
	$(CC) $(CFLAGS) parMethods.c

PCB.o: PCB.h PCB.c parMethods.h parMethods.c
	$(CC) $(CFLAGS) PCB.c

scheduler.o: scheduler.c scheduler.h PCB.h PCB.c parMethods.h parMethods.c
	$(CC) $(CFLAGS) scheduler.c

clean:
	\rm *.o sim01

