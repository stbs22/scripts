#include <stdio.h>

// Estructura de una cuenta
struct cuenta_banco {
  char nombre[20];
  char RUT[15];
};

// Programa principal. Sólo puede haber un main
int main(int argc, char **argv) {
  struct cuenta_banco cuentas[10];

  // pregunta e ingreso de datos utilizando scanf. Ojo que los arreglso de
  // caracteres no utilizan "&". Los arreglos comienzan con el índice en 0,
  // igual que python. Sólo por comodidad, se muestra en el mensaje de igreso de
  // datos el número de la cuenta que se está ingresando. Se le suma 1, pues
  // estamos usando el índice para mostrarlo.
  for (int i = 0; i < 10; i++) {
    printf("Ingrese nombre cuenta %i: ", i + 1);
    scanf("%s", cuentas[i].nombre);
    printf("Ingrese RUT cuenta %i: ", i + 1);
    scanf("%s", cuentas[i].RUT);
  }
  // Muestra por pantalla info
  for (int i = 0; i < 10; i++) {
    printf("%s\n%s\n--\n", cuentas[i].nombre, cuentas[i].RUT);
  }

  return 0;
}