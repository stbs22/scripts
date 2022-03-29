#include "my_strings.h"
#include <stdio.h>

// Grupo 14 Lenguajes y Paradigmas de Programación 26-03-21
// Andres Guevara
// Matias Hermosilla
// Esteban Hernández

int strcmpic(char* a, char* b){
    int cont = 0;
    
    for (int i = 0; i <= 50 ; i++){
        if((a[i] == '\0') && (b[i] == '\0')){

            if((a[i - 1] == '\0') || (b[i - 1] == '\0')){
                return 0;
            }
            break;
 
        }
        if(i == 50){
            printf("Sobrepasa 50 caracteres");
            return 0;
        }
        cont++;
    }

    for(int i = 0; i <= cont ;i++){

        int x = (int)a[i];
        int y = (int)b[i];
        
        if((x >= 65) && (x <= 90)){
            a[i] = (int)a[i] + 32;
        }
        if((y >= 65) && (y <= 90)){
            b[i] = (int)b[i] + 32;
        }

        if (a[i] != b[i]){
            return 0;
        }
    }
    return 1;
}