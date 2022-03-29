#include "pregunta_5.h"
char** comuna_mas_casos_por_region(ciudad** tabla, int number) {
  ciudad* it = NULL;
  ciudad* ciudad_max = NULL;
  char** ciudades = (char**)malloc(number * sizeof(char*));
  int max = 0;
  for (int i = 0; i < number; i++) {
    it = tabla[i];
    max = it->casos;
    ciudad_max = it;
    while (it != NULL) {
      if (max < it->casos) {
        max = it->casos;
        ciudad_max = it;
      }
      it = it->sgte;
    }
    ciudades[i] = (char*)malloc(strlen(ciudad_max->comuna) * sizeof(char));
    strcpy(ciudades[i], ciudad_max->comuna);
  }
  return ciudades;
}