#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Imprimir en ascii cada caracter de fichero
void sLecAux(char *texto){
  for(int i = 0; i< strlen(texto) ; i++){
      
      char ctx = texto[i];
      int ascii = (int)ctx, index = i+1;

      if(ascii != 13 && ascii != 10 && ascii > 31)printf("Caracter %i: [ %c ] - ACSII: %i\n",index,ctx,ascii);
      if(ascii == 13)printf("Caracter %i: [ \\n ] - ACSII: %i\n",index,ascii);
      if(ascii == 10)printf("Caracter %i: [ Nueva linea ] - ACSII: %i\n",index,ascii);
      if(ascii <= 31 && ascii != 13 && ascii != 10)printf("\x1b[31mCaracter %i: [ %c ] - ACSII: %i\x1b[0m\n",index,ctx,ascii);
      if (i == 950){ printf("Se excedieron 950 caracteres\n");  return;}
  }
  printf("incluir offset (-1) para numero de caracter\n");
}

char int_txt(int ascii){
  char caracter = ("%c",ascii);
  return caracter;
}

int txt_int(char caracter){
  int ascii = (int)caracter;
  return ascii;
}

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

int min(int a, int b){
    return (a > b) ? a : b;
}


int main(void){

  char* texto = "wn te fue como el pico";
  sLecAux(texto);

  //int val = txt_int('m');
  char* val = malloc(sizeof(char));
  val[0] = int_txt(99);

  char ctm = ("%c",27);
  printf("\n val = %c\n",ctm);
}
