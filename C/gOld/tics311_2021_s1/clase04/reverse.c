#include <math.h>
#include <stdio.h>

void f2(int n) {
  if (n == 0) {
    return;
  }
  printf("%d", n % 10);
  f2(n / 10);
}

int f(int x) {
  int resto = x % 10;
  int resultado = resto * pow(10, (int)log((double)x));
}

int main(int argc, char* argv[]) {
  // printf("%i\n", f(6543));
  int x = 6813543;
  int y = x;
  int resto;
  int resultado;
  int suma = 0;
  while (x > 0) {
    resto = x % 10;
    x = x / 10;
    suma *= 10;
    suma += resto;
  }
  printf("%i\n", suma);
  f2(y);
  printf("\n");
  return 0;
}