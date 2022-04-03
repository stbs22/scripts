
##Cambiar por nombre de archivo .c
###########################
NAME = main
LIB = lib.c
###########################

CC = gcc
CODE = $(NAME).c
OBJ = $(NAME).o
EXE = $(NAME)

#borrar al entregar
FILE = nocollide.csv
#FILE = notas.csv

all: $(CODE)
	$(CC) $(CODE) -o $(EXE) $(LIB)

#borrar al entregar:
	./$(EXE) $(FILE) 

$(OBJ): $(CODE)
	$(CC) -c $(CODE)

clean:
	rm -f *.o $(EXE) *~

