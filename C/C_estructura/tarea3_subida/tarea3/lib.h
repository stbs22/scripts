#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 26


typedef struct p {

  char *nombre;

  float promedio;

  struct p *siguiente;

} HashNodo;



int hash(char nombre[]);

void HashInsertar(char *nom, float prom);

void TICSmerge(float arr[], int arr2[], int l, int m, int r);

void TICSmergeSort(float arr[], int arr2[], int l, int r);

int cont_filas(FILE *archivo);

int cont_col(FILE *archivo);

void argv_excepcion(char **argv);

float *crea_means(FILE *archivo, int n_f, int n_c);

char **crea_nombres(FILE *archivo, int nfilas);

int *list(int n_f);