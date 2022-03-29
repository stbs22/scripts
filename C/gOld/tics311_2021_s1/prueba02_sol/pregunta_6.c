#include "pregunta_6.h"

#include <stdlib.h>
char* comuna_mas_casos_chile(ciudad** tabla, int number) {
  ciudad* it = NULL;
  ciudad* ciudad_max = NULL;
  char* ciudad;
  int max = 0;
  max = tabla[0]->casos;
  ciudad_max = tabla[0];
  for (int i = 0; i < number; i++) {
    it = tabla[i];
    while (it != NULL) {
      if (max < it->casos) {
        max = it->casos;
        ciudad_max = it;
      }
      it = it->sgte;
    }
  }
  ciudad = (char*)malloc(strlen(ciudad_max->comuna) * sizeof(char));
  strcpy(ciudad, ciudad_max->comuna);
  return ciudad;
}