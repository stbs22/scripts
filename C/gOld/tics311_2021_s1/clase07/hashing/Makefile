CC = gcc
OBJS = hashing.c

all: $(OBJS)
	$(CC) $(OBJS) -o hashing
	./hashing

hashing.o: hashing.c
	$(CC) -c hashing.c
			
clean:
	rm -f *.o hashing *~

