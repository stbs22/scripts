#include <stdio.h>

#include "funciones.h"
#include "pregunta_1.h"
#include "pregunta_2.h"
#include "pregunta_3.h"
#include "pregunta_4.h"
#include "pregunta_5.h"
#include "pregunta_6.h"
#include "pregunta_7.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "***\nYou must use one parameter!\n***\n");
    return 1;
  }
  char *filename = argv[1];
  int numero_regiones = 16;

  // Preguntas 1 y 2. read_hash utiliza creación de hash y insertar ciudad
  ciudad **tabla = read_hash(filename, numero_regiones);
  print_hash(tabla, numero_regiones);

  // Pregunta 3 Borrar ciiudad
  borrar(tabla, numero_regiones, 16109);
  print_hash(tabla, numero_regiones);

  // Pregunta 4 editar nombre de la ciudad
  editar_nombre(tabla, numero_regiones, 16207, "nuevo nombre");
  print_hash(tabla, numero_regiones);

  // pregunta 5 comuna por region con más casos
  char **comunas = comuna_mas_casos_por_region(tabla, numero_regiones);
  for (int i = 0; i < numero_regiones; i++) {
    printf("%s,", comunas[i]);
  }
  printf("\n");

  // pregunta 6 comuna  con más casos de Chile
  char *comuna = comuna_mas_casos_chile(tabla, numero_regiones);

  printf("%s\n", comuna);

  // pregunta 7 Segunda comuna con más casos de Chile
  char *comuna2 = segunda_comuna_mas_casos_chile(tabla, numero_regiones);

  printf("%s\n", comuna2);

  return 0;
}