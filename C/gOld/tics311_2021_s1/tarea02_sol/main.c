#include "funciones.h"

int main(int argc, char* argv[]) {
  FILE* f;
  char** names;
  float* grades;
  int n;
  if (argc != 2) {
    fprintf(stderr,
            "Debe ingresar sólo un argumento, y este debe ser el nombre del "
            "archivo");
    return 1;
  }
  f = fopen(argv[1], "r");
  if (f == NULL) {
    fprintf(stderr, "El archivo no existe");
    return 2;
  }
  n = read_from_csv(f, &names, &grades);
  mergeSort(grades, names, 0, n);
  print(names, grades, n);
  fclose(f);
  return 0;
}