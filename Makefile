#Cambiar por nombre de archivo .c
###########################
NAME = test
###########################

#Copiar y pegar en consola para correr archivo destino
######################################################
#
# cd /home/_init_/Escritorio/Scripts/GIT/scripts ; make
#
######################################################

CC = gcc
CODE = $(NAME).c
OBJ = $(NAME).o
EXE = $(NAME)

all: $(CODE)
	$(CC) $(CODE) -o $(EXE)
	./$(EXE)

$(OBJ): $(CODE)
	$(CC) -c $(CODE)

clean:
	rm -f *.o $(EXE) *~