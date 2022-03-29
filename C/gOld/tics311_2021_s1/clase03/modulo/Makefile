all: salida

push.o:
	gcc -c push.c

main.o: 
	gcc -c main.c

salida: main.o push.o
	gcc main.o push.o -o salida

clean:
	rm -f *.o
	rm -f salida