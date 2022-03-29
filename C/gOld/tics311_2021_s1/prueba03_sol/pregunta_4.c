#include "pregunta_4.h"

int nota_mas_frecuente(nodo* raiz) {
  if (raiz == NULL) return 0;
  int count = 0;
  nodo* tmp = raiz;

  while (tmp != NULL) {
    count++;
    tmp = tmp->down;
  }
  int count_left = nota_mas_frecuente(raiz->left);

  int count_right = nota_mas_frecuente(raiz->right);
  if (count_left > count_right && count_left > count)
    return count_left;
  else if (count_right > count_left && count_right > count)
    return count_right;
  else
    return count;
}