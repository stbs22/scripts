#include "funciones.h"

void print_array_names(char** names, int number) {
  for (int i = 0; i < number; i++) {
    printf("%s,", names[i]);
    fflush(stdout);
  }
  printf("\n");
}

void print_array_numbers(int* numbers, int number) {
  for (int i = 0; i < number; i++) {
    printf("%d,", numbers[i]);
    fflush(stdout);
  }
  printf("\n");
}