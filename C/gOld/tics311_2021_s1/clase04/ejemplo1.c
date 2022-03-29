#include <stdio.h>

void f(int x, int y) {
  if (x == y) {
    return;
  }
  printf("%d ", x);
  f(x + 1, y - 1);
}

int main(int argc, char* argv[]) {
  f(5, 11);
  return 0;
}