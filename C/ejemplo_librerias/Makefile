
##Cambiar por nombre de archivo .c y libreria .c
###########################
NAME = main
LIB = libreria
###########################

#Copiar y pegar en consola para correr archivo destino
######################################################
#
# cd /home/_init_/Documentos/Scripts/GIT/scripts/C/ejemplo_librerias ; make
#
######################################################

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

