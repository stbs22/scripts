#include "pregunta_3.h"

int frecuencia_de_una_nota(nodo* raiz, int nota) {
  if (raiz == NULL) return 0;
  int count = 0;
  if (nota < raiz->nota)
    count += frecuencia_de_una_nota(raiz->left, nota);
  else if (nota > raiz->nota)
    count += frecuencia_de_una_nota(raiz->right, nota);
  else
    count += 1 + frecuencia_de_una_nota(raiz->down, nota);
  return count;
}