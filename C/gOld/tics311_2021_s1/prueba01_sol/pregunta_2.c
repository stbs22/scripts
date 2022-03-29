#include "pregunta_2.h"

#include <stdio.h>
#include <stdlib.h>
int* leer_archivo_numero(char* filename) {
  int* numbers;
  FILE* f = fopen(filename, "r");
  int lines = 0;
  char word[100];
  while (fgets(word, 100, f) != NULL) {
    lines++;
  }
  rewind(f);
  numbers = (int*)malloc(lines * sizeof(int));
  for (int i = 0; i < lines; i++) {
    fgets(word, 100, f);
    numbers[i] = atoi(word);
  }

  return numbers;
}