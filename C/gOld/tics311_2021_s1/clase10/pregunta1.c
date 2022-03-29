#include "funciones.h"

void ordenar(struct p **lista){
  struct p* lista_ordenada = NULL;

  struct p* persona = *lista;
  while (persona!=NULL){
    struct p *tmp = persona->next;
    // si la lista esta vacia
    if (lista_ordenada==NULL){
      lista_ordenada = persona;
      persona->next = NULL;
    }
    // si va en la primera posicion
    else if (persona->altura < lista_ordenada->altura){
      persona->next = lista_ordenada;
      lista_ordenada = persona;
    }
    //
    else {
      struct p* iter = lista_ordenada;
      while ((iter->next!=NULL) && (iter->next->altura < persona->altura)){
        iter = iter->next;
      }
      struct p* tmp2 = iter->next; 
      iter->next = persona;
      persona->next = tmp2;
    }
    persona = tmp;
  }

  *lista = lista_ordenada;
}