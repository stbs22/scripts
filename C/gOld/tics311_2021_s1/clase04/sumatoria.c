#include <stdio.h>

int f(int x) {
  if (x == 0) {
    return x;
  }
  return x + f(x - 1);
}

int main(int argc, char* argv[]) {
  printf("%i\n", f(6));
  return 0;
}