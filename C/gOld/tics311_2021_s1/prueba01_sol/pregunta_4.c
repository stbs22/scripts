#include "pregunta_4.h"

void swap_numeros(int* numeros, int pos1, int pos2) {
  int tmp;
  tmp = numeros[pos1];
  numeros[pos1] = numeros[pos2];
  numeros[pos2] = tmp;
}