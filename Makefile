CC=gcc
CCFLAGS= -Wall -Wextra #-Wpedantic -Wconversion -Wshadow

prog2 : mainListe.o liste.o testListHelpers.o
	$(CC) mainListe.o liste.o testListHelpers.o -o prog2 -lm

mainListe.o : mainListe.c liste.o testListHelpers.o
	$(CC) $(CCFLAGS) -c mainListe.c

liste.o : liste.c liste.h
	$(CC) $(CCFLAGS) -c liste.c

testListHelpers.o : testListHelpers.c testListHelpers.h
	$(CC) $(CCFLAGS) -c testListHelpers.c

clear:
	rm -f mainListe.o liste.o testListHelpers.o prog2