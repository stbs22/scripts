#include "funciones.h"

void divide_lista_genero(struct p **lista, struct p **lista_m, struct p **lista_h){

  struct p* persona = *lista;
  struct p* ultimo_m = NULL;
  struct p* ultimo_h = NULL;
  while (persona != NULL){
    struct p* tmp = persona->next;
    if (strcmp(persona->genero, "Female")==0){
      if (*lista_m == NULL){
        *lista_m = persona;
        persona->next = NULL;
        ultimo_m = persona;
      }
      else {
        ultimo_m->next = persona;
        persona->next = NULL;
        ultimo_m = persona;
      }
    }
    else {
      if (*lista_h == NULL){
        *lista_h = persona;
        persona->next = NULL;
        ultimo_h = persona;
      }
      else {
        ultimo_h->next = persona;
        persona->next = NULL;
        ultimo_h = persona;
      }
    }
    persona = tmp;
  }
  *lista = NULL;

}