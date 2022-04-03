NAME = main
LIB = lib.c
CC = gcc

CODE = $(NAME).c
OBJ = $(NAME).o
EXE = tarea3

all: $(CODE)
	$(CC) $(CODE) -o $(EXE) $(LIB)

$(OBJ): $(CODE)
	$(CC) -c $(CODE)

clean:
	rm -f *.o $(EXE) *~