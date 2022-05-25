#ifndef _P1_UTILITIES_
#define _P1_UTILITIES_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define pregunta 5
#define w 10

typedef struct n {
  int id;
  char rut[11];
  char razon_social[200];
  char fecha_actuacion[11];
  char fecha_registro[11];
  char fecha_aprobacion[11];
  int anio;
  char mes[20];
  char comuna[80];
  int region;
  char codigo[40];
  char tipo[80];
  int capital;
  char comuna_social[80];
  int region_social;
} empresa;

void print_table(empresa *c, int N);
void print_empresa(empresa c);

#endif