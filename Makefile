CC=gcc
CCFLAGS= -Wall -Wextra #-Wpedantic -Wconversion -Wshadow

prog1 : mainListe.o liste.o testListHelpers.o 
	$(CC) mainListe.o liste.o testListHelpers.o -o prog1 -lm

mainListe.o : mainListe.c liste.o testListHelpers.o
	$(CC) $(CCFLAGS) -c mainListe.c

liste.o : liste.c liste.h
	$(CC) $(CCFLAGS) -c liste.c

testListHelpers.o : testListHelpers.c testListHelpers.h
	$(CC) $(CCFLAGS) -c testListHelpers.c





prog2 : mainStrhash.o  strhash.o liste.o testListHelpers.o 
	$(CC) mainStrhash.o  strhash.o liste.o testListHelpers.o -o prog2 -lm

mainStrhash.o : mainStrhash.c strhash.o liste.o testListHelpers.o
	$(CC) $(CCFLAGS) -c mainStrhash.c

strhash.o : strhash.c strhash.h
	$(CC) $(CCFLAGS) -c strhash.c

clear:
	rm -f mainListe.o liste.o testListHelpers.o mainStrhash.o strhash.o prog1 prog2