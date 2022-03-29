#include "pregunta_1.h"
#include "pregunta_2.h"
#include "pregunta_3.h"
#include "pregunta_4.h"
#include "pregunta_5.h"

int main(int argc, char** argv) {
  nodo* raiz = crear_arbol_desde_archivo(argv[1]);
  float puntaje;
  float total = 0;
  int pauta;
  printf("\nPregunta\tSu respuesta\tResp. Pauta\tPuntaje\n");
  printf("-----------------------------------------------------------\n");

  // Pregunta 1: Cree una función que retorne la profundidad del árbol
  int p = profundidad(raiz);
  pauta = 30;
  puntaje = p == pauta ? 0.48 : 0;
  printf("%5d\t\t%5d\t\t%6d\t\t%5.2f\n", 1, p, pauta, puntaje);
  total += puntaje;

  // Pregunta 2: Cree una función que retorne la cantidad de nodos del árbol
  p = cantidad_alumnos(raiz);
  pauta = 1000;
  puntaje = p == pauta ? 0.48 : 0;
  printf("%5d\t\t%5d\t\t%6d\t\t%5.2f\n", 2, p, pauta, puntaje);
  total += puntaje;

  // Pregunta 3: Cree una función que retorne la cantidad de personas que tienen
  // una nota entregada como parámetro
  p = frecuencia_de_una_nota(raiz, 50);
  pauta = 24;
  puntaje = p == pauta ? 0.48 : 0;
  printf("%5d\t\t%5d\t\t%6d\t\t%5.2f\n", 3, p, pauta, puntaje);
  total += puntaje;

  // Pregunta 4: Cree una función que retorne la cantidad de personas que tienen
  // la nota con mayor frecuencia
  p = nota_mas_frecuente(raiz);
  pauta = 25;
  puntaje = p == pauta ? 0.48 : 0;
  printf("%5d\t\t%5d\t\t%6d\t\t%5.2f\n", 4, p, pauta, puntaje);
  total += puntaje;

  // Pregunta 5: Cree una función que retorne la cantidad de personas que tienen
  // la nota con mayor frecuencia y llene el parámetro nota_frecuente con la
  // nota de mayor frecuencia
  int nota_frecuente = -1;
  int frecuencia = nota_mas_frecuente_2(raiz, &nota_frecuente);

  puntaje = (nota_frecuente == 15 && frecuencia == 25) ? 0.48 : 0;
  printf("%5d\t\t%3d %2d\t\t  15   25\t%5.2f\n", 5, nota_frecuente, frecuencia,
         puntaje);
  total += puntaje;

  eliminar_arbol(raiz);

  printf("-----------------------\n");
  printf("Puntaje total parte práctica: %0.2f\n", total);
  printf(
      "\n*** Esta corrección automática corresponde a una GUÍA, y en ningún "
      "caso corresponde al puntaje final obtenido en la prueba. ***\n");
  return 0;
}