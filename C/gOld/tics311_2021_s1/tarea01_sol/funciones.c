#include "funciones.h"
void print_avg_from_csv(FILE* f) {
  char line[1001];
  float sum = 0;
  float sum_students = 0;
  int count = 0;
  int count_students = 0;
  char* field;
  fgets(line, 1000, f);
  while (fgets(line, 1000, f) != NULL) {
    field = strtok(line, ",");
    printf("%s: ", field);
    field = strtok(NULL, ",");
    sum = 0.0;
    count = 0;
    while (field != NULL) {
      sum += atof(field);
      count++;
      field = strtok(NULL, ",");
    }
    printf("%f\n", sum / count);
    count_students++;
    sum_students += sum / count;
  }
  printf("---\nPromedio: %f\n", sum_students / count_students);
}