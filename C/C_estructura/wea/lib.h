#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct p {

  int key;

  char nombre[50];

  float promedio;

  struct p* siguiente;

}HashNodo;


typedef struct l {
  HashNodo* head;
} list;


int fhash(char* nombre);

int cont_filas(FILE *archivo);

int cont_col(FILE *archivo);

char** extraer_columna(FILE *archivo, int nfilas, int pos);

float *crea_means(FILE *archivo, int nfilas, int ncolum);

HashNodo* crea_hash(char** nombres, float* promedios, int nfilas);

void argv_excepcion(char **argv);

void display(HashNodo* tabla_hash);