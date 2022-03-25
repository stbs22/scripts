#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct a{
    int data;
    struct a *izquierda;
    struct a *derecha;
}nodo;

nodo* nuevo_arbol(int data){
    nodo* arbol = malloc(sizeof(nodo));
    
    arbol->data = 0;
    
    arbol->derecha = NULL;
    arbol->izquierda = NULL;

    return arbol;
}

int main(int argc, char** argv){
    
    nodo* arbol;// = malloc(sizeof(nodo));
    //arbol = nuevo_arbol(10);

    if(arbol == NULL) printf("\nctm");

    printf("%i\n",arbol->data);

    return 0;
}