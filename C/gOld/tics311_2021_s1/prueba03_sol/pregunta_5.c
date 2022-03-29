#include "pregunta_5.h"

int nota_mas_frecuente_2(nodo* raiz, int* nota_frecuente) {
  if (raiz == NULL) return 0;
  int count = 0;
  int tmp_max;
  nodo* tmp = raiz;

  while (tmp != NULL) {
    count++;
    tmp = tmp->down;
  }
  tmp_max = raiz->nota;
  int count_left = nota_mas_frecuente_2(raiz->left, nota_frecuente);
  if (count_left > count) {
    count = count_left;
  } else {
    *nota_frecuente = tmp_max;
  }
  tmp_max = *nota_frecuente;

  int count_right = nota_mas_frecuente_2(raiz->right, nota_frecuente);
  if (count_right > count) {
    count = count_right;
  } else {
    *nota_frecuente = tmp_max;
  }
  return count;
}