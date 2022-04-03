#include "lib.h"

// ESTRUCTURA DE DATOS Y ALGORITMOS
// TICS311 Seccion_01 2021 Tarea 3

// Andres Guevara
// Esteban Hernández
// Mátias Hermosilla

HashNodo *tabla[SIZE];
HashNodo *head[SIZE]; 

int main(int argc, char **argv) {

  argv_excepcion(argv);
  FILE *archivo = fopen(argv[1], "r");

  //guardar dimensiones del archivo
  int n_c = cont_col(archivo); 
  int n_f = cont_filas(archivo);

  //crear lista de promedios y nombres con mismos indices
  float *promedios = crea_means(archivo, n_f, n_c); 
  char **nombres = crea_nombres(archivo, n_f);

  //ordenar lista
  int *orden = list(n_f);
  TICSmergeSort(promedios, orden, 0, n_f);
  

  // imprime los primeros 10 elementos con los mejores promedios
  int maxd = n_f;

  if (n_f > 10) maxd = 10;

  printf("\n");
  for (int i = 0; i < maxd; i++) printf("%s: %f\n", nombres[orden[i] + 1], promedios[i]);


  //insertar elementos al bucket
  for (int i = 0; i < n_f; i++) HashInsertar(nombres[orden[i] + 1], promedios[i]);

  //pregunta por consola
  printf("\nIngrese una letra: ");
  char letra;
  scanf("%c", &letra);
 
  //hacer input independiente de mayuscula o minuscula
  if (((int)letra >= 97) && ((int)letra <= 122)) {
    int i = (int)letra - 32;
    letra = i;
  }
  int ascii = (int)letra - 65;

  //con bucket vacío:
  if (tabla[ascii]==NULL) printf("El bucket de letra %c se encuentra vacío\n\n",letra); 

  //imprir lista entera de un bucket señalado
  tabla[ascii] = head[ascii];
  while (tabla[ascii] != NULL) {
    printf("%s: %f\n", tabla[ascii]->nombre, tabla[ascii]->promedio);
    tabla[ascii] = tabla[ascii]->siguiente;
  }

  return 0;
}