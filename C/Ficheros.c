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

//Imprime caracter por caracter un fichero completo
void fprint(FILE *archivo){
    while(!feof(archivo)){
        printf("%c",fgetc(archivo));
    }
    rewind(archivo);
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

