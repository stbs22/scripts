#include "pregunta_3.h"
void borrar(ciudad** tabla, int id_region, int id_comuna) {
  ciudad* it = tabla[id_region - 1];

  if (it == NULL) {
    return;
  } else if (it->id_comuna == id_comuna) {
    tabla[id_region - 1] = it->sgte;
    free(it);
  } else {
    ciudad* tmp;
    while (it->sgte != NULL) {
      if (it->sgte->id_comuna == id_comuna) {
        tmp = it->sgte;
        it->sgte = tmp->sgte;
        free(tmp);
        break;
      }
      it = it->sgte;
    }
  }
}