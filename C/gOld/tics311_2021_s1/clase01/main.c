#include <stdio.h>
struct cuenta_banco {
  char *nombre;
  float saldo;
  long int cuenta;
  char *RUT;
};
int main(int argc, char **argv) {
  struct cuenta_banco cta1, cta2, cta3;
  cta1.nombre = "Bill Gates";
  cta1.saldo = 4200;
  cta1.cuenta = 1010101;
  cta1.RUT = "8.222.111-1";

  printf("%s\n", cta1.nombre);
  printf("%f\n", cta1.saldo);
  printf("%li\n", cta1.cuenta);
  printf("%s\n", cta1.RUT);

  cta2 = cta1;

  printf("%s\n", cta2.nombre);
  printf("%f\n", cta2.saldo);
  printf("%li\n", cta2.cuenta);
  printf("%s\n", cta2.RUT);
  return 0;
}