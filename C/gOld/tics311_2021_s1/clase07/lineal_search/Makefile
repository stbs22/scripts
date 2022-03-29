CC = gcc
OBJS = main.c

all: $(OBJS)
	$(CC) $(OBJS) -o main
	./main

hashing.o: main.c
	$(CC) -c main.c
			
clean:
	rm -f *.o main *~

