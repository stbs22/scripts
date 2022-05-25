#include "utilities.h"
#if pregunta == 1
#include "pregunta_1.h"
#elif pregunta == 2
#include "pregunta_2.h"
#elif pregunta == 3
#include "pregunta_3.h"
#elif pregunta == 4
#include "pregunta_4.h"
#elif pregunta == 5
#include "pregunta_5.h"
#endif
int main(int argc, char* argv[]) {
#if pregunta == 1
  // 1.- swap
  ciudad c[2];

  c[0].id = 3627391;
  strcpy(c[0].rut, "77503124-7");
  strcpy(c[0].razon_social, "Sherbim SpA");
  strcpy(c[0].fecha_actuacion, "01-01-2022");
  strcpy(c[0].fecha_registro, "01-01-2022");
  strcpy(c[0].fecha_aprobacion, "01-01-2022");
  c[0].anio = 2022;
  strcpy(c[0].mes, "Enero");
  strcpy(c[0].comuna, "CURICO");
  c[0].region = 7;
  strcpy(c[0].codigo, "SpA");
  strcpy(c[0].tipo, "CONSTITUCIÓN");
  c[0].capital = 500000;
  strcpy(c[0].comuna_social, "CURICO");
  c[0].region_social = 7;
  c[1].id = 3627560;
  strcpy(c[1].rut, "77503123-9");
  strcpy(c[1].razon_social,
         "Constructora Jaime Sebastián Cortes  Olivarez E.I.R.L.");
  strcpy(c[1].fecha_actuacion, "01-01-2022");
  strcpy(c[1].fecha_registro, "01-01-2022");
  strcpy(c[1].fecha_aprobacion, "01-01-2022");
  c[1].anio = 2022;
  strcpy(c[1].mes, "Enero");
  strcpy(c[1].comuna, "CURICO");
  c[1].region = 7;
  strcpy(c[1].codigo, "EIRL");
  strcpy(c[1].tipo, "CONSTITUCIÓN");
  c[1].capital = 1000000;
  strcpy(c[1].comuna_social, "CURICO");
  c[1].region_social = 7;
  printf("PRE-SWAP\n");
  print_table(c, 2);
  swap(&c[0], &c[1]);
  printf("POS-SWAP\n");
  print_table(c, 2);

#elif pregunta == 2
  // 2.- Árbol como lista
  int N;
  ciudad* c = leer_archivo("ciudades.csv", &N);
  print_table(c, N);
#elif pregunta == 3
// 3.- sierra
#include "empresa.c"
  empresa* empresas = ordenar_empresas(c, 30);
  print_table(empresas, 30);
#elif pregunta == 4
#include "empresa.c"
  empresa* empresas = N_mejores(c, 30, 5);
  print_table(empresas, 5);
#elif pregunta == 5
#include "empresa.c"
  empresa* empresas = N_mejores_region(c, 30, 5, 13);
  print_table(empresas, 5);
#endif

  return 0;
}