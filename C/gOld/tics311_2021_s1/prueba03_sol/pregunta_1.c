#include "pregunta_1.h"

int profundidad(nodo *raiz) {
  if (raiz == NULL) return -1;
  int left = 1 + profundidad(raiz->left);
  int right = 1 + profundidad(raiz->right);
  int down = 1 + profundidad(raiz->down);
  if (left > right && left > down)
    return left;
  else if (right > left && right > down)
    return right;
  else
    return down;
}