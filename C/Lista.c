#include <stdio.h>

typedef struct n {
    int numero;
    struct n* next;
} node;

typedef struct l {
    node* head;
    node* tail;
} list;


list* create_list() {
  list* nueva_lista = (list*)malloc(sizeof(list));
  nueva_lista->head = NULL;
  nueva_lista->tail = NULL;
  return nueva_lista;
}

void add_node(list* lista, int numero) {
  node* nuevo_nodo = (node*)malloc(sizeof(node));
  nuevo_nodo->numero = numero;
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
    printf("%i -> R:%f, I:%f\n", indice, it->numero);
    it = it->next;
    indice++;
  }
}

int main(int argc, char* argv[]){
    list* lista = create_list();

    add_node(lista, 5.0);
    add_node(lista, 4.0);

    print_list(lista);

    return 0;
}