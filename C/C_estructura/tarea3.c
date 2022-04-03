#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 26

// ESTRUCTURA DE DATOS Y ALGORITMOS
// TICS311 Seccion_01 2021

// Andres Guevara
// Esteban Hernández
// Mátias Hermosilla

typedef struct p {
  char *nombre;
  float promedio;
  struct p *siguiente;
} mone;

mone *tabla[SIZE];
mone *head[SIZE];

// Hash apellido en ascii
int hash(char nombre[]) {
  for (int i = 0;; i++) {
    // devolver caracter luego del primer espacio menos 65 para ir de 0 a 25
    if ((int)nombre[i] == 32) return ((int)nombre[i + 1] - 65);
  }
  return 0;
}

// Incertar cada alumno a su bucket
void incert(char *nom, float prom) {
  mone *alumno;

  int index = hash(nom);
  // printf("%i\n", index);

  if (tabla[index] == NULL) {
    alumno = malloc(sizeof(mone));
    alumno->nombre = nom;
    alumno->promedio = prom;
    alumno->siguiente = NULL;
    tabla[index] = alumno;
    head[index] = tabla[index];
  } else {
    alumno = tabla[index];
    alumno->siguiente = malloc(sizeof(mone));
    alumno = alumno->siguiente;
    alumno->nombre = nom;
    alumno->promedio = prom;
    alumno->siguiente = NULL;
    tabla[index] = tabla[index]->siguiente;
  }
}

// Ordenar de mayor a menor un arrreglo consecutivamente con otro arreglo
// utilizando MergeSort
void TICSmerge(float arr[], int arr2[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;
  float L[n1], R[n2];
  int L2[n1], R2[n2];
  for (int i = 0; i < n1; i++) {
    L[i] = arr[l + i];
    L2[i] = arr2[l + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = arr[m + 1 + j];
    R2[j] = arr2[m + 1 + j];
  }
  int i = 0;
  int j = 0;
  int k = l;

  while (i < n1 && j < n2) {
    if (L[i] >= R[j]) {  //// inversion de mayor a menor
      arr[k] = L[i];
      arr2[k] = L2[i];
      i++;
    } else {
      arr[k] = R[j];
      arr2[k] = R2[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    arr2[k] = L2[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = R[j];
    arr2[k] = R2[j];
    j++;
    k++;
  }
}

void TICSmergeSort(float arr[], int arr2[], int l, int r) {
  if (l >= r) {
    return;
  }
  int m = l + (r - l) / 2;
  TICSmergeSort(arr, arr2, l, m);
  TICSmergeSort(arr, arr2, m + 1, r);
  TICSmerge(arr, arr2, l, m, r);
}

// Contar la cantidad de filas de 0 al total
int cont_filas(FILE *archivo) {
  int n_f = 0;
  char fila[300];
  while (fgets(fila, 300, archivo)) {
    char *temp;
    temp = strtok(fila, "\n");
    n_f++;
  }
  rewind(archivo);
  return n_f - 1;
}

// Devuelve un arreglo con todos los nombres de un directorio
char **nmbres(char dir[]) {
  char file[300];
  char **nombre;
  int v = 0, i = 1;
  FILE *archivo = fopen(dir, "r");
  int nf = -1;
  char fila[300];
  while (fgets(fila, 300, archivo)) {
    char *temp2;
    temp2 = strtok(fila, "\n");
    nf++;
  }
  rewind(archivo);

  nombre = (char **)malloc(nf * sizeof(char *));

  while (fgets(file, 300, archivo)) {
    char *temp;
    temp = strtok(file, ",");
    while (temp != NULL && v == 1) {
      nombre[i] = (char *)malloc(100 * sizeof(char));
      strcpy(nombre[i], temp);
      temp = strtok(NULL, ",");
      i++;
      break;
    }
    v = 1;
  }
  return nombre;
}

// Devuelve un numero con la cantidad de columnas
int cont_col(FILE *archivo) {
  char fila[200];
  int n_c = 0;
  while (fgets(fila, 200, archivo)) {
    char *temp;
    temp = strtok(fila, ",");
    while (temp != NULL) {
      temp = strtok(NULL, ",");
      n_c++;
    }
    rewind(archivo);
    return n_c - 1;
  }
  rewind(archivo);
  return 0;
}

// Devuelve una sucesion de numeros
int *list(int n_f) {
  int *lista = malloc(n_f * sizeof(int));
  int j = 0;
  for (int i = 0; i < n_f; i++) {
    lista[i] = j;
    j++;
  }
  return lista;
}

int main(int argc, char **argv) {
  if (argv[1] == NULL) {
    printf("ERROR: No se ha ingresado archivo\n");
    return 0;
  }
  FILE *archivo = fopen(argv[1], "r");
  if (archivo == NULL) {
    printf("ERROR: El archivo no existe o está sin datos\n");
    return 0;
  }
  int n_c = cont_col(archivo);
  int n_f = cont_filas(archivo);
  char fila[200];
  int var = 0;
  int j = 0;
  float *arrprom = malloc(n_f * sizeof(float));
  while (fgets(fila, 200, archivo)) {
    char *temp;
    temp = strtok(fila, ",");
    while (temp != NULL && var == 1) {
      float notas = 0;
      temp = strtok(NULL, ",");
      for (int i = 0; i < n_c; i++) {
        notas = notas + atof(temp);
        temp = strtok(NULL, ",");
      }
      arrprom[j] = notas / n_c;
      j++;
    }
    var = 1;
  }
  char **nombres = nmbres(argv[1]);
  int *orden = list(n_f);

  TICSmergeSort(arrprom, orden, 0, n_f);

  printf("\n");

  int maxd = n_f;

  if (n_f > 10) {
    maxd = 10;
  }

  for (int i = 0; i < maxd; i++) {
    printf("%i.- %s: %f\n", i + 1, nombres[orden[i] + 1], arrprom[i]);
  }

  for (int i = 0; i < n_f; i++) {
    incert(nombres[orden[i] + 1], arrprom[i]);
  }

  char letra;
  int ascii;
  printf("\nIngrese una letra: ");
  scanf("%c", &letra);
  printf("\n");

  if (((int)letra >= 97) && ((int)letra <= 122)) {
    int i = (int)letra - 32;
    letra = i;
  }
  ascii = (int)letra - 65;

  tabla[ascii] = head[ascii];
  while (tabla[ascii] != NULL) {
    printf("%s: %f\n", tabla[ascii]->nombre, tabla[ascii]->promedio);
    tabla[ascii] = tabla[ascii]->siguiente;
  }

  return 0;
}