#include <stdio.h>
#include <stdlib.h>

typedef struct p {
  int dato;
  struct p* siguiente;
} nodo;

typedef struct l {
  nodo* head;
} list;

int main(int argc, char* argv[]) {
  list* lista = malloc(sizeof(list));
  nodo* current;
  lista->head = NULL;
  for (int i = 0; i < 10; i++) {
    if (lista->head == NULL) {
      lista->head = malloc(sizeof(nodo));
      lista->head->dato = i;
      lista->head->siguiente = NULL;
      current = lista->head;
    } else {
      current->siguiente = malloc(sizeof(nodo));
      current = current->siguiente;
      current->dato = i;
      current->siguiente = NULL;
    }
  }

  current = lista->head;
  while (current != NULL) {
    printf("%i - ", current->dato);
    current = current->siguiente;
  }
  printf("\n");
  return 0;
}