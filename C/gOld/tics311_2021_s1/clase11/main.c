#include <stdio.h>
#include <stdlib.h>
#include "print_tree.h"


int main(){
  struct node *root = NULL;
  struct node *tmp = (struct node *)malloc(sizeof(struct node));
  tmp->data = 12;
  tmp->left = NULL;
  tmp->right = NULL;
  //root = tmp;  

  root = insert_balanceado(root, 80); 
  root = insert_balanceado(root, 20); 
  root = insert_balanceado(root, 30); 
  root = insert_balanceado(root, 40); 
  root = insert_balanceado(root, 50); 
  root = insert_balanceado(root, 25); 
  printf("1\n");
  //root = insert_balanceado(root, 25);
  printf("2\n");
  //root = insert_balanceado(root, 30);
  printf("3\n");
 print_ascii_node(root);
  /*
  show_nodes(root);
  printf("\n");
  show_nodes_preorden(root);
  printf("\n");
  */
  root = deleteNode(root, 50);
  //show_nodes_preorden(root);
  //printf("\n");

  print_ascii_node(root);

  free(root->left);
  free(root->right);
  free(root);
  return 0;
}


