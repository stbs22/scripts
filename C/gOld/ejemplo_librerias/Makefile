NAME = main
LIB = libreria


CC = gcc
CODE = $(NAME).c
OBJ = $(NAME).o
EXE = $(NAME)
ARGV = 

all: $(CODE)
	$(CC) $(CODE) $(LIB).c -o $(EXE)
	./$(EXE) $(ARGV)

$(OBJ): $(CODE)
	$(CC) -c $(CODE) 
clean:
	rm -f *.o $(EXE) *~

