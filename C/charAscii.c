#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int main(int argc, char **argv){
  
  FILE *archivo = fopen(argv[1],"r");
  fLecAux(archivo);
  while(!feof(archivo)){
    printf("%c",fgetc(archivo));
  }
  printf("\n");
  return 0;
}
