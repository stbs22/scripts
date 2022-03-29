all: tarea02

funciones.o: funciones.c
	gcc -c funciones.c

main.o: main.c funciones.h
	gcc -c main.c

tarea02: funciones.o main.o
	gcc main.o funciones.o -o tarea02

clean:
	rm -f *.o
	rm -f tarea02