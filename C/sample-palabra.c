#include "my_strings.h"
#include <stdio.h>
#include <stdlib.h>

// Grupo 14 Lenguajes y Paradigmas de Programación 26-03-21
// Andres Guevara
// Matias Hermosilla
// Esteban Hernández

int main (void){
    char* str1;
    
    printf("Escribe una palabra: ");
    scanf("%s",str1);
    
    char* str2 = (char*) malloc(20 * sizeof(char));

    printf("Escribe %s: ",str1);
    scanf ("%s", str2);

    int var =  strcmpic (str1, str2);
    
    if (var == 0 ) printf("%d\n",var);
    if (var == 1 ) printf("%d\n",var);
}