#include "pregunta_3.h"
void swap_nombres(char** nombres, int pos1, int pos2) {
  char* tmp;
  tmp = nombres[pos1];
  nombres[pos1] = nombres[pos2];
  nombres[pos2] = tmp;
}