#include "pregunta_2.h"

int cantidad_alumnos(nodo* raiz) {
  if (raiz == NULL) return 0;
  int count = 1 + cantidad_alumnos(raiz->left);
  count += cantidad_alumnos(raiz->right);
  count += cantidad_alumnos(raiz->down);

  return count;
}