#include "funciones.h"

void unir_lista_intercalada(struct p **lista1,struct p **lista2,struct p **lista_final){

  struct p* persona_m = *lista1;
  struct p* persona_h = *lista2;
  struct p* ultimo = NULL;

  while((persona_m != NULL) && (persona_h != NULL)){
    struct p* tmp_m = persona_m->next;
    struct p* tmp_h = persona_h->next;

    if (*lista_final==NULL){
      *lista_final = persona_m;
      persona_m->next = persona_h;
      persona_h->next = NULL;
      ultimo = persona_h;
    }
    else {
      ultimo->next = persona_m;
      persona_m->next = persona_h;
      persona_h->next = NULL;
      ultimo = persona_h;
    }

    persona_m = tmp_m;
    persona_h = tmp_h;
  }
  *lista1 = NULL;
  *lista2 = NULL;
}
