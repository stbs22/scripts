#include "lista.h"

int main(int argc, char* argv[]) {
  list* lista = create_list();

  add_node(lista, 5.0, 4.0);
  add_node(lista, 4.0, 657.0);
  add_node(lista, 67.0, 12.0);
  add_node(lista, 46456.0, 1.0);
  print_list(lista);

  delete_node_ptr(lista, 2);
  print_list(lista);

  delete_node_ptr(lista, 2);
  print_list(lista);

  delete_node(lista, 0);
  print_list(lista);

  delete_node(lista, 0);
  print_list(lista);

  if (lista->head == NULL && lista->tail == NULL) {
    printf("Somos los mejores!! =)\n");
  } else {
    printf("Somos los peores dewlk mundo mundiual!\n");
  }

  add_node(lista, 46456.0, 1.0);
  print_list(lista);
  delete_list(lista);
  return 0;
}