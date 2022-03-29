#include "lista.h"

list* create_list() {
  list* nueva_lista = (list*)malloc(sizeof(list));
  nueva_lista->head = NULL;
  nueva_lista->tail = NULL;
  return nueva_lista;
}

void add_node(list* lista, float real, float imag) {
  node* nuevo_nodo = (node*)malloc(sizeof(node));
  nuevo_nodo->real = real;
  nuevo_nodo->imag = imag;
  nuevo_nodo->next = NULL;

  if (lista->head == NULL) {
    lista->head = nuevo_nodo;
    lista->tail = nuevo_nodo;
  } else {
    lista->tail->next = nuevo_nodo;
    lista->tail = nuevo_nodo;
  }
}

void print_list(list* lista) {
  printf("Lista :)\n");
  node* it = lista->head;

  int indice = 0;
  while (it != NULL) {
    printf("%i -> R:%f, I:%f\n", indice, it->real, it->imag);
    it = it->next;
    indice++;
  }
}

void delete_node(list* lista, int pos) {
  node* tmp;
  if (pos == 0) {
    tmp = lista->head;
    lista->head = tmp->next;
    free(tmp);
    if (lista->head == NULL) {
      lista->tail = NULL;
    }
  } else {
    node* it = lista->head;
    int indice = 1;
    while (it->next != NULL) {
      if (indice == pos) {
        tmp = it->next->next;
        break;
      }
      it = it->next;
      indice++;
    }
    if (it->next == lista->tail) {
      lista->tail = it;
    }
    free(it->next);
    it->next = tmp;
  }
}

void delete_list(list* lista) {
  node* it = lista->head;
  node* tmp;

  while (it != NULL) {
    tmp = it;
    it = it->next;
    free(tmp);
  }
  free(lista);
}

void delete_node_for(list* lista, int pos) {
  node* tmp;
  if (pos == 0) {
    tmp = lista->head;
    lista->head = tmp->next;
    free(tmp);
    if (lista->head == NULL) {
      lista->tail = NULL;
    }
  } else {
    node* it;
    int i;
    for (i = 1, it = lista->head; i < pos; i++, it = it->next)
      ;
    tmp = it->next->next;
    if (it->next == lista->tail) {
      lista->tail = it;
    }
    free(it->next);
    it->next = tmp;
  }
}

void delete_node_ptr(list* lista, int pos) {
  node* tmp;
  if (pos == 0) {
    tmp = lista->head;
    lista->head = tmp->next;
    free(tmp);
    if (lista->head == NULL) {
      lista->tail = NULL;
    }
  } else {
    node* prev = lista->head;
    node* it = prev->next;
    node* after = it->next;
    int indice = 1;

    while (it != NULL && indice != pos) {
      prev = it;
      it = after;
      after = after->next;
      indice++;
    }
    if (it == lista->tail) {
      lista->tail = prev;
    }
    free(it);
    prev->next = after;
  }
}