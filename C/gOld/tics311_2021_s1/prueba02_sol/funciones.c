#include "funciones.h"

#include "pregunta_1.h"
#include "pregunta_2.h"
#if funcion > 2
ciudad** read_hash(char* filename, int number) {
  ciudad** tabla = crear_tabla_hash(number);
  FILE* f = fopen(filename, "r");
  int lines = 0;
  char word[1000];
  char* token;
  ciudad* nueva_ciudad;
  while (fgets(word, 1000, f) != NULL) {
    lines++;
  }
  rewind(f);

  for (int i = 0; i < lines; i++) {
    fgets(word, 1000, f);
    if (i == 0) continue;

    nueva_ciudad = (ciudad*)malloc(sizeof(ciudad));
    token = strtok(word, ",");
    strcpy(nueva_ciudad->region, token);
    token = strtok(NULL, ",");
    nueva_ciudad->id_region = atoi(token);
    token = strtok(NULL, ",");
    strcpy(nueva_ciudad->comuna, token);
    token = strtok(NULL, ",");
    nueva_ciudad->id_comuna = atoi(token);
    token = strtok(NULL, ",");
    nueva_ciudad->poblacion = atoi(token);
    token = strtok(NULL, ",");
    nueva_ciudad->casos = atoi(token);
    insertar(tabla, nueva_ciudad);
  }

  return tabla;
}
#endif
void print_hash(ciudad** tabla, int number) {
  ciudad* it;
  for (int i = 0; i < number; i++) {
    it = tabla[i];
    while (it != NULL) {
      printf("%i,", it->id_comuna);
      printf("%s,", it->comuna);
      printf("%i,", it->casos);
      printf("%i\n", it->poblacion);
      it = it->sgte;
    }
  }
}