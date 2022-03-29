#include "tree.h"

nodo* nuevo_nodo(char* nombre, int nota) {
  nodo* n = (nodo*)malloc(sizeof(nodo));
  strcpy(n->nombre, nombre);
  n->nota = nota;
  n->left = NULL;
  n->right = NULL;
  n->down = NULL;
  return n;
}

nodo* insertar_nodo(nodo* raiz, char* nombre, int nota) {
  if (raiz == NULL)
    return nuevo_nodo(nombre, nota);
  else if (nota == raiz->nota)
    raiz->down = insertar_nodo(raiz->down, nombre, nota);
  else if (nota > raiz->nota)
    raiz->right = insertar_nodo(raiz->right, nombre, nota);
  else
    raiz->left = insertar_nodo(raiz->left, nombre, nota);
}

nodo* crear_arbol_desde_archivo(char* filename) {
  FILE* f;
  char line[1024];
  char *token, *nombre;
  nodo* raiz = NULL;
  int nota;

  int** m;
  f = fopen(filename, "r");

  fgets(line, 1023, f);
  while (fgets(line, 1023, f) != NULL) {
    token = strtok(line, ",");
    nombre = token;
    token = strtok(NULL, "\t");
    nota = atoi(token);
    raiz = insertar_nodo(raiz, nombre, nota);
  }

  return raiz;
}

void eliminar_arbol(nodo* raiz) {
  if (raiz == NULL) return;
  if (raiz->left != NULL) eliminar_arbol(raiz->left);
  if (raiz->right != NULL) eliminar_arbol(raiz->right);
  if (raiz->down != NULL) eliminar_arbol(raiz->down);
  free(raiz);
}