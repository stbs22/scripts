#include "pregunta_2.h"

void insertar(ciudad** tabla, ciudad* nueva_ciudad) {
  int bucket = nueva_ciudad->id_region - 1;
  if (tabla[bucket] == NULL) {
    tabla[bucket] = nueva_ciudad;
  } else {
    ciudad* it = tabla[bucket];
    while (it->sgte != NULL) {
      it = it->sgte;
    }
    it->sgte = nueva_ciudad;
  }
  nueva_ciudad->sgte = NULL;
}