
#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;
  int L[n1], R[n2];

  for (int i = 0; i < n1; i++) L[i] = arr[l + i];
  for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

  int i = 0;
  int j = 0;
  int k = l;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[], int l, int r) {
  if (l >= r) {
    return;  // returns recursively
  }
  int m = l + (r - l) / 2;
  mergeSort(arr, l, m);
  mergeSort(arr, m + 1, r);
  merge(arr, l, m, r);
}
void print_arreglo(int arreglo[], int numero_elementos) {
  for (int i = 0; i < numero_elementos; i++) {
    printf("%i,", arreglo[i]);
  }
  printf("\n");
}
int main(int argc, char *argv[]) {
  int arreglo[] = {2,   4,  6545, 3,    234, 4,     57, 567,  3, 5457,
                   567, 86, 435,  3452, 34,  54754, 21, 4656, 7, 56};
  print_arreglo(arreglo, 20);
  // bubble_sort(arreglo, 20);
  mergeSort(arreglo, 0, 19);
  print_arreglo(arreglo, 20);
}