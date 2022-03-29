#include <stdio.h>
#include <stdlib.h>

typedef struct n {
  float real;
  float imag;
  struct n* next;
} node;

typedef struct l {
  node* head;
  node* tail;
} list;

list* create_list();
void add_node(list* lista, float real, float imag);
void delete_node(list* lista, int pos);
void delete_node_for(list* lista, int pos);
void delete_node_ptr(list* lista, int pos);
void delete_list(list* lista);
void print_list(list* lista);