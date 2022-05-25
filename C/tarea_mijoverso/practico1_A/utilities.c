#include "utilities.h"

void print_table(empresa *c, int N) {
  printf("%8s|", "ID");
  printf("%*s|", w, "Rut");
  printf("%*s|", 60, "Razon S.");
  printf("%*s|", w, "Fecha Ac.");
  printf("%*s|", w, "Fecha R.");
  printf("%*s|", w, "Fecha Ap.");
  printf("%*s|", w, "Anio");
  printf("%*s|", w, "Mes");
  printf("%*s|", w, "Comuna T.");
  printf("%*s|", w, "Region T.");
  printf("%*s|", w, "Cod. S.");
  printf("%*s|", w, "Tipo Ac.");
  printf("%*s|", w, "Capital");
  printf("%*s|", w, "Comuna S.");
  printf("%*s|", w, "Region S.");
  printf("\n");
  printf("\n");
  for (int i = 0; i < N; i++) {
    print_empresa(c[i]);
  }
  printf("\n");
}

void print_empresa(empresa c) {
  printf("%8d|", c.id);
  printf("%*s|", w, c.rut);
  printf("%*s|", 60, c.razon_social);
  printf("%*s|", w, c.fecha_actuacion);
  printf("%*s|", w, c.fecha_registro);
  printf("%*s|", w, c.fecha_aprobacion);
  printf("%*d|", w, c.anio);
  printf("%*s|", w, c.mes);
  printf("%*s|", w, c.comuna);
  printf("%*d|", w, c.region);
  printf("%*s|", w, c.codigo);
  printf("%*s|", w, c.tipo);
  printf("%*d|", w, c.capital);
  printf("%*s|", w, c.comuna_social);
  printf("%*d|", w, c.region_social);
  printf("\n");
}