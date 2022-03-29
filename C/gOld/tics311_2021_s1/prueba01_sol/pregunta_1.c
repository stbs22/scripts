#include "pregunta_1.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char** leer_archivo_texto(char* filename) {
  char** names;
  FILE* f = fopen(filename, "r");
  int lines = 0;
  char word[100];
  while (fgets(word, 100, f) != NULL) {
    lines++;
  }
  rewind(f);
  names = (char**)malloc(lines * sizeof(char*));
  for (int i = 0; i < lines; i++) {
    fgets(word, 100, f);
    names[i] = (char*)malloc(strlen(word) * sizeof(char));
    strcpy(names[i], word);
    names[i][strlen(word) - 1] = '\0';
  }

  return names;
}