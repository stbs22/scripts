
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void){
    
    int contador = 0;
    int matriz[10][10];

    for(int i = 0; i < 10; i++){
        
        for(int j = 0; j < 10; j++){
            matriz[i][j] = i*j;
        }
    }

    for(int i = 0; i < 10; i++){

        printf("-->");

        for(int j = 0; j < 10; j++){
            printf("\t(%i,%i)[%i] ",i,j,matriz[i][j]);
        }

        printf("\n");
    }

    return 0;
}