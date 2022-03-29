#include "funciones.h"
int read_from_csv(FILE* f, char*** names, float** grades) {
  char line[1001];
  int count = 0;
  int count1 = 0;
  float sum = 0;
  float sum_students = 0;
  int count_students = 0;
  char* field;
  fgets(line, 1000, f);
  while (fgets(line, 1000, f) != NULL) {
    count1++;
  }
  rewind(f);
  *names = (char**)malloc(count1 * sizeof(char*));
  *grades = (float*)malloc(count1 * sizeof(float));
  count1 = 0;
  while (fgets(line, 1000, f) != NULL) {
    field = strtok(line, ",");
    (*names)[count1] = (char*)malloc(strlen(field) * sizeof(char));
    strcpy((*names)[count1], field);
    field = strtok(NULL, ",");
    sum = 0.0;
    count = 0;
    while (field != NULL) {
      sum += atof(field);
      count++;
      field = strtok(NULL, ",");
    }
    (*grades)[count1] = sum / count;
    count1++;
  }
  return --count1;
}
void merge(float grades[], char** names, int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;
  float L[n1], R[n2];
  char *Ln[n1], *Rn[n2];

  for (int i = 0; i < n1; i++) {
    L[i] = grades[l + i];
    Ln[i] = names[l + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = grades[m + 1 + j];
    Rn[j] = names[m + 1 + j];
  }

  int i = 0;
  int j = 0;
  int k = l;

  while (i < n1 && j < n2) {
    if (L[i] >= R[j]) {
      grades[k] = L[i];
      names[k] = Ln[i];
      i++;
    } else {
      grades[k] = R[j];
      names[k] = Rn[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    grades[k] = L[i];
    names[k] = Ln[i];
    i++;
    k++;
  }

  while (j < n2) {
    grades[k] = R[j];
    names[k] = Rn[j];
    j++;
    k++;
  }
}

void mergeSort(float grades[], char** names, int l, int r) {
  if (l >= r) {
    return;
  }
  int m = l + (r - l) / 2;
  mergeSort(grades, names, l, m);
  mergeSort(grades, names, m + 1, r);
  merge(grades, names, l, m, r);
}

void print(char** names, float* grades, int n) {
  for (int i = 0; i < n; i++) {
    printf("%s: %.2f\n", names[i], grades[i]);
  }
}