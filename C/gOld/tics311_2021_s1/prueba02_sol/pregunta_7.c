#include "pregunta_7.h"

#include <stdlib.h>
char* segunda_comuna_mas_casos_chile(ciudad** tabla, int number) {
  ciudad* it = NULL;
  ciudad *ciudad_max = NULL, *ciudad_max2 = NULL;
  int max = 0, max2 = 0;
  char* ciudad;
  if (tabla[0]->casos > tabla[0]->sgte->casos) {
    max = tabla[0]->casos;
    ciudad_max = tabla[0];
    max2 = tabla[0]->sgte->casos;
    ciudad_max2 = tabla[0]->sgte;
  } else {
    max2 = tabla[0]->casos;
    ciudad_max2 = tabla[0];
    max = tabla[0]->sgte->casos;
    ciudad_max = tabla[0]->sgte;
  }
  max = tabla[0]->casos;
  ciudad_max = tabla[0];
  for (int i = 0; i < number; i++) {
    it = tabla[i];
    while (it != NULL) {
      if (max < it->casos) {
        max2 = max;
        ciudad_max2 = ciudad_max;
        max = it->casos;
        ciudad_max = it;
      } else if (max2 < it->casos) {
        max2 = it->casos;
        ciudad_max2 = it;
      }
      it = it->sgte;
    }
  }
  ciudad = (char*)malloc(strlen(ciudad_max2->comuna) * sizeof(char));
  strcpy(ciudad, ciudad_max2->comuna);
  return ciudad;
}