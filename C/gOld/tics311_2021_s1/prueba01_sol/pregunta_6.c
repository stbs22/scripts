#include "pregunta_6.h"

#include <stdlib.h>
void liberar(char** nombres, int* numeros, int numero_elementos) {
  for (int i = 0; i < numero_elementos; i++) {
    free(nombres[i]);
  }
  free(nombres);
  free(numeros);
}