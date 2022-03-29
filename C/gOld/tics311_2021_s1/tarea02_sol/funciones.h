#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int read_from_csv(FILE* f, char*** names, float** grades);
void print(char** names, float* grades, int n);
void merge(float grades[], char** names, int l, int m, int r);
void mergeSort(float grades[], char** names, int l, int r);