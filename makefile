todo: main.o tabla.o columna.o tupla.o
	g++ -Wall -o main tabla.o columna.o tupla.o main.o
main.o: tabla.o columna.o tupla.o main.c
	g++ -Wall -c main.c
tabla.o: tabla.c tabla.h columna.o
	g++ -Wall -c tabla.c
columna.o: columna.c columna.h tupla.o
	g++ -Wall -c columna.c
tupla.o: tupla.c tupla.h
	g++ -Wall -c tupla.c

clean:
	rm -f *.o
	rm -f main

