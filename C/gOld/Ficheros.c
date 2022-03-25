#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Contar caracteres de Fichero abierto
int cont_char(FILE *archivo){
    int n = 0;
    while(!feof(archivo)){
        char c = fgetc(archivo);
        n++;
    }
    rewind(archivo);
    return n;
}

//Pasar por completo a string un Fichero abierto
char *fstr(FILE *archivo, int cont_caracteres){

    char *ftxt = malloc(cont_caracteres*sizeof(char));
    int cont = 0;
    
    while(!feof(archivo)){
        char c = fgetc(archivo);
        if( ("%d",c) != -1 ){
          //printf("\n%c - %d",c,c);
          ftxt[cont] = c;
        } 
        cont++;
    }
    
    rewind(archivo);
    return ftxt;
}

//Imprime caracter por caracter un fichero completo
void fprint(FILE *archivo){
    while(!feof(archivo)){
        printf("%c",fgetc(archivo));
    }
    
    rewind(archivo);
}

//Guardar texto en fichero sin sobreescribir
void fsavestr(FILE* archivo, char* dir, char* str, int pass){

  FILE* new_file = freopen(dir,"a",archivo); 
  
  if (pass) fprintf(new_file,"\n"); 

  for(int i = 0; i < (strlen(str)) ; i++){  
    if( (int)str[i] != -1)fprintf(new_file,"%c",str[i]);
    
  }
  rewind(archivo);
}


//crear lista de char** columna especifica csv con 
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
      data[i] = (char *)malloc(300 * sizeof(char));
      strcpy(data[i], temp);
      i++;
    }
    salto = 1;
  }

  rewind(archivo);

  return data;
}


//crear lista de floats* columna especifica csv con 
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


//Imprimir en ascii cada caracter de fichero
int fLecAux(FILE *archivo){
    int c = 1;
    while(!feof(archivo)){
        char ctx = fgetc(archivo);
        int ascii = (int)ctx;
        if(ascii != 13 && ascii != 10 && ascii > 31)printf("Caracter %i: [ %c ] - ACSII: %i\n",c,ctx,ascii);
        if(ascii == 13)printf("Caracter %i: [ \\n ] - ACSII: %i\n",c,ascii);
        if(ascii == 10)printf("Caracter %i: [ Nueva linea ] - ACSII: %i\n",c,ascii);
        if(ascii <= 31 && ascii != 13 && ascii != 10)printf("\x1b[31mCaracter %i: [ %c ] - ACSII: %i\x1b[0m\n",c,ctx,ascii);
        if (c == 950){ printf("Se excedieron los caracteres\n"); rewind(archivo); return 0; }
        c++;
    }
    rewind(archivo);
}

//Contar la cantidad de filas en un fichero
int cont_filas(FILE *archivo){
    int n_f = 0;
    char temp_fila[200];
    while(fgets(temp_fila, 200, archivo)){
        char *temp;
        temp = strtok(temp_fila,"\n");
        n_f++;    
    }
    rewind(archivo);
    return n_f-1;
}

//Devuelve un numero con la cantidad de columnas
int cont_col(FILE *archivo){
    int n_c = 0;
    char temp_fila[200];
    while(fgets(temp_fila,200,archivo)){
        char *temp;
        temp = strtok(temp_fila,",");
        while(temp!=NULL){
            temp = strtok(NULL,",");
            n_c++; 
        }
        rewind(archivo);
        return n_c - 1;
    }
    return 0;
}

//Comprobar si el archivo está correctamente puesto
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
}


//Rehacer un fichero con string sobrescribiendolo
void fsavestr(char dir[],char *txt){
  FILE *archivo = fopen(dir,"w");
  for(int i = 0; i < (strlen(txt)) ; i++){
      if(txt[i] != 0){ // evitar espacios no asignados     
          fprintf(archivo,"%c",txt[i]); //escribir caracter por caracter
      }
  }
  fclose(archivo);
}

int main(int argc, char **argv){
    argv_excepcion(argv);
    printf("Leyendo: \n");
    FILE *ar = fopen(argv[1],"r");
    fLecAux(ar);
    printf("\nColumnas: %i - Filas %i\n",cont_col(ar), cont_filas(ar) );
    printf("Caracteres: %i\n",cont_char(ar));
    return 0;
}

