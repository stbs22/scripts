#include "lib.h"

//ESTRUCTURA DE DATOS Y ALGORITMOS
//TICS311 Seccion_01 2021

// Andres Guevara
// Esteban Hernández
// Mátias Hermosilla


char** extr_columna_char(FILE *archivo, int nfilas, int pos){

  char fila[300];

  char **data = (char **)malloc( (nfilas-1) * sizeof(char *));

  int salto = 0, i = 0;

  while(fgets(fila, 300, archivo)){

    char *temp = strtok(fila, ",");
    
    if (temp != NULL && salto == 1){
      
      for(int x = 0; x < pos; x++){
        temp = strtok(NULL, ",");
      }
      printf("salida guardando: %s\n",temp);
      
      data[i] = (char *)malloc(300 * sizeof(char));
      strcpy(data[i], temp);
      i++;
    }
    salto = 1;
  }

  rewind(archivo);

  return data;
}


float* extr_columna_float(FILE *archivo, int nfilas, int pos){

  char fila[300];
  float *data = (float *)malloc( (nfilas-1) * sizeof(float));
  int salto = 0, i = 0;

  while(fgets(fila, 300, archivo)){

    char *temp = strtok(fila, ",");
    
    if (temp != NULL && salto == 1){
      
      for(int x = 0; x < pos; x++){
        temp = strtok(NULL, ",");
      }
      data[i] = atof(temp);
      i++;
    }
    salto = 1;
  }

  rewind(archivo);
  return data;
}


int main(int argc, char **argv) {

  //-------------------------------------------
  
  FILE *archivo2 = fopen(argv[1],"r");

  HashNodo* tabla_exclusiva_de_andres_NO_BORRAR[26];
  HashNodo* alumno;
  
  //-------------------------------------------
  
  argv_excepcion(argv);

  FILE *archivo = fopen(argv[1],"r");
  
  int nfilas = cont_filas(archivo);
  int ncolum = cont_col(archivo);
  
  char** tabla = extr_columna_char(archivo,nfilas,0);
  
  for(int i = 0; i < nfilas-1;i++){
    printf("caracter %i: %s\n",i,tabla[i]);
  }

  return 0;
}