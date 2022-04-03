#include <stdio.h>

#include "funciones.h"
#include "pregunta_1.h"
#include "pregunta_2.h"
#include "pregunta_3.h"
#include "pregunta_4.h"
#include "pregunta_5.h"
#include "pregunta_6.h"

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "***\nYou must use two parameters!\n***\n");
    return 1;
  }
  char *filename_names = argv[1];
  char *filename_numbers = argv[2];

  // primera parte: Leer un archivo de texto con un nombre por línea
  char **names = leer_archivo_texto(filename_names);
  print_array_names(names, 7);

  // segunda parte: Leer un archivo de texto con un número entero por línea
  int *numbers = leer_archivo_numero(filename_numbers);
  print_array_numbers(numbers, 7);

  // tercera parte: hacer swap en un arreglo de palabras
  swap_nombres(names, 1, 5);
  print_array_names(names, 7);

  // cuarta parte: hacer swap en un arreglo de enteros
  swap_numeros(numbers, 1, 5);
  print_array_numbers(numbers, 7);

  // quinta parte: ordenar los nombres del primer arreglo en función de los
  // números del segundo arreglo
  sort_names(names, numbers, 7);
  print_array_names(names, 7);
  print_array_numbers(numbers, 7);

  // sexta parte: liberar memoria
  liberar(names, numbers, 7);
  return 0;
}