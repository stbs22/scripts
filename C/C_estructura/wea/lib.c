#include "lib.h"

void display(HashNodo* tabla_hash) {

   for(int i = 0; i<26; i++) {

    printf("\n ~~ \n");

    printf("\nindex: %i, Letra: %c\n",i+1,(i+65));

    /*
    if(tabla_hash->key != NULL){
      printf("\nNombre: %s\nPromedio: %f\n",tabla_hash[i].nombre);}
    }
    */

    printf("\n ~~ \n");
   }
	
   printf("\n");
}


int fhash(char nombre[]){
  for(int i = 0;;i++){ 
    //devolver caracter luego del primer espacio menos 65 para ir de 0 a 26
    if( (int)nombre[i] == 32 ) return ( (int)nombre[i+1] - 65 );
  }
  return 0;
}

int cont_filas(FILE *archivo){

    int n_f = 0;
    char temp_fila[200];

    while(fgets(temp_fila, 200, archivo)){
        char *temp;
        temp = strtok(temp_fila,"\n");
        n_f++;    
    }
    rewind(archivo);

    return n_f;
}

int cont_col(FILE *archivo){
    int n_c = 0;
    char fila[200];
    while(fgets(fila,200,archivo)){
        char *temp;
        temp = strtok(fila,",");
        while(temp!=NULL){
            temp = strtok(NULL,",");
            n_c++; 
        }
        rewind(archivo);
        return n_c - 1;
    }
    return 0;
}

char** extraer_columna(FILE *archivo, int nfilas, int pos){

  char fila[300];

  char **data = (char **)malloc( (nfilas-1) * sizeof(char *));
  int salto = 0, i = 1;

  while(fgets(fila, 300, archivo)){

    char *temp = strtok(fila, ",");
    
    if (temp != NULL && salto == 1){
      
      for(int x = 0; x < pos; x++){
        printf("Salto-");
        temp = strtok(NULL, ",");
      }
      printf("salida guardando: %s\n",temp);
      
      data[i] = (char *)malloc(300 * sizeof(char));
      strcpy(data[i], temp);
    }
    salto = 1;
  }

  rewind(archivo);

  return data;
}



float *crea_means(FILE *archivo, int nfilas, int ncolum){

  float* promedios = malloc( (nfilas-1) * sizeof(float*));
  
  int salto = 0, cont = 1;

  char fila[300];

  while(fgets(fila, 300, archivo)){
            
    float sum = 0;
    int N = 0;
    
    char *temp = strtok(fila, ",");    
  
    if (salto == 1) {

      for(int i = 0; i < ncolum; i++){
        temp = strtok(NULL,",");

        sum = sum + atof(temp);
        
        N++;
      }

      promedios[cont] = (sum/N);
      cont++;
    }
    salto = 1;
  }

  rewind(archivo);

  return promedios;
}


HashNodo* crea_hash(char** nombres, float* promedios, int nfilas){
  
  HashNodo* tabla = (HashNodo*)malloc(26*sizeof(HashNodo));

  for(int i = 1; i < nfilas; i++){
    
    int index = fhash(nombres[i]);

    tabla[index].key = index + 65;
  
    strcpy(tabla[index].nombre,nombres[i]);
    
    tabla[index].promedio = promedios[i];

    strcpy(tabla[index].nombre,nombres[i]);

    //tabla[index].siguiente = (HashNodo*)malloc(sizeof(HashNodo));
  

    printf("Nombre: %s \nHash: %i\n",nombres[i],fhash(nombres[i]));
    
    printf("ascii asignado: %i - %c\n\n",tabla[index].key,(char)tabla[index].key);

  }
  printf("\n");
  
  return tabla;  
}


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

/*
void incert(char nom, int prom, HashNodo* tabla){

  HashNodo* alumno;
  int index = fhash(nom);

  if (tabla[index] == NULL){
    alumno = (HashNodo*)malloc(sizeof(HashNodo));
    alumno->nombre = nom;
    alumno->promedio = prom;
    tabla[index] = alumno;

  }else{
    alumno->siguiente = malloc(sizeof(HashNodo));
    alumno = alumno->siguiente;
    alumno->nombre = nom;
    alumno->promedio = prom;
    alumno->siguiente = NULL;

  }
  
}
*/