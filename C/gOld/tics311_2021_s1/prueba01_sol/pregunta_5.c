#include "pregunta_5.h"

void sort_names(char** nombres, int* numeros, int numero_elementos) {
  for (int i = 0; i < numero_elementos; i++) {
    for (int j = 0; j < numero_elementos - 1; j++) {
      if (numeros[j] > numeros[j + 1]) {
        swap_nombres(nombres, j, j + 1);
        swap_numeros(numeros, j, j + 1);
      }
    }
  }
}