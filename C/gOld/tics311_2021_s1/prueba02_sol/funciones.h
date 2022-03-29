#ifndef FUNCIONES_H__
#define FUNCIONES_H__

#define funcion 7

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct c {
  int id_region;
  char region[50];
  int id_comuna;
  char comuna[50];
  int casos;
  int poblacion;
  struct c* sgte;

} ciudad;

ciudad** read_hash(char* filename, int number);
void print_hash(ciudad** tabla, int number);

#endif