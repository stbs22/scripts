#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
  struct timeval start;
  struct timeval stop;
  double delta;
  int x = 0;

  gettimeofday(&start, NULL);
  for (int i = 0; i < atoi(argv[1]); i++) {
    for (int j = 0; j < atoi(argv[1]); j++) {
      x += 1;
    }
  }
  gettimeofday(&stop, NULL);
  delta =
      stop.tv_sec + stop.tv_usec * 1e-6 - (start.tv_sec + start.tv_usec * 1e-6);
  printf("%f\n", delta);
  return 0;
}