todo: main.o bd.o
	g++ -Wall -o main bd.o main.o
main.o: bd.o main.c
	g++ -Wall -c main.c
bd.o: bd.c bd.h
	g++ -Wall -c bd.c
clean:
	rm -f *.o
	rm -f main

