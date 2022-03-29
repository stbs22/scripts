#include <stdio.h>

// Estructura de una cuenta
struct cuenta_banco {
  char nombre[20];
  char apellido[20];
  char RUT[15];
  char telefono[12];
  int edad;
};

// Programa principal. Sólo puede haber un main
int main(int argc, char **argv) {
  struct cuenta_banco cta1;

  // pregunta e ingreso de datos utilizando scanf. Ojo que los arreglso de
  // caracteres no utilizan "&"
  printf("Ingrese nombre: ");
  scanf("%s", cta1.nombre);
  printf("Ingrese apellido: ");
  scanf("%s", cta1.apellido);
  printf("Ingrese RUT: ");
  scanf("%s", cta1.RUT);
  printf("Ingrese telefono: ");
  scanf("%s", cta1.telefono);
  printf("Ingrese edad: ");
  scanf("%i", &cta1.edad);
  // Muestra por pantalla info
  printf("%s\n%s\n%s\n%s\n%i\n", cta1.nombre, cta1.apellido, cta1.RUT,
         cta1.telefono, cta1.edad);
  return 0;
}