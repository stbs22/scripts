#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//leer y retornar lista con numeros de archivo
int* leer_archivo_numero(char* nombre){

  int* lista_n;
  int filas = 0;
  char arr[100];

  FILE* archivo = fopen(nombre, "r");
  
  while (fgets(arr, 100, archivo) != NULL) {
    filas++;
  }
  rewind(archivo);
  
  lista_n = (int*)malloc(filas * sizeof(int));

  for (int i = 0; i < filas; i++) {
    fgets(arr, 100, archivo); //recorrer y tokenizar archivo con cada fila en arr
  
    lista_n[i] = atoi(arr);
  }

  return lista_n;
}

int min(int a, int b){
    return (a < b ? a : b);
}

int main(void){
    printf("%i\n",min(11,10));
}
