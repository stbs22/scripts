#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct n {
  char nombre[100];
  int nota;
  struct n* left;
  struct n* right;
  struct n* down;
} nodo;

nodo* nuevo_nodo(char* nombre, int nota);
nodo* insertar_nodo(nodo* raiz, char* nombre, int nota);
nodo* crear_arbol_desde_archivo(char* filename);
void eliminar_arbol(nodo* raiz);

#endif