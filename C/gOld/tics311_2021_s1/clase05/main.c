#include <stdio.h>

void swap(int *x, int *y) {
  int t = *x;
  *x = *y;
  *y = t;
}

void print_arreglo(int arreglo[], int numero_elementos) {
  for (int i = 0; i < numero_elementos; i++) {
    printf("%i,", arreglo[i]);
  }
  printf("\n");
}

void bubble_sort(int arreglo[], int numero_elementos) {
  int contador = 0;
  for (int i = 0; i < numero_elementos; i++) {
    for (int j = 1; j < numero_elementos - i; j++) {
      contador++;
      if (arreglo[j - 1] > arreglo[j]) {
        swap(&arreglo[j - 1], &arreglo[j]);
      }
    }
  }
  printf("El valor del contador es: %i\n", contador);
}

int main(int argc, char *argv[]) {
  int arreglo[] = {2,   4,  6545, 3,    234, 4,     57, 567,  3, 5457,
                   567, 86, 435,  3452, 34,  54754, 21, 4656, 7, 56};
  print_arreglo(arreglo, 20);
  bubble_sort(arreglo, 20);
  print_arreglo(arreglo, 20);
}