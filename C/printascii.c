#include <stdio.h>

//recibe string como argumento y devuelve valor ascii de cada caracter

int main(int argc, char *argv[]){

    for (int i = 1; i < argc; i++){
        
        printf("%s: ", argv[i]);
        
        for (int j = 0; argv[i][j] != '\0'; j++){
            printf("%c[%d] ", argv[i][j], argv[i][j]);
        }
        
        printf("\n");
    }
    
    return 0;
}