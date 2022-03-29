#include "pregunta_1.h"

#include <stdlib.h>

ciudad** crear_tabla_hash(int n) {
  ciudad** tabla = (ciudad**)malloc(n * sizeof(ciudad*));
  for (int i = 0; i < n; i++) {
    tabla[i] = NULL;
  }
  return tabla;
}