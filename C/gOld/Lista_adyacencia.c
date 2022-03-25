
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_nodos 10

typedef struct p {
  
  int nodo;
  struct p *siguiente;

} lista;

lista *current[SIZE_nodos]; 
lista *Lista_adyacencia[SIZE_nodos]; 

void AgregarArista(int nodo1, int nodo2) {

  lista *bucket;

  if (current[nodo1] == NULL) { //ingresa el primer alumno a un bucket vacio
    
    bucket = malloc(sizeof(lista));

    bucket->nodo = nodo2;
    bucket->siguiente = NULL;

    current[nodo1] = bucket;
    Lista_adyacencia[nodo1] = current[nodo1];

  } else {  // ingresa alumnos a buckets llenos a traves de listas

    bucket = current[nodo1];

    bucket->siguiente = malloc(sizeof(lista));
    bucket = bucket->siguiente;

    bucket->nodo = nodo2;
    bucket->siguiente = NULL;

    current[nodo1] = current[nodo1]->siguiente;
  }

}

void p_nodo(lista* wea){
    if(wea != NULL){
        printf("-->%i",wea->nodo);
        p_nodo(wea->siguiente);
    }
}

void p_lista(lista** wea){
    for(int i = 0; i < SIZE_nodos; i++){
        printf("\nNODO %i: ",i);
        if(wea[i] != NULL) p_nodo(wea[i]);
    } 
    
}

int main(void){
    
    AgregarArista(2,1);
    AgregarArista(2,3);
    AgregarArista(2,5);
    AgregarArista(4,5);
    AgregarArista(4,2);

    p_lista(Lista_adyacencia);
    return 0;
}


