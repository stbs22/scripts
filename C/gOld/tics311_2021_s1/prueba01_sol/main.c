#include <stdio.h>

#include "funciones.h"
#if funcion == 1
#include "pregunta_1.h"
#elif funcion == 2
#include "pregunta_2.h"
#elif funcion == 3
#include "pregunta_3.h"
#elif funcion == 4
#include "pregunta_4.h"
#elif funcion == 5
#include "pregunta_5.h"
#elif funcion == 6
#include "pregunta_6.h"
#endif
int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "***\nYou must use two parameters!\n***\n");
    return 1;
  }
  char *filename_names = argv[1];
  char *filename_numbers = argv[2];

  // primera parte: Leer un archivo de texto con un nombre por línea
#if funcion == 1
  char **names = leer_archivo_texto(filename_names);
  print_array_names(names, 50);

#elif funcion == 2
  // segunda parte: Leer un archivo de texto con un número entero por línea
  int *numbers = leer_archivo_numero(filename_numbers);
  print_array_numbers(numbers, 50);

#elif funcion == 3
  // tercera parte: hacer swap en un arreglo de palabras
  char *names[] = {"Danilo", "Sebastian", "Felipe"};
  swap_nombres(names, 1, 2);
  print_array_names(names, 3);

#elif funcion == 4
  // cuarta parte: hacer swap en un arreglo de enteros
  int numbers[] = {1, 5, 7, 6, 8, 43, 2, 4, 65, 8, 4};
  swap_numeros(numbers, 1, 5);
  print_array_numbers(numbers, 11);

#elif funcion == 5
  // quinta parte: ordenar los nombres del primer arreglo en función de los
  // números del segundo arreglo
  int numbers[] = {1, 5, 7, 6, 8, 43, 2, 9, 65, 8, 4};
  char *names[] = {"Danilo", "Sebastian", "Felipe", "ROMINA",
                   "Pedro",  "Valeska",   "Alicia", "Magaly",
                   "Norma",  "Daniel",    "Paula"};
  sort_names(names, numbers, 11);
  print_array_names(names, 11);

#elif funcion == 6
  // sexta parte: liberar memoria
  liberar(names, numbers, 7);
#endif
  return 0;
}