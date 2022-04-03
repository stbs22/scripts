#include "lib.h"


HashNodo *tabla[SIZE];  // tabla hash creada
HashNodo *head[SIZE];   // el primer elemento de una lista de cierto bucket


//Hash apellido en ascii
int hash(char nombre[]) {

  for (int i = 0;; i++) {

    // devolver caracter luego del primer espacio menos 65 para ir de 0 a 25
    if ((int)nombre[i] == 32) return ((int)nombre[i + 1] - 65);
  
  }

  return 0;
}


// Incertar cada alumno a su bucket y a traves de listas
void HashInsertar(char *nom, float prom) {
  HashNodo *alumno;

  int index = hash(nom);

  if (tabla[index] == NULL) { //ingresa el primer alumno a un bucket vacio
    
    alumno = malloc(sizeof(HashNodo));

    alumno->nombre = nom;
    alumno->promedio = prom;
    alumno->siguiente = NULL;

    tabla[index] = alumno;
    head[index] = tabla[index];

  } else {  // ingresa alumnos a buckets llenos a traves de listas
    alumno = tabla[index];

    alumno->siguiente = malloc(sizeof(HashNodo));
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


//chequeo correcto de ejecutable
void argv_excepcion(char **argv){

    if(argv[1] == NULL){
        printf("\x1b[31mERROR:\x1b[0m No se ha ingresado archivo\n");
        exit(1);
    }
    
    FILE *archivo = fopen(argv[1],"r");

    if(archivo == NULL){
        printf("\x1b[31mERROR:\x1b[0m El archivo \'%s\' no existe o no tiene datos\n",argv[1]);
        exit(1);
    }
    fclose(archivo);
    return;
}


//crear lista con promedios
float *crea_means(FILE *archivo, int n_f, int n_c){
  
  float *arrprom = malloc(n_f * sizeof(float));

  char fila[200];
  int var = 0;
  int j = 0;

  while (fgets(fila, 200, archivo)) {
    char *temp;
    temp = strtok(fila, ",");
    
    while (temp != NULL && var == 1) {
      float notas = 0;
      temp = strtok(NULL, ",");

      for(int i = 0; i < n_c; i++) {
        notas = notas + atof(temp);
        temp = strtok(NULL, ",");
      }
      arrprom[j] = notas / n_c;
      j++;
    }
    var = 1;
  }
  rewind(archivo);
  return arrprom;

}


// Devuelve un arreglo con todos los nombres de un directorio
char **crea_nombres(FILE *archivo, int nfilas) {

  char **nombre = (char **)malloc(nfilas * sizeof(char *));

  char file[300];
  int salto = 0, i = 1;

  while (fgets(file, 300, archivo)) {

    char *temp = strtok(file, ",");
    if(temp != NULL && salto == 1) {

      nombre[i] = (char *)malloc(300 * sizeof(char));

      strcpy(nombre[i], temp);
      temp = strtok(NULL, ",");
      i++;
    }
    salto = 1;
  }
  return nombre;
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
