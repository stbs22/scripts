#include "pregunta_4.h"

void editar_nombre(ciudad** tabla, int id_region, int id_comuna,
                   char* nuevo_nombre) {
  ciudad* it = tabla[id_region - 1];

  while (it != NULL) {
    if (it->id_comuna == id_comuna) {
      strcpy(it->comuna, nuevo_nombre);
      break;
    }
    it = it->sgte;
  }
}