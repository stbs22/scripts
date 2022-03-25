#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct sample1 {
    int numero;
    struct sample1* next;
} node;

typedef struct sample2 {
    node* inicio;
    node* final;
} list;



list* create_list() {
  
  list* nueva_lista = (list*)malloc(sizeof(list));

  nueva_lista->inicio = NULL;
  nueva_lista->final = NULL;
  
  return nueva_lista;
}



void add_node(list* lista, int numero) {

  node* nuevo_nodo = (node*)malloc(sizeof(node));
  
  nuevo_nodo->numero = numero;
  
  nuevo_nodo->next = NULL;


  if (lista->inicio == NULL) {

    lista->inicio = nuevo_nodo;
    lista->final = nuevo_nodo;

  } else {

    lista->final->next = nuevo_nodo;
    lista->final = nuevo_nodo;
  }
  
}

int len_list(list* lista){
  node* it = lista->inicio;

  int indice = 0;

  while(it != NULL){
    indice++;
    it = it->next;
  }

  return indice;
}

void edit_nodo(list* lista, int n_nodo, int numero){
  
  int indice = 0;
  node* it = lista->inicio;

  if(n_nodo > len_list(lista)){
    printf("el nodo excede el largo de la lista\n");
    return;
  }

  while(indice != n_nodo){  
    indice++;
    it = it->next;
  }
  it->numero = numero;

}

void print_list(list* lista) {

  printf("Lista:");
  
  node* it = lista->inicio;

  int indice = 0;

  if(it == NULL){
    printf(" NULL");
  }
  10
  while (it != NULL) {
    printf("\n%i -> N:%i", indice, it->numero);
    it = it->next;
    indice++;
  }
}

int main(int argc, char* argv[]){

    list* lista = create_list();

    while(1){
      
      printf("\n\n1:agregar nodo nuevo\n2:editar un nodo\n3:imprimir lista\n4:imprimir nodo\n5:rellenar lista");
      printf("\n\nSeleccione: ");
      int op1;

      scanf("%d",&op1);
      switch(op1){

        case 1:
          
          printf("\ningrese numero nuevo:");

          int input;
          scanf("%d",&input);
          add_node(lista,input);

          print_list(lista);

          break;

        case 2:
          
          print_list(lista);

          printf("\ningrese nodo a cambiar:");

          int input1;
          scanf("%d",&input1);

          printf("\ningrese numero nuevo:");
          int input2;
          scanf("%d",&input2);

          edit_nodo(lista, input1, input2);

          break;

        case 3:
          printf("largo de lista: %i\n",len_list(lista));
          print_list(lista);
          break;
      
        case 4:
          print_list(lista);
          break;

        case 5:
          printf("\ningrese cantidad de elementos:");
          int input1;
          scanf("%d",&input1);

          for(int i = 0; i <= input1; i++){
            add_node(lista, rand() % 501);
          }
          break;

        default:
          break;
      }
    }
    return 0;
}