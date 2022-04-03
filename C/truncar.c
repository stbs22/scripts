#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void mostrar_truncado(float n){
    
    printf("%c.",(int)(n)+'0');

    char digito_1 = ((n - (int)(n))*10) +'0'; 
    printf("%c",digito_1);

    return;
}

char* truncar(float n){
    
    char* temp = malloc(3*sizeof(char));
    
    temp[0] = (int)(n)+'0';
    temp[1] = '.';
    temp[2] = ((n - (int)(n))*10) +'0';
    temp[3] = '\0';

    return temp;
}

int max(int a, int b){
  if(a > b) return a;
  else return b;
}


int main(int argc, char** argv){
    
    // float n = 6.8854;
    // printf("Numero a cambiar: %f\n",n);


    // printf("Numero nuevo: ");
    // mostrar_truncado(n);
    // char* kwea = truncar(n);
    // printf("\nNumero new: %s",kwea);
    // printf("\n");

    printf("%i",max(6,10));
    return 0;
}